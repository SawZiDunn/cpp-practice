#include <iostream>
#include <map>
#include <string>

int main()
{
    // Create a map where keys are strings and values are integers
    std::map<std::string, int> age;

    // Inserting data into the map
    age["Alice"] = 30;
    age["Bob"] = 25;
    age.insert(std::make_pair("Charlie", 45));

    // Accessing elements
    std::cout << "Alice's age: " << age["Alice"] << std::endl;

    // Iterate over the map
    for (const auto &pair : age)
    {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }

    // Find an element
    if (age.find("Bob") != age.end())
    {
        std::cout << "Bob is found, age: " << age["Bob"] << std::endl;
    }
    else
    {
        std::cout << "Bob is not found." << std::endl;
    }

    return 0;
}
