//
// Created by hao.wang on 2024/1/26.
//
#include "common.h"

class TestClass {
 public:
    TestClass() {
        std::cout << "Constructor function" << std::endl;
    }
    void func() {
        std::cout << "debug = " << debug << std::endl;
    }
    ~TestClass() {
        std::cout << "Destructor function" << std::endl;
    }

 private:
    int debug = 1;
};

TEST(unique_ptr, test1) {
    std::unique_ptr<TestClass> pTest = std::make_unique<TestClass>();
    pTest->func();
}