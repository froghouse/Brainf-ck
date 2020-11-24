#ifndef __RAII_HPP__
#define __RAII_HPP__

#include <fstream>
#include <iostream>
#include <string_view>
#include <streambuf>

namespace RAII
{
    class File
    {
        public:
            File(const std::string_view);
            ~File();
            std::string read();
            void write(const std::string_view);
        private:
            std::ifstream ifs;
            std::ofstream ofs;
            std::string_view file_name;
    };
};

#endif // __RAII_HPP__
