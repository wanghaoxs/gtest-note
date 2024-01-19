//
// Created by hao.wang on 2024/1/10.
//

#ifndef GTEST_TOOL_UTIL_H
#define GTEST_TOOL_UTIL_H

#include <iostream>
#include <sstream>

class Util {
 public:
    template <typename T>
    static std::string string_concatenation(const T& argv) {
        std::string str = "";
        std::stringstream ss;
        ss << argv;
        str = ss.str();
        return str;
    }

    template <typename T, typename... Args>
    static std::string string_concatenation(const T& t, const Args&... rest) {
        std::string str = "";
        std::stringstream ss;
        ss << t;
        ss << string_concatenation(rest...);
        str = ss.str();
        return str;
    }
};
#endif  // GTEST_TOOL_UTIL_H
