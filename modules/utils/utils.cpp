#include "utils.h"

#include <utility>


std::string utils::ltrim(std::string string) {
    string.erase(string.begin(),
                 std::find_if(string.begin(), string.end(), [](unsigned char ch) { return !std::isspace(ch); }));
    return string;
}

std::string utils::rtrim(std::string string) {
    string.erase(
            std::find_if(string.rbegin(), string.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(),
            string.end());
    return string;
}

std::string utils::trim(std::string string) {
    return ltrim(rtrim(std::move(string)));
}

void utils::checkForRedundantSymbols(const std::string &string, const std::string &allowed_symbols) {
    for (const auto &symbol: string)
        if (allowed_symbols.find(symbol) == std::string::npos)
            throw std::invalid_argument("Operand data is invalid. Unknown symbol: '" + std::string(1, symbol) + "'.");
}

