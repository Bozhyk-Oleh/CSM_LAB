// globalogic_task_Bozhyk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "FileSearch.h"
#include <chrono>
#include <thread>

#define NumbThreads 4

int main()
{
    std::vector<std::string> paths, sub_directories;
    get_vector_sub_directories(sub_directories, "C:\\");
    std::string target_file;
    std::cout << "Enter file name without extension:";
    std::cin >> target_file;
    auto start = std::chrono::high_resolution_clock::now();
    unsigned int x = (sub_directories.size() / NumbThreads) + 1;
    std::thread t1(search_in_folder, ref(paths), sub_directories, 0, sub_directories.size(), target_file);
    t1.detach();
    std::thread t2(search_in_folder, ref(paths), sub_directories, x, 2 * x, target_file);
    t2.detach();
    std::thread t3(search_in_folder, ref(paths), sub_directories, 2 * x, 3 * x, target_file);
    t3.detach();
    std::thread t4(search_in_folder, ref(paths), sub_directories, 3 * x, sub_directories.size(), target_file);
    t4.detach();
    while (paths.empty()) {
    }
    std::cout << "Result:\n";
    for (int i = 0; i < paths.size(); i++)
        std::cout << paths[i] << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << "\nDuration:" << duration.count() << "s" << std::endl;
}

