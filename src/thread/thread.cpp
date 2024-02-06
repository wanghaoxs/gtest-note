//
// Created by hao.wang on 2024/1/26.
//
#include "common.h"

class BackgroundThread {
 public:
    void operator()() const {
        for (int i = 0; i < 10; i++) {
            std::cout << "counter = " << i << std::endl;
            sleep(1);
        }
    }
};

TEST(thread, test1) {
    BackgroundThread backgroundThread;
    std::thread t(backgroundThread);
    t.join();
}

TEST(thread, test2) {
    std::thread t([] {
        for (int i = 0; i < 10; i++) {
            std::cout << "counter = " << i << std::endl;
            sleep(1);
        }
    });
    t.join();
}

class OperationTask {
 public:
    std::vector<int> v;
    void operator()() {
        std::cout << "task v.data() = " << v.data() << std::endl;
        std::cout << "task v.size() = " << v.size() << std::endl;
    }
};

TEST(temp2, test1) {
    unsigned long long size_1M = 1024 * 1024;
    std::vector<int> v1(size_1M / sizeof(int));
    std::cout << "main1 v1.data() = " << v1.data() << std::endl;
    std::cout << "main1 v1.size() = " << v1.size() << std::endl;

    OperationTask opTask;
    opTask.v = std::move(v1);
    std::thread t(opTask);

    std::cout << "main2 v1.data() = " << v1.data() << std::endl;
    std::cout << "main2 v1.size() = " << v1.size() << std::endl;

    t.join();

    std::cout << std::endl;
}
