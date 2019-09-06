#pragma once
#include <type_traits>
#include <iostream>
#include <vector>
#include <list>
#include <tuple>





// Is Integral
template<class T>
typename std::enable_if<std::is_integral<T>::value, T>::type
print_ip(const T& ip) {
    for (size_t sz = sizeof(T); sz != 0; --sz) {
        std::cout << ((ip >> (8 * (sz - 1))) & 0xff)
                  << (sz != 1 ? "." : "");
    }
}



// String
template<typename T>
struct is_string {
    static const bool value = false;
};

template<>
struct is_string<std::string> {
    static const bool value = true;
};

template <typename T>
typename std::enable_if<is_string<T>::value>::type print_ip(const T& ip) {
    std::cout << ip;
}


// Vector and List
template<typename T>
struct is_list_or_vector {
    static const bool value = false;
};

template<typename T>
struct is_list_or_vector<std::vector<T>> {
    static const bool value = true;
};


template<typename T>
struct is_list_or_vector<std::list<T>> {
    static const bool value = true;
};

template <typename T>
std::enable_if_t<is_list_or_vector<T>::value> print_ip(const T& ip) {
    auto it = ip.begin();
    while (it != ip.end()){
        std::cout << *it;
        ++it;
        it != ip.end() ? std::cout << "." : std::cout << "";
    }
}

// Tuple
template<typename... Args>
struct is_tuple {
    static const bool value = false;
};

template<typename... Args>
struct is_tuple<std::tuple<Args ...>> {
    static const bool value = true;
};

template<typename T, size_t arg_pos, size_t last_pos>
struct unpack_tuple {
    static void print_tuple(const T& value) {
        std::cout << std::get<arg_pos>(value) << ".";
        unpack_tuple<T, arg_pos + 1, last_pos>::print_tuple(value);
    }
};

template<typename Type, size_t arg_pos>
struct unpack_tuple<Type, arg_pos, arg_pos> {
    static void print_tuple(const Type& value) {
        std::cout << std::get<arg_pos>(value);
    }
};


template <typename... Args>
typename std::enable_if<is_tuple<Args...>::value> print_ip(const std::tuple<Args...>& ip) {
    constexpr int num_args_tuple = std::tuple_size<std::tuple<Args...>>::value;
    unpack_tuple<std::tuple<Args...>, 0, num_args_tuple - 1>::print_tuple(ip);

}
