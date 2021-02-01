#ifndef G_INPUT_H
#define G_INPUT_H
#include <functional>
#include <unordered_map>

namespace Input
{
    auto processKeyInput(int key, int scanCode, int action, int mods) -> void;
    auto processQuickKeyInput() -> void;
    auto processMouseMoveInput(double x, double y) -> void;
    extern std::unordered_map<int, std::function<void()>> keyMapping;
    extern std::unordered_map<int, std::function<void()>> keyQuickMapping;
};
#endif
