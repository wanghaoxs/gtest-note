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
    int channels = 3;
    omp_set_num_threads(channels);
#pragma omp parallel default(none) shared(std::cout)
    {
        int omp_thread_index = omp_get_thread_num();
        if (omp_thread_index % 3 == 0) {
            std::this_thread::sleep_for(std::chrono::seconds(10));
            std::string info = "current_thread_index = " + std::to_string(omp_thread_index) + "\n";
            std::cout << info << std::endl;
        } else if (omp_thread_index % 3 == 1) {
            std::string info = "current_thread_index = " + std::to_string(omp_thread_index) + "\n";
            std::cout << info << std::endl;
        } else if (omp_thread_index % 3 == 2) {
            std::string info = "current_thread_index = " + std::to_string(omp_thread_index) + "\n";
            std::cout << info << std::endl;
        }
    }
    std::cout << "end!!!!!!!!!" << std::endl;
}