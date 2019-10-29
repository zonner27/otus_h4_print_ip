#ifndef PRINTIP214628082019_H
#define PRINTIP214628082019_H

#include <iostream>
#include <array>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <tuple>

/*!
*    Функция print_ip выводит в поток oustream ip-адрес переданный в качестве параметра
*    \param T integral type
*    \param out Выходной поток
*/
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

/*!
*    Функция print_ip выводит в поток oustream ip-адрес переданный в качестве параметра
*    \param T string type
*    \param out Выходной поток
*/
void print_ip(const std::string &value, std::ostream& out)
{
    out << value << std::endl;
}

/*!
*    Функция print_ip выводит в поток oustream ip-адрес переданный в качестве параметра
*    \param T container type
*    \param out Выходной поток
*/
template <typename T>
decltype(begin(std::declval<T>()), end(std::declval<T>()), void())
print_ip(const T &container, std::ostream& out)
{
    for (auto it = std::begin(container); it != std::end(container); ++it)
        {
            out << std::to_string(*it);

            if (std::next(it) != std::end(container))
                out << ".";
        }
    out << std::endl;
}

/*!
*    Функция print_ip выводит в поток oustream ip-адрес переданный в качестве параметра
*    \param T tuple type
*    \param out Выходной поток
*/
template<typename... Args>
void print_ip(std::tuple<Args...> T, std::ostream& out)
{
    bool i = 0;
    std::apply([&i, &out](auto&&... args) {(((i == 0 ? out << args : out << "." << args), i = 1), ...);}, T);
    out << std::endl;
}


#endif //PRINTIP214628082019_H
