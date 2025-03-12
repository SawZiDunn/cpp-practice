#include <iostream>
#include <string>

class MyString
{
private:
    std::string data;

public:
    // Constructors
    MyString(const char *str = "") : data(str) {}
    MyString(const std::string &str) : data(str) {}

    // Overloaded equality and relational operators
    bool operator==(const MyString &other) const
    {
        return data == other.data;
    }

    bool operator!=(const MyString &other) const
    {
        return !(*this == other); // equility operator is already overload at this point
    }

    // String concatenation operators
    MyString &operator+=(const MyString &other)
    {
        data += other.data;
        return *this;
    }

    MyString operator+(const MyString &other) const
    {
        return MyString(data + other.data);
    }

    // Subscript operator
    char &operator[](size_t index)
    {
        if (index >= data.length())
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const char &operator[](size_t index) const
    {
        if (index >= data.length())
        {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Assignment operator
    MyString &operator=(const MyString &other)
    {
        if (this != &other)
        {
            data = other.data;
        }
        return *this;
    }

    // Member functions
    bool empty() const
    {
        return data.empty();
    }

    MyString substr(size_t pos, size_t len = std::string::npos) const
    {
        try
        {
            return MyString(data.substr(pos, len));
        }
        catch (const std::out_of_range &)
        {
            throw std::out_of_range("Invalid substring parameters");
        }
    }

    // Friend operator for output streaming
    friend std::ostream &operator<<(std::ostream &os, const MyString &str)
    {
        os << str.data;
        return os;
    }
};

int main()
{
    MyString s1("happy");
    MyString s2("birthday");
    MyString s3; // empty string

    // Test overloaded equality and relational operators
    std::cout << "Testing equality operators:\n";
    std::cout << std::boolalpha;
    std::cout << "(s2 == s1): " << (s2 == s1) << '\n';
    std::cout << "(s2 != s1): " << (s2 != s1) << '\n';

    // Test string empty function
    std::cout << "\nTesting s3.empty(): " << s3.empty() << '\n';
    if (s3.empty())
    {
        std::cout << "s3 is empty; assigning s1 to s3\n";
    }

    // Assignment
    s3 = s1;
    std::cout << "s3 = " << s3 << '\n';

    // Test overloaded string concatenation assignment operator
    std::cout << "\nTesting string concatenation:\n";
    s1 += s2;
    std::cout << "s1 = " << s1 << '\n';

    // Test string concatenation with a C string
    std::cout << "s1 + \" is my\" yields: ";
    std::cout << s1 + " is my" << '\n';

    // Test substring
    std::cout << "\nTesting substring:\n";
    std::cout << "The substring of s1 starting at location 0 for 4: ";
    std::cout << s1.substr(0, 4) << '\n';

    // Test substring with "end-of-string" option
    std::cout << "The substring of s1 starting at location 15: ";
    std::cout << s1.substr(15) << '\n';

    // Test copy assignment
    MyString s4(s1);
    std::cout << "\nTesting copy assignment:\n";
    std::cout << "s4 = " << s4 << '\n';

    // Test subscript operator
    try
    {
        std::cout << "\nTesting subscript operator:\n";
        s1[0] = 'H';
        std::cout << "s1 after s1[0] = 'H': " << s1 << '\n';

        // Test subscript out of range
        std::cout << "\nTesting subscript out of range:\n";
        char c = s1[100]; // Should throw exception
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "An exception occurred: " << e.what() << '\n';
    }

    return 0;
}
