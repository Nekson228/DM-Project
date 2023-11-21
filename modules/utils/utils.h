#include <algorithm>
#include <cctype>
#include <locale>

#ifndef DM_UTILS_H
#define DM_UTILS_H

namespace utils {
    // trim from start
    std::string ltrim(std::string string);

    // trim from end
    std::string rtrim(std::string string);

    // trim from both ends
    std::string trim(std::string string);

    void checkForRedundantSymbols(const std::string& string, const std::string& allowed_symbols);
}

#endif //DM_UTILS_H
