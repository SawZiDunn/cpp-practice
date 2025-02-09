#include <iostream>
#include <string>
#include <vector>

// Define the Student_info struct
struct Student_info {
    std::string name;
    double midterm;
    double final;
    std::vector<double> homework;
};

// Function to print student information
void print_student_info(const Student_info &s) {
    std::cout << "Name: " << s.name << std::endl;
    std::cout << "Midterm: " << s.midterm << ", Final: " << s.final << std::endl;
    std::cout << "Homework Grades: ";
    for (double grade : s.homework) {
        std::cout << grade << " ";
    }
    std::cout << std::endl << std::endl;
}

int main() {
    // Create an instance of Student_info and set its member values
    Student_info student1;
    student1.name = "John Doe";
    student1.midterm = 88.5;
    student1.final = 92.0;
    student1.homework = {95.0, 87.0, 90.0};

    // Create another student instance
    Student_info student2 = {"Jane Smith", 90.0, 91.5, {88.0, 92.0, 85.0}};

    // Create a vector to hold multiple students
    std::vector<Student_info> students;
    students.push_back(student1);
    students.push_back(student2);

    // Iterate over the vector to print each student's info
    for (const auto& student : students) {
        print_student_info(student);
    }

    return 0;
}
