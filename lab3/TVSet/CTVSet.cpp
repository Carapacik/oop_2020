#include "CTVSet.h"

void CTVSet::TurnOn()
{
	isEnable = true;
}

void CTVSet::TurnOff()
{
	isEnable = false;
}

bool CTVSet::IsTurnOn() const
{
	return isEnable;
}

bool CTVSet::IsExist(int currentChannel)
{
	return currentChannel >= minChannel && currentChannel <= maxChannel;
}

bool CTVSet::SelectChannel(int currentChannel)
{
	if (!isEnable) 
	{
		return false;
	}
	else if (IsExist(currentChannel))
	{
		previousChannel = channel;
		channel = currentChannel;
		return true;
	}
	return false;
}

int CTVSet::GetChannel() const
{
	if (isEnable)
		return channel;
	return 0;
}

void CTVSet::SelectPreviousChannel()
{
	if (!isEnable || previousChannel != 0)
		std::swap(channel, previousChannel);
}