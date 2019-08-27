#include <iostream>
#include <array>
#include <string>
#include <cstring>
#include <vector>
#include <list>


template <typename T>
decltype(std::cout << std::declval<T>(), void())
print_ip(T value)
{
    constexpr int size = sizeof(value);
    std::array<unsigned char, size> bytes;
    std::memcpy(&bytes, &value, size);
    for (unsigned int i = size - 1; i != 0; --i)
        std::cout << std::to_string(bytes[i]) << ".";
    std::cout << std::to_string(bytes[0]);
    std::cout << std::endl;
}

void print_ip(std::string value)
{
    std::cout << value << std::endl;
}

template <typename T>
decltype(begin(std::declval<T>()), end(std::declval<T>()), void())
print_ip(T container)
{
    for (auto it = std::begin(container); it != std::end(container); ++it)
        {
            std::cout << std::to_string(*it);

            if (std::next(it) != std::end(container))
                std::cout << ".";
        }

    std::cout << std::endl;
}

int main()
{
    try {
        print_ip(char(-1));
        print_ip(short(0));
        print_ip(int(2130706433));
        print_ip(long(8875824491850138409));
        print_ip(std::string("192.168.1.1"));
        print_ip(std::vector<int>{1, 2, 3, 4});
        print_ip(std::list<char>{5, 6, 7, 8});

    } catch (std::exception& e) {

        std::cout << e.what() << std::endl;
    }


    return 0;
}
