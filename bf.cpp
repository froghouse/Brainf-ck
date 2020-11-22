#include "bf.hpp"
#include <exception>
#include <iostream>

std::string_view BF::code;
std::vector<BF::Instruction> BF::instructions;
std::size_t BF::pointer;
std::vector<char> BF::memory = {0};

void BF::add()
{
    BF::memory[BF::pointer] += 1;
}

void BF::subtract()
{
    BF::memory[BF::pointer] -= 1;
}

void BF::left()
{
    if(BF::pointer == 0)
    {
        throw std::runtime_error("Memory Underflow");
    }

    BF::pointer--;
}

void BF::right()
{
    if(BF::pointer == BF::memory.size() - 1)
    {
        BF::memory.push_back(0);
    }

    BF::pointer++;
}

void BF::output()
{
    std::cout << BF::memory[BF::pointer];
}

void BF::input()
{
    std::cin >> BF::memory[BF::pointer];
}

void BF::parse(const char* prg)
{
    code = prg;

    for(auto c : code)
    {
        switch(c)
        {
            case '+':
                BF::instructions.push_back(BF::Instruction::ADD);
                break;
            case '-':
                BF::instructions.push_back(BF::Instruction::SUBTRACT);
                break;
            case '<':
                BF::instructions.push_back(BF::Instruction::LEFT);
                break;
            case '>':
                BF::instructions.push_back(BF::Instruction::RIGHT);
                break;
            case '[':
                BF::instructions.push_back(BF::Instruction::LOOP_START);
                break;
            case ']':
                BF::instructions.push_back(BF::Instruction::LOOP_END);
                break;
            case '.':
                BF::instructions.push_back(BF::Instruction::OUTPUT);
                break;
            case ',':
                BF::instructions.push_back(BF::Instruction::INPUT);
                break;
        }
    }
}

void BF::execute()
{
    auto ip = std::begin(BF::instructions);
    BF::pointer = 0;
    std::size_t loop_nesting = 0;

    while(ip != std::end(BF::instructions))
    {
        switch(*ip)
        {
            case BF::Instruction::ADD:
                BF::add();
                break;

            case BF::Instruction::SUBTRACT:
                BF::subtract();
                break;

            case BF::Instruction::LEFT:
                BF::left();
                break;

            case BF::Instruction::RIGHT:
                BF::right();
                break;

            case BF::Instruction::LOOP_START:
                if(BF::memory[BF::pointer] == 0)
                {
                    loop_nesting = 0;

                    while(true)
                    {
                        ++ip;

                        if(*ip == BF::Instruction::LOOP_START)
                        {
                            ++loop_nesting;
                            continue;
                        }
                        else if(loop_nesting > 0 && *ip == BF::Instruction::LOOP_END)
                        {
                            --loop_nesting;
                            continue;
                        }
                        else if(*ip == BF::Instruction::LOOP_END && loop_nesting == 0)
                        {
                            break;
                        }
                    }
                }
                break;

            case BF::Instruction::LOOP_END:
                if(BF::memory[BF::pointer] != 0)
                {
                    loop_nesting = 0;

                    while(true)
                    {
                        --ip;

                        if(*ip == BF::Instruction::LOOP_END)
                        {
                            ++loop_nesting;
                            continue;
                        }
                        else if(loop_nesting > 0 && *ip == BF::Instruction::LOOP_START)
                        {
                            --loop_nesting;
                            continue;
                        }
                        else if(*ip == BF::Instruction::LOOP_START && loop_nesting == 0)
                        {
                            break;
                        }
                    }
                }
                break;

            case BF::Instruction::OUTPUT:
                BF::output();
                break;

            case BF::Instruction::INPUT:
                BF::input();
                break;
        }

        ++ip;
    }
}

