#include "Controller.h"

void TurnOn(CTVSet& TV, std::ostream& output)
{
	if (!TV.IsTurnOn())
	{
		TV.TurnOn();
		output << "TV is turned on\n";
	}
	else
	{
		output << "TV is already on\n";
	}
}

void TurnOff(CTVSet& TV, std::ostream& output)
{
	if (TV.IsTurnOn())
	{
		TV.TurnOff();
		output << "TV is turned off\n";
	}
	else
	{
		output << "TV is already off\n";
	}
}

void SelectChannel(CTVSet& TV, std::istream& input, std::ostream& output)
{
	int channel;
	if (input >> channel)
	{
		if (!TV.IsTurnOn())
		{
			output << "TV is turned off\nTurn on TV that select channel\n";
			return;
		}
		else if (!TV.IsExist(channel))
		{
			output << "Channel doesn't exist\n";
			return;
		}
		TV.SelectChannel(channel);
		output << "Selected channel " << channel << "\n";
	}
	else
	{
		output << "Input error\n";
		input.clear();
	}
}

void Info(CTVSet& TV, std::ostream& output)
{
	output << "TV is turned ";
	if (TV.IsTurnOn()) 
	{
		output << "on\n";
	}
	else 
	{
		output << "off\n";
	}
	output << "Current channel " << TV.GetChannel() << "\n";
}

void SelectPreviousChannel(CTVSet& TV, std::ostream& output)
{
	TV.SelectPreviousChannel();
	output << "Previous channel selected\n";
}

void Controller(CTVSet& TV, std::istream& input, std::ostream& output)
{
	std::string command;
	while (std::cin >> command)
	{
		if (command == "TurnOn")
		{
			TurnOn(TV, output);
		}
		else if (command == "TurnOff")
		{
			TurnOff(TV, output);
		}
		else if (command == "SelectChannel")
		{
			SelectChannel(TV, input, output);
		}
		else if (command == "Info")
		{
			Info(TV, output);
		}
		else if (command == "SelectPreviousChannel")
		{
			SelectPreviousChannel(TV, output);
		}
		else
		{
			output << "Unknown command. Please close program or use:\n\tTurnOn\n\tTurnOff\n\tSelectChannel\n\tSelectPreviousChannel\n\tInfo\n";
		}
	}
}