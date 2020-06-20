#include "CParallelepiped.h"

CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
	:CBody("Parallelepiped", density),
	width(width),
	height(height),
	depth(depth)
{}

double CParallelepiped::GetWidth() const
{
	return CParallelepiped::width;
}

double CParallelepiped::GetHeight() const
{
	return CParallelepiped::height;
}

double CParallelepiped::GetDepth() const
{
	return CParallelepiped::depth;
}

double CParallelepiped::GetVolume() const
{
	return round(depth * height * width * 1000) / 1000;
}

void CParallelepiped::OtherParameters(std::ostream& output) const
{
	output << "Width: " 
		<< GetWidth() 
		<< "\nHeight: "
		<< GetHeight() 
		<<"\nDepth: " 
		<< GetDepth()
		<< std::endl;
}