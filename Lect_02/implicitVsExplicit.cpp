#include <iostream>
#include <string>

// Without explicit (allows implicit conversion)
class BankAccount1
{
public:
    // using // prevents narrowing conversions like double to int
    BankAccount1(const std::string &accNum, int initialPin)
        : balance(0.0), accountNumber(accNum), pin{initialPin} {}

    void showAccount()
    {
        std::cout << "Account: " << accountNumber << ", PIN: " << pin << std::endl;
    }

private:
    double balance;
    std::string accountNumber;
    int pin;
};

// With explicit (prevents implicit conversion)
class BankAccount2
{
public:
    explicit BankAccount2(const std::string &accNum, int initialPin)
        : balance(0.0), accountNumber(accNum), pin(initialPin) {}

    void showAccount()
    {
        std::cout << "Account: " << accountNumber << ", PIN: " << pin << std::endl;
    }

private:
    double balance;
    std::string accountNumber;
    int pin;
};

int main()
{
    // Both classes allow these (direct initialization):
    BankAccount1 acc1("12345", 500.567);
    BankAccount2 acc2("12345", 1111);

    // Only BankAccount1 (without explicit) allows these:
    BankAccount1 acc3 = {"67890", 2222};             // Works: implicit conversion allowed
    BankAccount1 acc4 = BankAccount1{"98765", 3333}; // Works: implicit conversion allowed

    // These won't compile with BankAccount2 (with explicit):
    BankAccount2 acc0{"12345", 1111};
    // BankAccount2 acc5 = {"67890", 2222};        // Error: implicit conversion not allowed
    // BankAccount2 acc6 = BankAccount2{"98765", 3333};  // Error: implicit conversion not allowed

    // Show the accounts
    acc1.showAccount(); // Works
    acc2.showAccount(); // Works
    acc3.showAccount(); // Works
    acc4.showAccount(); // Works
    acc0.showAccount();

    return 0;
}