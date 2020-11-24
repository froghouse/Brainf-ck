#ifndef __BF_HPP__
#define __BF_HPP__ 1

#include <vector>
#include <string_view>
#include <cstddef>

namespace BF
{
    enum class Instruction
    {
        ADD,
        SUBTRACT,
        LEFT,
        RIGHT,
        LOOP_START,
        LOOP_END,
        OUTPUT,
        INPUT
    };
    
    void add();
    void subtract();
    void left();
    void right();
    void output();
    void input();
    void parse(const char*);
    void execute();

    extern std::string_view code;
    extern std::vector<Instruction> instructions;
    extern std::size_t pointer;
    extern std::vector<char> memory;
};

#endif // __BF_HPP__
