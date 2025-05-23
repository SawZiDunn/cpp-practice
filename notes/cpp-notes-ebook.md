Lecture notes on the book "C++ How to Program, 10th Edition by Paul Deitel and Harvey Deitel".

Lecturer: Phairoj Jatanachai, B.Eng (Computer Engineering), M.B.A.

## Table of Content

-   [Table of Content](#table-of-content)
-   [Lecture 1 Introduction](#lecture-1-introduction)
    -   [Why C++](#why-c)
    -   [OOP](#oop)
-   [Lecture 2 Cpp Structure](#lecture-2-cpp-structure)
    -   [Programming Paradigms](#programming-paradigms)
    -   [Working with objects](#working-with-objects)
    -   [auto](#auto)
    -   [Data types](#data-types)
    -   [Type Casting](#type-casting)
    -   [For Looping](#for-looping)
-   [Lecture 3 Intro to Class](#lecture-3-intro-to-class)
    -   [Lecture 4 Containers](#lecture-4-containers)
    -   [Lecture 5 Classes](#lecture-5-classes)
-   [Lecture 6 Functions and Control](#lecture-6-functions-and-control)
    -   [Functions](#functions)
    -   [Generic Function](#generic-function)
    -   [Recursion with Pointers](#recursion-with-pointers)
-   [Lecture 7 Pointers](#lecture-7-pointers)
-   [Lecture 7](#lecture-7)
-   [Lecture 8](#lecture-8)
-   [Lecture 9](#lecture-9)
-   [Lecture 10](#lecture-10)
-   [Lecture 11](#lecture-11)
-   [Lecture 12](#lecture-12)

## Lecture 1 Introduction

### Why C++

-   Performance
-   Control over system resources / low-level operations
-   Object Oriented Programming

How to run

-   Compile
-   Execute
-   Cpp file -> object file -> executable file

```
$ g++ -o -std=c++14 a.out a.cpp
$ ./a.out
```

### OOP

-   Object: an instance of a class
-   Benefit

    -   Re-usability
    -   More natural way

-   Class: Description of Object OR Blueprint for creating objects

    -   Attributes => fields (variables) and methods

-   Principles of OOP

    -   Abstraction: Hiding complex reality by **_modeling classes appropriate to the problem_**.
    -   Encapsulation: **_Bundling the data and the methods that operate on the data_** into a single unit or class.
    -   Inheritance: Mechanism where **_one class acquires the properties (methods and fields) of another_**.
    -   Polymorphism: Ability of different classes to be **_treated as instances of the same class through inheritance_**.
        -   Overriding existing methods of existing classes.
        -   To allow a single function or method to work in different ways depending on the object it is called on.)

-   Encapsulation and Polymorphism example

    ```
      Circle c1; Rectangle r1;
      cout << c1.Area() << endl;
      cout << r1.Area() << endl;
    ```

-   Why OOP ?

    -   Limitation of procedural languages
        -   Division into functions: grouping number of functions => large programs
        -   Complex: Large programs become complex and difficult to debug
        -   Data undervalued: Data is not secure because any function can access the global variable and change its values.
    -   Reusable and easy to modify existing codes => No big programs
    -   Single unit (objects) & functions inside the class (methods) - call the method in the object to use => No complex
    -   Cannot access the data directly, only from reading data item in an object and return its value (encapsulation) => Data is secure.

    ```
    #include <iostream>
    using namespace std;

    // this is a comment
    /* this is multiline
      comment */

    int main() {
      cout << "Hello world" << endl;
      return 0;
    }
    ```

    ### Two types of Errors

    Syntax Error

    -   aka Compile-time error
    -   violating the C++ lang rules
    -   fixing the syntax (from top to bottom)

    Logic Error

    -   aka Run-time error
    -   Program don't do what suppose to do

    Overflow Error

    -   aka Round-off error
    -   Computation result is outside of numeric range

    ### Fixing Errors

    -   Testing: Validating program correctness
    -   Debugging: Finding error source

    ### cout and cin

    ```
    #include <iostream>
    using namespace std;

    int main() {
      string name; int age;
      cout << "Enter your name: "; getline(cin, name);
      cout << "Enter your age: "; cin >> age;
      cout << name << " is " << age << " years old." << endl;

      cin.ignore();

      string father_name;
      cout << "What is your father's name: "; getline(cin, father_name);
      cout << "Your father is " << father_name;
      return 0;
    }
    ```

    ```
    #include <iostream>
    #include <string>
    using namespace std;

    int main() {
      string name; int age;
      cout << "Enter your name: "; cin >> name;
      cout << "Enter your age: "; cin >> age;
      cout << name << " is " << age << " years old." << endl;

      // framing * around name
      const string greeting = "Hello " + name + "!";
      const string spaces(greeting.size(), ' ');

      const string second = "* " + spaces + " *";
      const string first(second.size(), '*');

      cout << first << endl;
      cout << second << endl;
      cout << "* " << greeting << " *" << endl;
      cout << second << endl;
      cout << first << endl;

      return 0;
    }
    ```

-   string: #include\<string\>
    // it will create 5 blank spaces by default
-   setw(5): #include\<iomanip\>
    // after this all will fill that \* character
-   setfill('\*')
    // setprecision(n): precision of n number
-   scientific: will show in scientific format

```
  cout << setw(5) << 123 << setw(10) << 456 << endl;
  cout << setfill('*');
  cout << setw(5) << 123 << setw(10) << 456 << endl;
  double num = 3.14192436;
  cout << setprecision(1) << num << endl;
  // will take 3 digit
  cout << setprecision(3) << num << endl;
  cout << scientific << num << endl;
  // precision is 10: other values become zeros
  cout << setprecision(10) << fixed << num << endl;
```

Output is ...

```
%./no1
      123       456
    **123*******456
    3
    3.14
    3.142e+00
    3.1419243600
```

-   hex
-   oct
-   showbase
-   noshowbase
-   showpos
-   noshowpos
-   showpoint
-   noshowpoint
-   boolalpha
-   noboolalpha
-   uppercase

## Lecture 2 Cpp Structure

### Programming Paradigms

-   Imperative
    -   Structured/Procedural
    -   Object-oriented: Programs are composed of **Interrelated** objects
-   Declarative
    -   Functional
    -   Logic

### Working with objects

-   Strings: mutable types (name[0] = 'H' is valid.)
-   Block or scope of variable { }
-   Some objects can be used as variables.
    ```
    complex<double> a = 2; complex<double>=3i;
    a += b; // a is 2+3i
    ```

### auto

-   auto: allows the compiler to automatically deduce the type of a variable from its initializer (like eval in Python?)

```
  int a[5] = {1, 2, 3, 4, 5};
  // auto will auto deduce each element of a is int
  // equivalent to for (int i: a) ...
  for (auto i: a) {
      cout << i << endl;
  };
```

### Data types

-   Built-in / Primitive / Intrinsic types
-   9 types: char, short, int, long, bool, float, double, long long, long double
-   int8_t: 8 bit integer

### Type Casting

```
  double x = 1.2;
  int y = x;
  cout << x << "'s integer is " << y << endl;
  //   double z = y; // error

  double xx = 2.24;
  int yy = (int) xx;
  float zz = (float) (xx/yy);
  cout << xx << "'s integer is " << yy << " and divided value is " << zz << endl;
```

Output is ...

```
  1.2's integer is 1
  2.24's integer is 2 and divided value is 1.12
```

-   static_cast\<new type\> ( expression ) (e.g static_cast<int> (3/2))
    -   Identifies a cast at compile time
-   dynamic_cast
    -   Casting at runtime.
    -   Only works on reference and pointers
-   const_cast
    -   cannot change their values
    -   const_cast let the programmer to add or remove const keyword to ref or pointers
        (normally they cannot const)
-   reinterpret_cast
    -   Takes the bits in the expression and reuse them UNCONVERTED as a new type
    -   Only works on reference and pointers

### For Looping

```
  for (int i=0; i<5; i++) {
  }
  // looping a container or sequence
  // auto keyword can also be used
  for (int i: v1) {
  }
```

## Lecture 3 Intro to Class

-   Computer Organization

    -   Input Unit
    -   Output Unit
    -   Memory Unit
    -   ALU
    -   CPU
    -   Secondary storage unit

-   Programming languages

    -   Machine languages
    -   Assembly
    -   High-level
    -   Interpret and Compile languages

-   OOP
    -   Functions, member functions (methods in class)
    -   Class
    -   Attributes and data members (private, protected, public)
        -   Private: Only within class the attributes declared
        -   Protected: Only within and its child class
        -   Public: Can access from any part of program

C++ Dev Environment Phases 1. Editor: e.g. VSCode 2. Preprocessor: process the code 3. Loader: load the program in memory 4. CPU: each instruction executed and storing new data from the program

-   Order of precedence (all left to right except =)
    -   () \* / % + - << >> < <= > >= == != =

Constructors

-   Special type of function in a class that is automatically called when an object of
    that class is created.
-   Purpose:
    -   To initialize the object's properties
    -   Setting up initial states or Performing any setup steps necessary
-   Implicit vs Explicit
    -   Implicit: default constructor
    -   Explicit: prevent implicit conversions for classes for safety
    -

```
class ExplicitExample {
public:
    explicit ExplicitExample(int value);
};

int main() {
    // without explicit, both ways are valid to initialize

    // Copy initialization
    ExplicitExample obj1 = 42; // Error: Cannot implicitly convert int to ExplicitExample

    // Direct initialization
    ExplicitExample obj2(42);  // OK: Explicit conversion
    return 0;
}
```

### Lecture 4 Containers

Array vs Vector: https://hsf-training.github.io/hsf-training-cpp-webpage/03-arrays-and-vectors/index.html

Vectors and Lists operations: https://coding-champ.com/tutorials/c-plus-plus/lists-and-vectors

```
#include<iostream>
#include<vector>
#include<list>
using namespace std;

template <typename T1>
vector<T1> delete_neg_vector(vector<T1> vec) {
    for(int i=0; i < vec.size(); i++) {
        if (vec[i] < 0) {
            vec.erase(vec.begin()+i);
        } else {
            continue;
        }
    }
    return vec;
}

template <typename T1>
void delete_neg_vector_ref(vector<T1> &vec) {
    for(int i=0; i < vec.size(); i++) {
        if (vec[i] < 0) {
            vec.erase(vec.begin()+i);
        } else {
            continue;
        }
    }
}

template <typename T2>
list<T2> delete_neg_list(list<T2> ls) {
    for(auto i=ls.begin(); i!=ls.end();) {
        if (*i < 0) {
            i = ls.erase(i);
        } else {
            i++;
        }
    }
    return ls;
}

template <typename T3>
void print_collection(T3 container) {
    for (auto i: container) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v1 = {1, -2, 3, 2, 4, 5};
    vector<int> pos_vec = delete_neg_vector(v1);
    cout << "Original vector: ";
    print_collection(v1);
    cout << "Positive vector: ";
    print_collection(pos_vec);
    cout << "After pass by reference:";
    delete_neg_vector_ref(v1);
    print_collection(v1);

    list<int> l1 = {1, -2, 3, 2, 4, 5};
    list<int> pos_ls = delete_neg_list(l1);
    cout << "Original list: ";
    print_collection(l1);
    cout << "Positive list: ";
    print_collection(pos_ls);
    return 0;
}
```

Output

```
Original vector: 1 -2 3 2 4 5
Positive vector: 1 3 2 4 5
After pass by reference:1 3 2 4 5
Original list: 1 -2 3 2 4 5
Positive list: 1 3 2 4 5
```

```
#include<iostream>
#include<vector>
using namespace std;

struct Employee {
    string name;
    int age;
    double salary;
};

struct Dept {
    string name;
    vector<Employee> employee_ls;
    float kpi;
};

struct Company {
    string name;
    vector<Dept> department_ls;
    float stock_price;
};

int main() {
    Employee p1 = {
            "Mr. Thomson",
            21,
            200.21
    };

    vector<Employee> emp_ls_IT = {
        p1,
        {
            "Miss James",
            79,
            2003.21
        }
    };

    Dept IT = {
        "IT",
        emp_ls_IT,
        21.3
    };

    vector<Dept> department_ls = {
        IT,
        {
            "Finance",
            emp_ls_IT,
            21.3
        }
    };

    cout << department_ls[1].name << endl;
    return 0;

}
```

### Lecture 5 Classes

```
// implicit constructor by default
class Account1 {
    private:
        string name;
    public:
        // created automatically by compiler
        // - whether inside the code or not
        // Account1() {

        // }

        void setName(string accountName) {
            name = accountName;
        }
        // should put const to show compiler error in case the value in name is changed.
        string getName() const {
            return name;
        }
};

// w/ explicit constructor
class Account2 {
    private:
        string name;
    public:
        // constructors = function same name with the class
        // explicitly defined constructor
        explicit Account2(string accountName) : name(accountName) {

        }
    void setName(string accountName) {
        name = accountName;
    }
    // should put const to show compiler error in case the value in name is changed.
    string getName() const {
        return name;
    }
};

// w/ data validation
class Account3 {
    private:
        string name; int balance;
    public:
        // constructors = function same name with the class
        // explicitly defined constructor
        explicit Account3(string accountName, int initialBalance) : name(accountName) {
            // setting default to zero if less than 0
            if (initialBalance > 0) {
                balance = initialBalance;
            }
        }
        void setName(string accountName) {
            name = accountName;
        }
        // should put const to show compiler error in case the value in name is changed.
        string getName() const {
            return name;
        }

        void setBalance(int initialBalance) {
            balance = initialBalance;
        }
        // should NOT put const to show compiler error in case the value in name is changed.
        int getBalance() {
            return balance;
        }
};
```

```
Account1 myAccount;

    myAccount.setName("John");
    cout << myAccount.getName() << endl;

    // cout << "Enter your name: ";
    // string theName;
    // getline(cin, theName);
    // cout << "The name is " << theName << endl;

    // myAccount.setName(theName);
    // cout << "The name to myAccount object is " << myAccount.getName() << endl;

    // ----------------- w/ explicit constructor

    Account2 myAccount2("Alex");
    // reset the name in myAccount2
    // myAccount2.setName("Athena");
    cout << myAccount2.getName() << endl;

    // ----------------- w/ data validation

    Account3 myAccount3("Alex", 100);
    cout << myAccount3.getName() << endl;
    cout << myAccount3.getBalance() << endl;

    Account3 myAccount4("Alex", -1);
    cout << myAccount4.getName() << endl;
    cout << myAccount4.getBalance() << endl;
```

## Lecture 6 Functions and Control

### Functions

```
    int arr[3] = {10, 20, 30};
    cout << *arr << endl;
    // pointer shifted by one position
    cout << *(arr+1) << endl;

    // invalid using ++ for shifting
    // cout << *arr++ << endl;

    // cannot use for CONTAINTER classes like vector, array, list
    // vector<int> vec = {10, 20, 30};
    // array<int, 3> arr2 = {10, 20, 30};
    // cout << *arr2 << endl;

    // Output
    // 10
    // 20
```

### Generic Function

-   template \<typename T>

```
    template <typename T>
    void swap4(T& a, T& b) {
        T temp;
        temp = a;
        a = b;
        b = temp;
    }
  // pass by reference with Generic
    int n7 = 10; int n8 = 20;
    cout << n7 << '\t' << n8 << endl;
    swap4(n7, n8);
    cout << n7 << '\t' << n8 << endl;
```

### Recursion with Pointers

```
    void printArray(int *ptr, size_t size) {
        if (size == 0) {
            cout << endl;
            return;
        }
        cout << *ptr << " ";
        // pointer is shifted to one position
        printArray(ptr+1, size-1);
    }

    void reverseArray(int *ptr, size_t size) {
        if (size == 0) {
            return;
        }
        reverseArray(ptr+1, size-1);
        cout << *ptr << " ";
    }

    void reverseVector(vector<int> vec, int size) {
        if (size == 0) {
            cout << vec[0] << endl;
            return;
        }
        cout << vec[size] << " ";
        reverseVector(vec, size-1);
    }

    int maxFinder(int *ptr, size_t size) {
        if (size == 1) {
            return ptr[0];
        }
        int max = maxFinder(ptr+1, size-1);
        return (ptr[0] > max) ? ptr[0] : max;
    }
```

## Lecture 7 Pointers

-   Pass by value: new variable, arguments are copied when used in function
-   Pass by reference:
    -   & is used, Not copied
    -   compiler point the function that references the memory allocation (address) of the original variable
    -   original value changes when reference variable changes (should consider using const if you don't want to update)
-   Pass by pointers:
    -   \* is used and also known as dereferencing. It accepts the value of the original variable.
    -   it has own memory allocation

| Feature                   | Pass by Reference                                                       | Pass by Pointer                                                                    |
| ------------------------- | ----------------------------------------------------------------------- | ---------------------------------------------------------------------------------- |
| Syntax                    | `void functionName(Type &param)`                                        | `void functionName(Type *param)`                                                   |
| Modification of Value     | Changes to the parameter inside the function affect the original value. | Changes to the dereferenced pointer inside the function affect the original value. |
| Nullability               | Not applicable. References must always be bound to valid objects.       | Pointers can be assigned a `nullptr` or checked for null before dereferencing.     |
| Initialization            | Must be initialized upon declaration.                                   | Can be declared first and then initialized later.                                  |
| Syntax for Calling        | `functionName(variable)`                                                | `functionName(&variable)`                                                          |
| Memory Overhead           | Generally lower as no extra memory is needed for a reference.           | Requires additional memory to store the memory address.                            |
| Reference vs. Dereference | Direct use of the variable.                                             | Requires dereferencing (`*pointer`) before using the value.                        |
| Pointer Arithmetic        | Not applicable. References do not support pointer arithmetic.           | Allows for pointer arithmetic.                                                     |
| Ease of Use               | Easier syntax, often preferred for clarity.                             | Requires explicit dereferencing, which can be error-prone.                         |
| Pointer Ownership         | No ownership semantics.                                                 | Ownership can be transferred or managed explicitly.                                |
| Use in Arrays             | Cannot be used to iterate through an array.                             | Can be used with pointer arithmetic to iterate through an array.                   |

```
// pass by value: original value is copied
// original variables not swap
void swap1(int n1, int n2) {
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

// pass by reference: original value is pointed
// original variables swap
void swap2(int &n1, int &n2) {
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

// pass by pointer: address of the original variable is given
// original variables swap
void swap3(int *n1, int *n2) {
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
```

## Lecture 7

-   random numbers

```
#include <cstdlib>
#include <ctime>

unsigned int random_seed = static_cast<unsigned int>(time(nullptr));
srand(random_seed);

int random_generator(int min, int max) {
    return min + rand() % (max - min + 1);
}
```

-   static array does not reinitialize in second call - compile time
-   dynamic array reinitialize in second call - runtime

```
static array<int, 3> arr1; // static
array<int, 3> arr2; // dynamic
```

-   Using & (reference) in the iterator objects makes the original value changes

```
for (int& i: arr1) {
    i++;
}
```

## Lecture 8

Pointer = variable holds address of another variable

```
int x = 5;
int* y = &x;
// address
cout << y << endl;
// value
cout << *y << endl;
// pointer y updates means &x updates that makes x updates
*y *= 2;
cout << x << endl;

int num1;
// num3 is reference of num1
int& num3 = num1;
cout << num1 << endl;
//so num3 which is &num1 updates means num1 updates
num3 *= 2;
cout << num1 << "\t" << num3 << endl;
```

```
int arr[] = {10, 20, 30};
int* ptr = arr;
cout << *ptr << endl;
cout << *ptr+1 << endl;
cout << arr[0] << endl;
// moves to next index
cout << *(ptr+1) << endl;

int* ptr1 = &arr[1];
int* ptr2 = &arr[2];
// index difference (here 1 - 0)
cout << ptr2 - ptr1 << endl;
```

```
char* str[]{"hello world", "hi"}; // not allowed char* str[] = "abc";
cout << str[1] << endl; // hi
```

## Lecture 9

```
// How to run:
// g++ -std=c++11 -o a lectures/lecture_9.cpp main.cpp
```

```
// if class member and initializer variables are same names use this->
Student::Student(string name, int age, Grade grade) {
    this->name = name;
    this->age = age;
    this->grade = grade;
}
```

```
Student s1("Thura", 21, Grade::A);
cout << s1.getAge() << endl;
(s1.getGrade() == Grade::A) ? cout << "A" << endl: cout << "B" << endl;

// reference of the object can modify the value
Student& s2 = s1;
s2.setAge(22);
cout << "S2: " << s2.getAge() << endl;
cout << "S1: " << s1.getAge() << endl;

// pointer to the object can modify the value
Student* s3 = &s1;
s3->setAge(23);
cout << "S3: " << s3->getAge() << endl;
cout << "S1: " << s1.getAge() << endl;
```

-   Private members can be modified using & and \* concepts
-   Considerations: Encapsulation breach, Const correctness and Lift-time management

const keyword

```
// error
const Student s4("Thura", 21, Grade::A);
Student& s5 = s4; // Use const Student& s5 = s4;
s5.setAge(23); // Error if use const Student& s5 = s4; because of const
cout << "S3: " << s5.getAge() << endl;
cout << "S1: " << s4.getAge() << endl;

// error
Student* s5 = &s4; // Use const Student* s5 = &s4;
s5.setAge(23); // Error if use const Student& s5 = s4; because of const
cout << "S3: " << s5.getAge() << endl;
cout << "S1: " << s4.getAge() << endl;
```

Composition

-   Using a class as a member of another class

## Lecture 10

Operator overloading unchanged

-   Precedence
-   Associativity
-   Arity

Restrictions

-   No new operator
-   cannot alter fundamental types - int, char, etc.
-   -   and += do not automatically shared the overloading
-   -> () [] = must be declared as member of the class.

See the code: https://github.com/ThuraAung1601/learn_cpp/tree/main/notes/practise_for_final/complex.cpp

Dynamic memory management

```
int* ptr = new int;
int* arr = new int[10];

delete ptr;
delete[] arr;
```

## Lecture 11

```
    // ios::app is to append the existing text file
    ofstream myFile("check_out_list.txt", ios::app);
    if (myFile.is_open()) {  // if(!myFile.fail())
        for(CheckOut i: checkout_list) {
            myFile << i << endl;
        }
    } else {
        cerr << "Error:: File cannot opened";
        exit(1);
    };

    if (myFile.is_open()) {  // if(!myFile.fail())
        myFile << no1 << endl;
    } else {
        cerr << "Error:: File cannot opened";
        exit(1);
    };

    myFile.close();

    // read from the file
    ifstream myFile1("check_out_list.txt");
    string line;
    while (getline(myFile1, line)) {
        cout << line << endl;
    }
    myFile1.close();
```

## Lecture 12

Polymorphism

See the code: https://github.com/ThuraAung1601/learn_cpp/blob/main/notes/practise_for_final/practise_q3.cpp

Runtime polymorphism

```
// Create objects of Circle and Rectangle
Circle circle(5);
Rectangle rectangle(4, 6);

// Pointer to the base class
Shape* shape1 = &circle;
Shape* shape2 = &rectangle;

// Calculate and print areas using runtime polymorphism
std::cout << "Area of Circle: " << shape1->area() << std::endl;
std::cout << "Area of Rectangle: " << shape2->area() << std::endl;
```
