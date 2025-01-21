## Object-Oriented Programming

### Objects

-   attributes = characteristics of an object
-   an attribute describes the current states
-   a well-defined object - it has its own identity, attributes, and behavior.

### Classes

-   Each class has a name and describes attributes and behavior (methods).
-   Classes are blueprints of objects
-   attributes are also referred to as properties or data.
-   Process of creating object = instantiation

### Access specifiers

-   public
-   private: default specifier
-   protected

### Abstraction

-   abstraction is the concept of providing only essential information to the outside world
-   allows us to write a single bank account class, and then create different objects based on the class, for individual bank accounts, rather than creating a separate class for each bank account.
-   foundation for encapsulation and polymorphism

### Encapsulation

-   data hiding
-   restricting access to the inner workings of that class

### Constructors

-   called when the class is created

```cpp
class myClass {
  public:
    myClass(string nm) {
      setName(nm);
    }
    void setName(string x) {
      name = x;
    }
    string getName() {
      return name;
    }
  private:
    string name;
};

int main() {
  myClass ob1("David");
  myClass ob2("Amy");
  cout << ob1.getName();
}
```

### Headers Source

-   Header: declare variables and functions
-   Source: implementation
-   #include headers

### Constructors and Destructors

-   Constructor: run when the object is created
-   Destructor: when deleted
    -   cannot have the parameters
    -   cannot overload
    -   called when object is deleted

```
class MyClass
{
  public:
    // constructor
   MyClass();
    // destructor
   ~MyClass();
};;
```

### ifndef

```
#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass
{
  public:
  MyClass();
  protected:
  private:
};

#endif // MYCLASS_H
```

ifndef stands for "if not defined". The first pair of statements tells the program to define the MyClass header file if it has not been defined already.

endif ends the condition.

### Pointers and Classes

```
#include <iostream>
using namespace std;

class MyClass
{
    public:
        MyClass();
        void myPrint();
};

MyClass::MyClass() {
}
void MyClass::myPrint() {
    cout <<"Hello"<<endl;
}

int main() {
    MyClass obj;
    MyClass *ptr = &obj;
    ptr->myPrint();
}
```

pointer **ptr** assign (point) to the address of **obj**.

ptr->myPrint() means **myPrint() function** of pointer ptr.

### Const

-   const variables can be initialized in the constructor

### friend

-   The friend function of a class is the function that can have access to private and protected the class.

```
#include <iostream>
using namespace std;

class Point {
    public:
        Point(int a, int b): x(a), y(b) {};
        void print() {
            cout << x << ", " << y;
        }
    private:
        int x;
        int y;

    friend void shift(Point &p, int step);
};

void shift(Point &p, int step) {
    p.x += step;
    p.y += step;
}

int main() {
    int x, y;
    cin>>x>>y;
    Point p(x, y);

    int step;
    cin>>step;
    shift(p, step);

    p.print();
}
```

### Class Interface

Separating a class interface into a header file in C++ is a standard practice for organizing code. It improves readability, reusability, and maintainability. Here's a step-by-step guide:

Header File (ClassName.h): Contains the class declaration (interface).
Source File (ClassName.cpp): Contains the class definition (implementation).

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

### abstract class

-   override can only use to virtual functions
-   pure virtual function basically defines, that the derived classes will have that function defined on their own.
-   abstract class is a class with pure virtual function.
-   abstract class serves as a blueprint for other classes and may contain one or more abstract methods.
-   cannot be initialised itself.

### template

allows generic coding

```
#include <iostream>
using namespace std;

template <class T, class U>
T smaller(T a, U b) {
  if (a > b) {
    return b;
  } else {
    return a;
  }
}
```

```
template <class T>
class Pair {
 private:
  T first, second;
 public:
  Pair (T a, T b):
   first(a), second(b){
  }
  T bigger();
};

template <class T>
T Pair<T>::bigger() {
  return (first>second ? first : second);
}
```

```
#include <iostream>
using namespace std;

//change the class to a template
template <class T>
class Queue
{
	private:
	T *arr;
    int count;
    public:
    	Queue(int size) {
    	    arr = new T[size];
    	    count = 0;
    	}
    	void add(T elem) {
    	    arr[count] = elem;
    	    count++;
    	}
    	void get(int index) {
    	    cout << arr[index]<<endl;
    	}
};

int main()
{
	Queue<string> q(4);
	q.add("James");
	q.add("Andy");
	q.add("Amy");
	q.get(2);

	Queue <int> n(2);
	n.add(42);
	n.add(33);
	n.get(1);

	return 0;
}
```

tempate specialization

```
#include <iostream>
using namespace std;

template <class T>
class Div {
    public:
        Div (T x, T y) {
            cout <<x / y<<endl;
        }
};

//your code goes here
template <>
class Div <string> {
   public:
        Div (string x, string y) {
            cout << x.size() / y.size() << endl;
        }
};


int main () {
    string a, b;
    cin >> a >> b;
    int x, y;
    cin >> x >> y;

    Div <string> d2(a, b);
    Div <int> d1(x, y);

}
```

### Exception

```
int motherAge = 29;
int sonAge = 36;
if (sonAge > motherAge) {
  throw "Wrong age values";
}
```

```
#include <iostream>
using namespace std;

int main() {
   string name;
   cin >> name;
   int length = name.size();
   try {
      if (length < 4 || length > 20) {
         throw length;
      }
      cout << "Valid";

   }
   catch(int length) {
      cout << "Invalid";
   }

   return 0;
}
```
