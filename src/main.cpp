#include "printip.h"

/*!
*    \mainpage
*    \brief Программа печати условного ip-адреса
*    \author Ivan Z
*    \version 1.0
*    \date август 2019 года
*
*    Функция выполняет печать условного ip-адреса.
*    Адрес может быть представлен в виде произвольного целочисленного типа.
*    Представление не зависит от знака типа. Выводить побайтово начиная со
*    старшего с символом . в качестве разделителя.
*    Адрес может быть представлен в виде строки. Выводится как есть.
*    Адрес может быть представлен в виде контейнеров std::list, std::vector.
*    Выводится содержимое контейнера поэлементно и разделяется ..
*    Дополнительно адрес может быть представлен в виде std::tuple при
*    условии, что все типы одинаковы. Выводится содержимое поэлементно и
*    разделяется .. Опционально.
*    Прикладной код должен содержать следующие вызовы:
*    • Печать адреса как char(-1)
*    • Печать адреса как short(0)
*    • Печать адреса как int(2130706433)
*    • Печать адреса как long(8875824491850138409)
*    • Печать адреса как std::string
*    • Печать адреса как std::vector
*    • Печать адреса как std::list
*    • Опционально. Печать адреса как std::tuple
*/


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
        print_ip(std::make_tuple(long(9), long(10), long(11), long(12)), std::cout);

    } catch (std::exception& e)
    {

        std::cout << e.what() << std::endl;
    }


    return 0;
}
