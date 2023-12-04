#include <iostream>
#include <iomanip>

class Account {
protected:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    Account(const std::string& number, const std::string& holder, double initialBalance)
        : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

    void displayDetails() const {
        std::cout << "Account Details for " << getAccountType() << " (ID: " << accountNumber << "):" << std::endl;
        std::cout << "   Holder: " << accountHolder << std::endl;
        std::cout << "   Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    }

    virtual std::string getAccountType() const {
        return "Generic Account";
    }

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited $" << amount << " into " << getAccountType() << " (ID: " << accountNumber << ")." << std::endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " from " << getAccountType() << " (ID: " << accountNumber << ")." << std::endl;
        } else {
            std::cout << "Insufficient funds to withdraw $" << amount << " from " << getAccountType() << " (ID: " << accountNumber << ")." << std::endl;
        }
    }

    // Overload assignment operator
    Account& operator=(const Account& other) {
        if (this != &other) {
            accountNumber = other.accountNumber;
            accountHolder = other.accountHolder;
            balance = other.balance;
        }
        return *this;
    }

    friend class CurrentAccount; // Declare CurrentAccount as a friend
    friend Account operator+(const Account& lhs, const Account& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double rate)
        : Account(number, holder, initialBalance), interestRate(rate) {}

    std::string getAccountType() const override {
        return "Savings Account";
    }

    void withdraw(double amount) override {
        const double minBalance = 100; // Minimum balance requirement
        if (balance - amount >= minBalance) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " from " << getAccountType() << " (ID: " << accountNumber << ")." << std::endl;
        } else {
            std::cout << "Cannot withdraw $" << amount << " from " << getAccountType() << " (ID: " << accountNumber << "). Minimum balance not met." << std::endl;
        }
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(const std::string& number, const std::string& holder, double initialBalance, double limit)
        : Account(number, holder, initialBalance), overdraftLimit(limit) {}

    // Conversion constructor
    CurrentAccount(const Account& account)
        : Account(account), overdraftLimit(0) {}

    std::string getAccountType() const override {
        return "Current Account";
    }

    void withdraw(double amount) override {
        if (amount <= (balance + overdraftLimit)) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " from " << getAccountType() << " (ID: " << accountNumber << ")." << std::endl;
        } else {
            std::cout << "Cannot withdraw $" << amount << " from " << getAccountType() << " (ID: " << accountNumber << "). Overdraft limit exceeded." << std::endl;
        }
    }

    friend Account operator+(const Account& lhs, const Account& rhs);
};

// Define operator+ function outside of the class
Account operator+(const Account& lhs, const Account& rhs) {
    Account result = lhs; // Use the conversion constructor
    result.balance += rhs.balance;
    std::cout << "Transferred $" << rhs.balance << " from " << rhs.getAccountType() << " (ID: " << rhs.accountNumber
              << ") to " << lhs.getAccountType() << " (ID: " << lhs.accountNumber << ")." << std::endl;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "Account Details after transaction:" << std::endl;
    os << account.getAccountType() << " (ID: " << account.accountNumber << "):" << std::endl;
    os << "   Holder: " << account.accountHolder << std::endl;
    os << "   Balance: $" << std::fixed << std::setprecision(2) << account.balance << std::endl;
    return os;
}

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);

    savings.displayDetails();
    current.displayDetails();

    // Transfer 300 from savings to current
    current = current + savings;

    std::cout << current;

    return 0;
}
