#include "common.h"

TEST(gtest, string_concatenation1) {
    std::string str = Util::string_concatenation("test", 1, "gtest", 1);
    std::cout << str << std::endl;
}

TEST(gtest, read_json) {}

 TEST(gtest, openmp) {
    int channels = 2;
    omp_set_num_threads(3 * channels);
#pragma omp parallel default(none) shared(std::cout)
    {
        int omp_thread_index = omp_get_thread_num();
        int current_thread_index = omp_get_thread_num() / 3 + 1;
        if (omp_thread_index % 3 == 0) {
            std::string info = "current_thread_index = " + std::to_string(current_thread_index) + "\n";
            std::cout << info << std::endl;
        } else if (omp_thread_index % 3 == 1) {
            std::string info = "current_thread_index = " + std::to_string(current_thread_index) + "\n";
            std::cout << info << std::endl;
        } else if (omp_thread_index % 3 == 2) {
            std::string info = "current_thread_index = " + std::to_string(current_thread_index) + "\n";
            std::cout << info << std::endl;
        }
    }
}