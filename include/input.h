#ifndef G_INPUT_H
#define G_INPUT_H
#include <functional>
#include <unordered_map>

namespace Input
{
    auto processInput(int key, int scanCode, int action, int mods) -> void;
    extern std::unordered_map<int, std::function<void()>> keyMapping;
};
#endif
