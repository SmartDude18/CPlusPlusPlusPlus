#include <iostream>


int main()
{
    //variables
    std::string name; //Stores the employee’s name
    char initial; //Stores the first letter of the last name
    short age; //Stores employee age (smallest type for 18-99 range)
    bool isAdult; //True if 18 or older, false otherwise
    unsigned zipcode; //Stores a 5-digit zip code (non-negative)
    float wage; //Stores the hourly wage
    short daysWorked; //Stores the number of days worked (max 7)
    float hoursWorkedPerDay[7]; //Stores hours worked per day (array for up to 7 days)
    const float taxRate = 0.1f; // 10% tax rate

    //data
    std::cout << "What is your first name? " << std::endl;
    std::cin >> name;

    std::cout << "what is the first initial of your last name? "<< std::endl;
    std::cin >> initial;

    std::cout << "How old are you? " << std::endl;
    std::cin >> age;

    std::cout << "What is your Zipcode? " << std::endl;
    std::cin >> zipcode;

    std::cout << "How much do you make per hour? " << std::endl;
    std::cin >> wage;

    std::cout << "How many days have you work this week? " << std::endl;
    std::cin >> daysWorked;


    float totalHours = 0;
    for (int i = 0; i < daysWorked; i++) {
        std::cout << "How many hours were worked on day " << (i + 1) << "? " << std::endl;
        float holdHours;
        std::cin >> holdHours;
        totalHours += holdHours;
        hoursWorkedPerDay[i] = holdHours;
    }


    float grossIncome = totalHours * wage;
    float taxAmount = grossIncome * taxRate;
    float netIncome = grossIncome - taxAmount;
    isAdult = (age >= 18);

    std::cout << "\nEmployee Payroll Summary"<<std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "Name: " << name << " " << initial << "." << std::endl;
    std::cout << "Age: " << age << " (Adult: " << (isAdult ? "Yes" : "No") << ")" << std::endl;
    std::cout << "Zipcode: " << zipcode << std::endl;
    std::cout << "Hourly Wage: $" << wage << " per hour" << std::endl;
    std::cout << "Total Hours Worked: " << totalHours << " hours" << std::endl;
    std::cout << "Gross Income: $" << grossIncome <<std::endl;
    std::cout << "Tax Amount: $" << taxAmount <<std::endl;
    std::cout << "Net Income: $" << netIncome <<std::endl;
}