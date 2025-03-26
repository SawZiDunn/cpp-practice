#include <iomanip>
#include <sstream>
#include <stdexcept>
#include "BPCommissionEmployee.h" 
using namespace std;

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const string& first, const string& last, const string& ssn,
    double sales, double rate, double salary)
    : CommissionEmployee(first, last, ssn, sales, rate) // Initialize base class
{
    setBaseSalary(salary); // validate and store base salary
}

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    if (salary < 0.0) {
        throw invalid_argument("Salary must be >= 0.0");
    }
    baseSalary = salary;
}

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const { 
    return baseSalary; 
}

// calculate earnings
double BasePlusCommissionEmployee::earnings() const {
    // Access base class members using CommissionEmployee:: prefix
    return baseSalary + CommissionEmployee::earnings(); 
}

// return string representation of BasePlusCommissionEmployee object
string BasePlusCommissionEmployee::toString() const { 
    ostringstream output;
    output << fixed << setprecision(2); // two digits of precision

    // Access base class members using CommissionEmployee:: prefix
    output << "base-salaried commission employee: " 
           << CommissionEmployee::getFirstName() << ' ' 
           << CommissionEmployee::getLastName() 
           << "\nsocial security number: " << CommissionEmployee::getSocialSecurityNumber() 
           << "\ngross sales: " << CommissionEmployee::getGrossSales()
           << "\ncommission rate: " << CommissionEmployee::getCommissionRate()
           << "\nbase salary: " << baseSalary; 

    return output.str(); 
} 