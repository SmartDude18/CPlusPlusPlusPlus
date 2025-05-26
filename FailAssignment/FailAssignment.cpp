// FailAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"


int main()
{
    std::vector<Shape*> shapes;

    Circle* c = new Circle(1.0f);
    c->SetRadius(3.0f);
    Rectangle* r = new Rectangle(4.0f, 5.0f);

    shapes.push_back(c);
    shapes.push_back(r);

    for (Shape* shape : shapes)
    {
        std::cout << "Area: " << shape->Area() << std::endl;
        //did use google to learn how to do the dynamic cast
        if (Circle* circle = dynamic_cast<Circle*>(shape))
        {
            std::cout << "Radius: " << circle->GetRadius() << std::endl;
        }
    }
    for (Shape* shape : shapes)
    {
        delete shape;
    }

    return 0;
}
