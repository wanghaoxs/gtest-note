//
// Created by hao.wang on 2024/1/12.
//
#include "common.h"

TEST(gtest, string_concatenation) {
    std::string str = Util::string_concatenation("test", 1, "gtest", 1);
    std::cout << str << std::endl;
}

template <typename T, typename... Ts>
void print(T value, Ts... values) {
    std::cout << value << ", ";
    if constexpr (sizeof...(values) > 0) {
        print(values...);
    }
}

TEST(parameter_pack, test1) {
    print("gtest", 10, 2.00);

    std::cout << std::endl;
}