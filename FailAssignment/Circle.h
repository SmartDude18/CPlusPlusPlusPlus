#pragma once
#include <string>
#include "Shape.h"
class Circle : public Shape
{
public:
    Circle(float radius);

    float Area() override;

    void SetRadius(float radius);
    float GetRadius();
    std::string getShapeType() override;

private:
    float m_radius;
};

