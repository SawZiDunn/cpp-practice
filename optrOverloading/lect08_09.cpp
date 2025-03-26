#include <iostream>
#include <iomanip>
#include <stdexcept>

// Begin class Array definition
class Array
{
    friend std::ostream &operator<<(std::ostream &, const Array &);
    friend std::istream &operator>>(std::istream &, Array &);

public:
    explicit Array(int = 10); // default constructor
    Array(const Array &);     // copy constructor
    ~Array();                 // destructor

    size_t getSize() const;                                                 // return size
    const Array &operator=(const Array &);                                  // assignment operator
    bool operator==(const Array &) const;                                   // equality operator
    bool operator!=(const Array &right) const { return !(*this == right); } // inequality operator

    int &operator[](int);      // subscript operator for non-const objects
    int operator[](int) const; // subscript operator for const objects

private:
    size_t size; // pointer-based array size
    int *ptr;    // pointer to first element of pointer-based array
};

// Begin Array implementation
Array::Array(int arraySize)
    : size{arraySize > 0 ? static_cast<size_t>(arraySize) : throw std::invalid_argument{"Array size must be greater than 0"}},
      ptr{new int[size]{}}
{
}

Array::Array(const Array &arrayToCopy)
    : size{arrayToCopy.size}, ptr{new int[size]}
{
    for (size_t i = 0; i < size; ++i)
    {
        ptr[i] = arrayToCopy.ptr[i];
    }
}

Array::~Array()
{
    delete[] ptr;
}

size_t Array::getSize() const
{
    return size;
}

const Array &Array::operator=(const Array &right)
{
    if (&right != this)
    {
        if (size != right.size)
        {
            delete[] ptr;
            size = right.size;
            ptr = new int[size];
        }
        for (size_t i = 0; i < size; ++i)
        {
            ptr[i] = right.ptr[i];
        }
    }
    return *this;
}

bool Array::operator==(const Array &right) const
{
    if (size != right.size)
    {
        return false;
    }
    for (size_t i = 0; i < size; ++i)
    {
        if (ptr[i] != right.ptr[i])
        {
            return false;
        }
    }
    return true;
}

int &Array::operator[](int subscript)
{
    if (subscript < 0 || subscript >= static_cast<int>(size))
    {
        throw std::out_of_range{"Subscript out of range"};
    }
    return ptr[subscript];
}

int Array::operator[](int subscript) const
{
    if (subscript < 0 || subscript >= static_cast<int>(size))
    {
        throw std::out_of_range{"Subscript out of range"};
    }
    return ptr[subscript];
}

std::istream &operator>>(std::istream &input, Array &a)
{
    for (size_t i = 0; i < a.size; ++i)
    {
        input >> a.ptr[i];
    }
    return input;
}

std::ostream &operator<<(std::ostream &output, const Array &a)
{
    for (size_t i = 0; i < a.size; ++i)
    {
        output << std::setw(12) << a.ptr[i];
        if ((i + 1) % 4 == 0)
        {
            output << std::endl;
        }
    }
    if (a.size % 4 != 0)
    {
        output << std::endl;
    }
    return output;
}

// Begin main function
int main()
{
    Array integers1{7}; // seven-element Array
    Array integers2;    // 10-element Array by default

    std::cout << "Size of Array integers1 is " << integers1.getSize()
              << "\nArray after initialization:\n"
              << integers1
              << "\nSize of Array integers2 is " << integers2.getSize()
              << "\nArray after initialization:\n"
              << integers2;

    std::cout << "\nEnter 17 integers:\n";
    std::cin >> integers1 >> integers2;

    std::cout << "\nAfter input, the Arrays contain:\n"
              << "integers1:\n"
              << integers1
              << "integers2:\n"
              << integers2;

    if (integers1 != integers2)
    {
        std::cout << "\nintegers1 and integers2 are not equal\n";
    }

    Array integers3{integers1}; // invokes copy constructor
    std::cout << "\nSize of Array integers3 is " << integers3.getSize()
              << "\nArray after initialization:\n"
              << integers3;

    integers1 = integers2; // assignment
    std::cout << "\nAfter assignment, integers1:\n"
              << integers1;

    if (integers1 == integers2)
    {
        std::cout << "\nintegers1 and integers2 are equal after assignment\n";
    }

    // Demonstrating subscript operator, exception handling, and more can be added here...

    return 0;
}
