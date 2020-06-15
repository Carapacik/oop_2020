#pragma once
#include "stdafx.h"

class CTVSet
{
public:
	void TurnOn();
	void TurnOff();
	bool IsExist(int currentChannel);
	bool SelectChannel(int currentChannel);
	int GetChannel() const;
	bool IsTurnOn() const;
	void SelectPreviousChannel();

private:
	bool isEnable = false;
	int channel = 1;
	int previousChannel = 0;
	static const int minChannel = 1;
	static const int maxChannel = 99;
};