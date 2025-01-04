# Header and Source Files for a Class

Separating a class interface into a header file in C++ is a standard practice for organizing code. It improves readability, reusability, and maintainability. Here's a step-by-step guide:

1. Structure of the Header and Source Files
   Header File (ClassName.h): Contains the class declaration (interface).
   Source File (ClassName.cpp): Contains the class definition (implementation).
2. Example: Separation of Class Interface

### Header File: Example.h

```cpp
#ifndef EXAMPLE_H  // Include guard to prevent multiple inclusions
#define EXAMPLE_H

#include <string>  // Include necessary headers

class Example {
private:
    int data;
    std::string name;

public:
    // Constructor
    Example(int data, const std::string& name);

    // Getter for data
    int getData() const;

    // Setter for data
    void setData(int data);

    // Display information
    void display() const;
};

#endif  // EXAMPLE_H

```

### Source File: Example.cpp

```cpp
#include "Example.h"  // Include the header file
#include <iostream>   // For input/output

// Constructor
Example::Example(int data, const std::string& name) : data(data), name(name) {}

// Getter for data
int Example::getData() const {
    return data;
}

// Setter for data
void Example::setData(int data) {
    this->data = data;
}

// Display information
void Example::display() const {
    std::cout << "Data: " << data << ", Name: " << name << std::endl;
}


```

### Main File: main.cpp

```cpp

#include <iostream>
#include "Example.h"  // Include the header file

int main() {
    Example obj(42, "Sample");
    obj.display();

    obj.setData(100);
    obj.display();

    return 0;
}
```

### Key Points

#### Include Guards:

Use #ifndef, #define, and #endif in the header file to avoid multiple inclusions.
Alternatively, in modern C++ (C++20), you can use #pragma once.

#### Separation of Concerns:

The header file focuses on what the class provides (its interface).
The source file implements how the class behaves.

#### Compilation:

Compile both Example.cpp and main.cpp together:

```bash
g++ Example.cpp main.cpp -o program
```

#### Minimized Dependencies:

Include only necessary headers in the header file.
Add additional headers in the source file if needed.
This organization keeps your project modular, simplifies debugging, and adheres to best practices.

# Declaring Objects

Objects can be declared in different ways:

## Automatic (Local) Objects

Declared inside a function; their lifetime is tied to the function scope.

```cpp
class Example {
public:
    Example() { std::cout << "Constructor Called" << std::endl; }
};


void func() {
    Example obj; // Constructor called
} // Destructor called here

```

## Dynamic Objects

Created on the heap using new; requires explicit deletion.

```c++
Example\* obj = new Example(); // Constructor called
delete obj; // Destructor called

```

## Static Objects

Exist for the program's lifetime.

```c++

void func() {
static Example obj; // Constructor called only once
}

```

## Array of Objects

```c++
Example arr[3]; // Calls default constructor for each element
```

## Object Pointers

```c++
Example obj;
Example\* ptr = &obj; // Pointer to an object
```
