// FileSearch.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "FileSearch.h"

// TODO: This is an example of a library function
void get_vector_sub_directories(std::vector<std::string>& sub_directories, const std::string start_point) {
    for (auto& file : std::filesystem::directory_iterator(start_point, std::filesystem::directory_options::skip_permission_denied)) {
        sub_directories.push_back(file.path().string());
    }
}

void search_in_folder(std::vector<std::string>& path, std::vector<std::string> sub_directory, int start_point, int end_point, std::string target) {
    for (int i = start_point; i < end_point; i++) {
        if (sub_directory[i] != "C:\\Documents and Settings" && std::filesystem::path(sub_directory[i]).extension() != ".sys"
            && std::filesystem::path(sub_directory[i]).extension() != ".log" && std::filesystem::path(sub_directory[i]).extension() != ".tmp"
            && !sub_directory[i].starts_with(".")) {

            for (auto& file : std::filesystem::recursive_directory_iterator(sub_directory[i], std::filesystem::directory_options::skip_permission_denied)) {
                //std::cout << std::this_thread::get_id() << "----" << file << std::endl;
                if (file.path().filename().replace_extension() == target) {
                    path.push_back(file.path().string());
                    not_finish_job = false;
                    return;
                }
            }
        }
        else
            continue;
    }
}

bool get_status_job() {
    return not_finish_job;
}