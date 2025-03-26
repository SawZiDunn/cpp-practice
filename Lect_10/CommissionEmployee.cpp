
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "CommissionEmployee.h"
using namespace std;

// constructor
CommissionEmployee::CommissionEmployee(const string& first,
                                       const string& last,
                                       const string& ssn, double sales,
                                       double rate) {
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
}
// first name
void CommissionEmployee::setFirstName(const string& first) {
    firstName = first;
}
std::string CommissionEmployee::getFirstName() const { return firstName; }
// last name
void CommissionEmployee::setLastName(const string& last) {
    lastName = last;
}
std::string CommissionEmployee::getLastName() const { return lastName; }
// social security number
void CommissionEmployee::setSocialSecurityNumber(const string& ssn) {
    socialSecurityNumber = ssn;
}
std::string CommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}
// gross sales
void CommissionEmployee::setGrossSales(double sales) {
    if (sales >= 0.0) {
        grossSales = sales;
    } else {
        throw invalid_argument("Gross sales must be >= 0.0f");
    }
}
double CommissionEmployee::getGrossSales() const { return grossSales; }
// commission rate
void CommissionEmployee::setCommissionRate(double rate) {
    if (rate > 0.0f && rate < 1.0f) {
        commissionRate = rate;
    } else {
        throw std::invalid_argument(
            "Commission rate must be > 0.0f and < 1.0f");
    }
}
double CommissionEmployee::getCommissionRate() const { return commissionRate; }
// calculate earnings
double CommissionEmployee::earnings() const {
    return commissionRate * grossSales;
}
// return string representation of CommissionEmployee object
string CommissionEmployee::toString() const {
    ostringstream output;
    output << fixed << setprecision(2); // two digits of precision
    output << "commission employee: " << firstName << " " << lastName
        << "\nsocial security number: " << socialSecurityNumber << "\ngross sales: " << grossSales
        << "\ncommission rate: " << commissionRate;
    return output.str();
}
