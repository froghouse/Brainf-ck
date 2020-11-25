#include "raii.hpp"
#include <exception>
#include <filesystem>

bool file_exists(const std::filesystem::path& p, std::filesystem::file_status s = std::filesystem::file_status{})
{
    if(std::filesystem::status_known(s) ? std::filesystem::exists(s) : std::filesystem::exists(p))
    {
        return true;
    }

    return false;
}

RAII::File::File(const std::string_view fname)
{
    file_name = fname;

    if(file_exists(std::string(file_name).c_str()))
    {
        ifs.open(std::string(file_name).c_str());
    }
    else
    {
        throw std::invalid_argument(std::string(file_name) + " does not exist.");
    }
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

        if(file_exists(std::string(file_name).c_str()))
        {
            ifs.open(std::string(file_name).c_str());
        }
        else
        {
            throw std::invalid_argument(std::string(file_name) + " does not exist.");
        }
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

        if(file_exists(std::string(file_name).c_str()))
        {
            ofs.open(std::string(file_name).c_str());
        }
        else
        {
            throw std::invalid_argument(std::string(file_name) + " does not exist.");
        }
    }

    ofs << std::string(data).c_str();
}
