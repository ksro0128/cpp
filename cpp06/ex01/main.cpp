#include <iostream>
#include "Serializer.hpp"

struct Data 
{
    int value;
};

int main(void) 
{
    Data myData;
    myData.value = 42;

    uintptr_t serializedValue = Serializer::serialize(&myData);
    Data* deserializedData = Serializer::deserialize(serializedValue);
    if (deserializedData == &myData)
        std::cout << "Serialization and deserialization successful!" << std::endl;
    else
        std::cout << "Serialization and deserialization failed!" << std::endl;
}
