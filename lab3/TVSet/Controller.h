#pragma once
#include "CTVSet.h"
#include "stdafx.h"

const std::string TURN_OFF = "TurnOff";
const std::string TURN_ON = "TurnOn";
const std::string SELECT_CHANNEL = "SelectChannel";
const std::string INFO = "Info";
const std::string SELECT_PREVIOUS_CHANNEL = "SelectPreviousChannel";
const std::string UNKNOWN_COMMAND = "Unknown command. Please close program or use:\n\tTurnOn\n\tTurnOff\n\tSelectChannel <channel>\n\tSelectPreviousChannel\n\tInfo\n";
const std::string TV_IS_ON = "TV is turned on\n";
const std::string TV_IS_OFF = "TV is turned off\n";
const std::string CHANNEL_NOT_EXIST = "Channel doesn't exist\n";
const std::string INPUT_ERROR = "Input error\n";
const std::string PREVIOUS_CHANNEL_SELECTED = "Previous channel selected\n";
const std::string SELECTED_CHANNEL = "Selected channel ";
const std::string CURRENT_CHANNEL = "Current channel ";
const std::string ALREADY_ON = "TV is already on\n";
const std::string ALREADY_OFF = "TV is already off\n";

void Controller(CTVSet& TV, std::istream& input, std::ostream& output);