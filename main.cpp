#include "bf.hpp"
#include "raii.hpp"

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
