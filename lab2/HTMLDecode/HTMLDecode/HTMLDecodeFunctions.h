#pragma once
#include "stdafx.h"

struct Entities
{
    std::string character;
    std::string entity;
};

const std::vector<Entities> HTML_ENTITIES =
{
    {"&", "&amp;"},
    {"'", "&apos;"},
    {">", "&gt;"},
    {"<", "&lt;"},
    {"\"", "&quot;"}
};

std::string ReplaceItemsInString(std::string& html, const std::string& entity, const std::string& character);
std::string HTMLDecode(std::string const& html);