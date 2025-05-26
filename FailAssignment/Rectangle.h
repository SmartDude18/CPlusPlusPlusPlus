#pragma once
#include <string>
#include "Shape.h"
class Rectangle : public Shape
{
public:
    Rectangle(float width, float height);

    float Area() override;
    std::string getShapeType() override;

private:
    float m_width;
    float m_height;
};

