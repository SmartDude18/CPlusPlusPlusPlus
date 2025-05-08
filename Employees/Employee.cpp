#include "Employee.h";
#include <iostream>;
using namespace std;
const float Employee::taxRate = 0.1f;
void Employee::setValues()
{
    std::cout << "Enter name: ";
    std::cin >> name;

    std::cout << "Enter age: ";
    std::cin >> age;

    std::cout << "Enter zipcode: ";
    std::cin >> zipcode;

    std::cout << "Enter hourly wage: ";
    std::cin >> wage;

    std::cout << "Enter total hours worked this week: ";
    std::cin >> hoursWorked;
}

std::ostream& operator << (std::ostream& os, Employee& const employee)
{
    
    float weeklyGross = employee.wage * employee.hoursWorked;
    float weeklyTax = weeklyGross * employee.taxRate;
    float weeklyNet = weeklyGross - weeklyTax;
    float yearlyGross = weeklyGross * 52;
    float yearlyNet = yearlyGross - (yearlyGross * employee.taxRate);

    os << "\nEmployee Payroll Summary\n";
    os << "-------------------------\n";
    os << "Name: " << employee.name << "\n";
    os << "Age: " << employee.age << "\n";
    os << "Zipcode: " << employee.zipcode << "\n";
    os << "Hourly Wage: $" << employee.wage << "\n";
    os << "Hours Worked: " << employee.hoursWorked << "\n";
    os << "Weekly Gross Pay: $" << weeklyGross << "\n";
    os << "Weekly Net Pay: $" << weeklyNet << "\n";
    os << "Yearly Gross Pay: $" << yearlyGross << "\n";
    os << "Yearly Net Pay: $" << yearlyNet << "\n";
    return os;
}