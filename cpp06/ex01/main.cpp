#include <iostream>
#include "Serializer.hpp" 
#include "Data.hpp"

int main (void)
{
    Data    myData;
    myData.id = 42;
    myData.name = "cpp06 ex01";
    myData.value = 42.2f;

    //print original pointer
    Data *originalPtr = &myData;
    std::cout << "Orifinal adress (Data*): " << originalPtr << std::endl;

    //serializer() -> convert pointer to uintptr_t
    uintptr_t rawData = Serializer::serialize(originalPtr);
    std::cout << "Serialized value (uintprt_t): " << rawData << std::endl;

    //desirializer() -> convert uintprt_t back to pointer
    Data *desirializedPtr = Serializer::deserialize(rawData);
    std::cout << "Desirialized adress (Data*): " << desirializedPtr << std::endl;

    //comparision
    if (originalPtr == desirializedPtr)
    {
        std::cout << "ID:    " << desirializedPtr->id << std::endl;
        std::cout << "Name:  " << desirializedPtr->name << std::endl;
        std::cout << "Value: " << desirializedPtr->value << std::endl;
    }
    else
        std::cout << "error: pointer not correpond" << std::endl;

    return (0);
}