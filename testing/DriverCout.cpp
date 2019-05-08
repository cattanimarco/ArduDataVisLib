#include <iostream>

#include "DriverCout.h"

DriverCout::DriverCout(void)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void DriverCout::drawPixel(Point point, int thickness, Color color)
{
	// std::cout << "DriverCout::drawPixel x: " << point.x
	// 		  << " y: " << point.y
	// 		  << " value: " << point.value
	// 		  << " tickness: " << thickness
	// 		  << " color: (" << (int)color.red
	// 		  << "," << (int)color.green
	// 		  << "," << (int)color.blue
	// 		  << ")" << std::endl;
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void DriverCout::drawLine(Line line, int thickness, Color color)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	//drawPixel(line.begin,thickness,color);
}

void DriverCout::drawCircle(Circle circle, int thickness, Color color)
{
}

void DriverCout::drawRectangle(Rectangle rectangle, int thickness, Color color)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void DriverCout::fillRectangle(Rectangle rectangle, Color color)
{
}

void DriverCout::fillCircle(Circle circle, Color color)
{
}
