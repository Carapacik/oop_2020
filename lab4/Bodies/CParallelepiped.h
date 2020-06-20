#pragma once
#include "CBody.h"

class CParallelepiped final : public CBody
{
public:
	CParallelepiped(double density, double width, double height, double depth);
	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;
	double GetVolume() const override;
private:
	virtual void OtherParameters(std::ostream& output) const override;
	double width;
	double height;
	double depth;
};