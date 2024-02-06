#include <syscall.h>

#include "common.h"

class ThreadTest {
 public:
    ThreadTest() = default;
    void print_tid() {
        std::cout << "this thread id: " << std::this_thread::get_id() << std::endl;
    }
};

TEST(gtest, openmp) {
    std::cout << "gtest" << std::endl;
    int channels = 2;
    omp_set_num_threads(channels);
    // cuInit(0);
#pragma omp parallel default(none) shared(std::cout)
    {
        cuInit(0);
        std::cout << "main : " + std::to_string(omp_get_thread_num()) << std::endl;
    }
}

TEST(gtest, openmp1) {
    std::cout << "gtest" << std::endl;
    int channels = 2;
    omp_set_num_threads(channels);
#pragma omp parallel default(none) shared(std::cout)
    {
        std::cout << "main : " + std::to_string(omp_get_thread_num()) << std::endl;
        int omp_thread_index = omp_get_thread_num();
        int current_thread_index = omp_get_thread_num() / 3 + 1;
        if (omp_thread_index % 3 == 0) {
            std::string info = "current_thread_index = " + std::to_string(current_thread_index) + "\n";
            std::cout << info << std::endl;
            //            ThreadTest thread1;
            //            thread1.print_tid();
        } else if (omp_thread_index % 3 == 1) {
            std::string info = "current_thread_index = " + std::to_string(current_thread_index) + "\n";
            std::cout << info << std::endl;
            //            ThreadTest thread2;
            //            thread2.print_tid();
        } else if (omp_thread_index % 3 == 2) {
            std::string info = "current_thread_index = " + std::to_string(current_thread_index) + "\n";
            std::cout << info << std::endl;
            //            ThreadTest thread3;
            //            thread3.print_tid();
        }
    }
}