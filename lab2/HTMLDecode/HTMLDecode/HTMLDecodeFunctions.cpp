#include "HTMLDecodeFunctions.h"

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

std::string ReplaceItemsInString(std::string& html, const std::string& entity, const std::string& character)
{
    std::string result = "";
    if (html.empty())
        return result;
    else 
    {
        size_t currentPos = 0;
        size_t foundPos = 0;
        while (foundPos != std::string::npos)
        {
            foundPos = html.find(entity, currentPos);
            if (foundPos != std::string::npos)
            {
                result.append(html, currentPos, foundPos - currentPos);
                currentPos = foundPos + entity.size();
                result.append(character);
            }
            else
            {
                result.append(html, currentPos, html.size());
                break;
            }
        }
        return result;
    }
}

std::string HTMLDecode(std::string const& html)
{
    std::string resultString = html;        
    for (auto item : HTML_ENTITIES) 
        resultString = ReplaceItemsInString(resultString, item.entity, item.character);

    return resultString;
}
