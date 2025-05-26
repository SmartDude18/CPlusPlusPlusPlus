#pragma once
#include <string>
class Shape
{
	public:
		virtual float Area() = 0;
		virtual std::string getShapeType() = 0;
};

