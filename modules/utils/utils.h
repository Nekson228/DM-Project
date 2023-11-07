#include <algorithm>
#include <cctype>
#include <locale>

#ifndef DM_UTILS_H
#define DM_UTILS_H

// trim from start
std::string ltrim(std::string s);

// trim from end
std::string rtrim(std::string s);

// trim from both ends
std::string trim(std::string s);

#endif //DM_UTILS_H
