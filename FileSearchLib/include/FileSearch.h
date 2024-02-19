#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <chrono>
#include <thread>

static bool not_finish_job = true;

bool get_status_job();
void get_vector_sub_directories(std::vector<std::string>& sub_directories, const std::string start_point);
void search_in_folder(std::vector<std::string>& path, std::vector<std::string> sub_directory, int start_point, int end_point, std::string target);