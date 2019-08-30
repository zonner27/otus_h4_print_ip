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
void print_ip(std::string value, std::ostream& out)
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

/*!
*    Функция print_ip выводит в поток oustream ip-адрес переданный в качестве параметра
*    \param T tuple type
*    \param out Выходной поток
*/
template<typename... Args>
void print_ip(std::tuple<Args...> T, std::ostream& out)
{
    // т.к. все элементы tuple одного типа
    using mytype = typename std::tuple_element<0,decltype(T)>::type;
    std::vector<mytype> tmp;
    std::apply([&tmp](auto&&... args) {((tmp.push_back(args)), ...);}, T);
    print_ip(tmp, out);
}


#endif //PRINTIP214628082019_H
