#include <iostream>
#include <array>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <tuple>


template <typename T>
decltype(std::cout << std::declval<T>(), void())
print_ip(T value, std::ostream& out)
{
    constexpr int size = sizeof(value);
    std::array<unsigned char, size> bytes;
    std::memcpy(&bytes, &value, size);
    for (unsigned int i = size - 1; i != 0; --i)
        out << std::to_string(bytes[i]) << ".";
    out << std::to_string(bytes[0]);
    out << std::endl;
}

void print_ip(std::string value, std::ostream& out)
{
    out << value << std::endl;
}

template <typename T>
decltype(begin(std::declval<T>()), end(std::declval<T>()), void())
print_ip(T container, std::ostream& out)
{
    for (auto it = std::begin(container); it != std::end(container); ++it)
        {
            out << std::to_string(*it);

            if (std::next(it) != std::end(container))
                out << ".";
        }
    out << std::endl;
}


template<typename... Args>
void print_ip(std::tuple<Args...> T, std::ostream& out)
{
    //int i = 0;
    //template <typename T1>
    std::vector<int> tmp;
    //std::apply([&i](auto&&... args) {((std::cout << args << '.' << ++i), ...);}, T);
    std::apply([&tmp](auto&&... args) {((tmp.push_back(args)), ...);}, T);
    for (auto var : tmp)
        out << var << " ";
//    for_each(T, callback());
    out << std::endl;
}


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
        print_ip(std::make_tuple(11, 12, 13, 14, 15, 17), std::cout);

    } catch (std::exception& e)
    {

        std::cout << e.what() << std::endl;
    }


    return 0;
}
