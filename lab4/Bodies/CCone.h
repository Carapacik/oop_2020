#pragma once
#include "CBody.h"

class CCone final : public CBody
{
public:
	CCone(double density, double baseRadius, double height);
	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;
private:
	virtual void OtherParameters(std::ostream& output) const override;
	double baseRadius;
	double height;
};