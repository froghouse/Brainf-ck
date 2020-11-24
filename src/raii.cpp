#include "raii.hpp"

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
