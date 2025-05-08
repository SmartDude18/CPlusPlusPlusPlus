#pragma once
#include <iostream>
#include <string>

class Employee {
public:
    void setValues();
    friend std::ostream& operator << (std::ostream& os, Employee& const employee);

private:
    std::string name;
    short age;
    unsigned int zipcode;
    float wage;
    float hoursWorked;

    static const float taxRate; // Declare tax as a static constant
};
