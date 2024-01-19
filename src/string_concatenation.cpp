//
// Created by hao.wang on 2024/1/12.
//
#include "common.h"

TEST(gtest, string_concatenation) {
    std::string str = Util::string_concatenation("test", 1, "gtest", 1);
    std::cout << str << std::endl;
}