#include "printip.h"

int main()
{
    try
    {
        print_ip(char(-1), std::cout);
        print_ip(short(0), std::cout);
        print_ip(int(2130706433), std::cout);
        print_ip(long(8875824491850138409), std::cout);
        print_ip(std::string("192.168.1.1"), std::cout);
        print_ip(std::vector<int>{1, 2, 3, 4}, std::cout);
        print_ip(std::list<char>{5, 6, 7, 8}, std::cout);
        print_ip(std::make_tuple(long(11), long(10), long(13), long(15)), std::cout);

    } catch (std::exception& e)
    {

        std::cout << e.what() << std::endl;
    }


    return 0;
}
