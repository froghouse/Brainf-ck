#include "bf.hpp"
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

RAII::File::File(const std::string_view fname)
{
    file_name = fname;
    ifs.open(std::string(file_name).c_str());
}

RAII::File::~File()
{
    if(ifs)
    {
        ifs.close();
    }

    if(ofs)
    {
        ofs.close();
    }
}

std::string RAII::File::read()
{
    if(!ifs)
    {
        if(ofs)
        {
            ofs.close();
        }

        ifs.open(std::string(file_name).c_str());
    }

    std::string tmp;
    
    ifs.seekg(0, std::ios::end);
    tmp.reserve(ifs.tellg());
    ifs.seekg(0, std::ios::beg);

    tmp.assign((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

    return tmp;
}

void RAII::File::write(const std::string_view data)
{
    if(!ofs)
    {
        if(ifs)
        {
            ifs.close();
        }


        ofs.open(std::string(file_name).c_str());
    }

    ofs << std::string(data).c_str();
}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cerr << "Usage: $ " << argv[0] << " <code_file>\n";
        return -1;
    }

    RAII::File f(argv[1]);

    BF::parse(f.read().c_str());
    BF::execute();

    return 0;
}
