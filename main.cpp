#include "config.h"
#include "bf.hpp"

int main()
{
    const char *prg = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";

    BF::parse(prg);
    BF::execute();

    return 0;
}
