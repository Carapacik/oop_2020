#pragma once
#include "CBody.h"

class CSphere final : public CBody
{
public:
	CSphere(double density, double radius);
	double GetRadius() const;
	double GetVolume() const override;
private:
	virtual void OtherParameters(std::ostream& output) const override;
	double radius;
};