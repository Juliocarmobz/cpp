#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


/*
    pegar a linha toda, procurar a s1
    enquanto 


*/
static void string_replace(std::string *line, const char* s1, const char* s2)
{
    if (s1 != '\0')
        return ;
    std::string     rest_line;
    size_t pos = line->find(s1);
    while (pos != string::npos)
    {
        
    }

    return ;
}


int main(int ac, char **av)
{
    if (ac != 4 || av[2] != '\0')
    {
        std::cout << "Wrong input, please insert <./sedisforlosers> <filename> <string1> <string2>" << std::endl;
        exit(1);
    }

    std::string          line;
    std::ifstream        myfile (av[1]);
    std::string          new_file_name = av[1];
    std::ofstream        new_file;

    new_file_name += ".replace";
    const char *temp_file_name = new_file_name.c_str();
    if (myfile.is_open())
    {
        new_file.open ( temp_file_name );
        while (std::getline (myfile, line) )
        {
            string_replace(&line, av[2], av[3]); //modificar line para substituir s1 por s2
            new_file << line << std::endl;
        }
        myfile.close();
        new_file.close();
    }
    else std::cout << "Unable to open file" << std::endl;
    return (0);
}

// 1 pegar o nome do arquivo, fazer verificacoes nele (ver se existe ou se esta vazio) myfile.open(filename)
// 2 criar um novo arquivo, pegar uma string argv 1 <filename.replace>
// s1 != '\0'
// 3 ter todo o arquivo e verificar a ocorrencia de s1, quando achar trocar por s2, ver se a string que vai ser substituida nao necessariamente tera o mesmo tamanho
