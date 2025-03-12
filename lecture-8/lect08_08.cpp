#include <iostream>
#include <array>
#include <stdexcept> // Include for std::invalid_argument

// Date.h content
class Date
{
    friend std::ostream &operator<<(std::ostream &, const Date &);

public:
    Date(int m = 1, int d = 1, int y = 1900); // default constructor
    void setDate(int, int, int);              // set month, day, year
    Date &operator++();                       // prefix increment operator
    Date operator++(int);                     // postfix increment operator
    Date &operator+=(unsigned int);           // add days, modify object
    static bool leapYear(int);                // is year a leap year?
    bool endOfMonth(int) const;               // is day at the end of month?

private:
    unsigned int month;
    unsigned int day;
    unsigned int year;

    static const std::array<unsigned int, 13> days; // days per month
    void helpIncrement();                           // utility function for incrementing date
};

// Date.cpp content
const std::array<unsigned int, 13> Date::days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(int month, int day, int year)
{
    setDate(month, day, year);
}

void Date::setDate(int mm, int dd, int yy)
{
    if (mm >= 1 && mm <= 12)
    {
        month = mm;
    }
    else
    {
        throw std::invalid_argument{"Month must be 1-12"};
    }

    if (yy >= 1900 && yy <= 2100)
    {
        year = yy;
    }
    else
    {
        throw std::invalid_argument{"Year must be >= 1900 and <= 2100"};
    }

    if ((month == 2 && leapYear(year) && dd >= 1 && dd <= 29) || (dd >= 1 && dd <= days[month]))
    {
        day = dd;
    }
    else
    {
        throw std::invalid_argument{"Day is out of range for current month and year"};
    }
}

Date &Date::operator++()
{
    helpIncrement();
    return *this;
}

Date Date::operator++(int)
{
    Date temp{*this};
    helpIncrement();
    return temp;
}

Date &Date::operator+=(unsigned int additionalDays)
{
    for (unsigned int i = 0; i < additionalDays; ++i)
    {
        helpIncrement();
    }
    return *this;
}

bool Date::leapYear(int testYear)
{
    return (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0));
}

bool Date::endOfMonth(int testDay) const
{
    if (month == 2 && leapYear(year))
    {
        return testDay == 29;
    }
    else
    {
        return testDay == days[month];
    }
}

void Date::helpIncrement()
{
    if (!endOfMonth(day))
    {
        ++day;
    }
    else
    {
        if (month < 12)
        {
            ++month;
            day = 1;
        }
        else
        {
            ++year;
            month = 1;
            day = 1;
        }
    }
}

std::ostream &operator<<(std::ostream &output, const Date &d)
{
    static const char *monthName[13] = {"", "January", "February", "March", "April", "May", "June",
                                        "July", "August", "September", "October", "November", "December"};
    output << monthName[d.month] << ' ' << d.day << ", " << d.year;
    return output;
}

// main.cpp content
int main()
{
    Date d1{12, 27, 2010}; // December 27, 2010
    Date d2;               // defaults to January 1, 1900

    std::cout << "d1 is " << d1 << "\nd2 is " << d2 << "\n";
    std::cout << "\n\nd1 += 7 is " << (d1 += 7) << "\n";

    d2.setDate(2, 28, 2008);
    std::cout << "\n\nd2 is " << d2 << "\n";
    std::cout << "\n++d2 is " << ++d2 << " (leap year allows 29th)\n";

    Date d3{7, 13, 2010};
    std::cout << "\n\nTesting the prefix increment operator:\n"
              << " d3 is " << d3 << "\n";
    std::cout << "++d3 is " << ++d3 << "\n";
    std::cout << " d3 is " << d3 << "\n";

    std::cout << "\n\nTesting the postfix increment operator:\n"
              << " d3 is " << d3 << "\n";
    std::cout << "d3++ is " << d3++ << "\n";
    std::cout << " d3 is " << d3 << "\n";

    return 0;
}
