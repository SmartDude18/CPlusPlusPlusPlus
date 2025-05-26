#include <string>
#include "Rectangle.h"

Rectangle::Rectangle(float width, float height)
{
	m_width = width;
	m_height = height;
}

float Rectangle::Area()
{
	return m_width * m_height;
}

std::string Rectangle::getShapeType()
{
	return "Rectangle";
}