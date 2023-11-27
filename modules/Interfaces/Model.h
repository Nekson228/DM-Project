#ifndef DM_MODULES_MODEL_H

#include <string>

class iModel {
public:
    [[nodiscard]] virtual std::string str() const = 0;
};

#define DM_MODULES_MODEL_H

#endif //DM_MODULES_MODEL_H
