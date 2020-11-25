#include "bf.hpp"
#include "raii.hpp"

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cerr << "Usage: $ " << argv[0] << " <code_file>\n";
        return -1;
    }
    
    try 
    {
        RAII::File f(argv[1]);

        BF::parse(f.read().c_str());
        BF::execute();
    }
    catch(std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return -2;
    }

    return 0;
}
