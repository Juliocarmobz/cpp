#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->_vec = other._vec;
        this->_deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parseInput(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        // Verifica se a string contém apenas dígitos
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!std::isdigit(arg[j])) {
                return false;
            }
        }

        long val = std::atol(arg.c_str());
        if (val < 0 || val > 2147483647) {
            return false;
        }

        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }
    return true;
}

void PmergeMe::sortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] > arr[i+1])
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        else
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
    }

    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = hasStraggler ? arr.back() : -1;

    // Ordena os pares pelo maior elemento
    for (size_t i = 1; i < pairs.size(); ++i) {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        while (j >= 0 && pairs[j].first > key.first) {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = key;
    }

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
    }

    // Insere os elementos pendentes (menores) na mainChain via busca binária
    if (!pairs.empty()) {
        mainChain.insert(mainChain.begin(), pairs[0].second);
    }

    for (size_t i = 1; i < pairs.size(); ++i) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].second);
        mainChain.insert(it, pairs[i].second);
    }

    if (hasStraggler) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    arr = mainChain;
}

void PmergeMe::sortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] > arr[i+1])
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        else
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
    }

    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = hasStraggler ? arr.back() : -1;

    for (size_t i = 1; i < pairs.size(); ++i) {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        while (j >= 0 && pairs[j].first > key.first) {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = key;
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
    }

    if (!pairs.empty()) {
        mainChain.insert(mainChain.begin(), pairs[0].second);
    }

    for (size_t i = 1; i < pairs.size(); ++i) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].second);
        mainChain.insert(it, pairs[i].second);
    }

    if (hasStraggler) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    arr = mainChain;
}

void PmergeMe::printSequence(const std::string& prefix, const std::vector<int>& seq) const {
    std::cout << prefix;
    size_t limit = seq.size() > 5 ? 5 : seq.size();
    for (size_t i = 0; i < limit; ++i) {
        std::cout << seq[i] << " ";
    }
    if (seq.size() > 5) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

void PmergeMe::execute() {
    printSequence("Before: ", _vec);

    // Benchmarking Vector
    struct timeval start, end;
    gettimeofday(&start, NULL);
    sortVector(_vec);
    gettimeofday(&end, NULL);
    double timeVec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    // Benchmarking Deque
    gettimeofday(&start, NULL);
    sortDeque(_deq);
    gettimeofday(&end, NULL);
    double timeDeq = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    printSequence("After:  ", _vec);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}