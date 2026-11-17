#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    if (!loadDatabase("data.csv")) {
        std::cerr << "Error: could not open database file (data.csv)." << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) return false;

    std::string line;
    std::getline(file, line); // Pula o cabeçalho (date,exchange_rate)
    
    while (std::getline(file, line)) {
        size_t comma = line.find(',');
        if (comma != std::string::npos) {
            std::string date = line.substr(0, comma);
            std::string rateStr = line.substr(comma + 1);
            float rate = std::atof(rateStr.c_str());
            _database[date] = rate;
        }
    }
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    // Verificação simples de dias de cada mês
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (isLeap ? 29 : 28)) return false;
    }
    return true;
}

void BitcoinExchange::processInput(const std::string& filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Pula o cabeçalho do input
    
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        size_t pipe = line.find(" | ");
        if (pipe == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipe);
        std::string valueStr = line.substr(pipe + 3);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value;
        std::istringstream iss(valueStr);
        if (!(iss >> value)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        // Encontra o elemento logo acima da data alvo (já que iteradores não têm iteração reversa garantida de find)
        std::map<std::string, float>::const_iterator it = _database.upper_bound(date);
        
        if (it == _database.begin()) {
            std::cerr << "Error: date too early => " << date << std::endl;
            continue;
        }
        
        // Retorna um passo atrás para pegar a data exata ou a data anterior mais próxima
        --it;
        float rate = it->second;
        
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
}