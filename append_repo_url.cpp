/**
 * @file append_repo_url.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "append_repo_url.hpp"

void display_file(void) {
    for (int i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }
}

void open_file(void) {
    check_file_exists();
    file.open("repo_urls.txt");
    if (!file) {
        cout << "Error opening file" << endl;
        exit(1);
    }
}

void read_file(void) {
    while (getline(file, line)) {
        lines.push_back(line);
    }
}

void write_file(void) {
    ofstream new_file;
    new_file.open("clone_repo_urls.txt");
    if (!new_file) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    for (int i = 0; i < lines.size(); i++) {
        new_file << lines[i] << endl;
    }
    new_file.close();
}

void append_git_clone(void) {
    for (int i = 0; i < lines.size(); i++) {
        lines[i] = "git clone " + lines[i];
    }
}

void output_results(void) {
    for (int i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }
}

void close_file(void) {
    file.close();
}

void rename_file_directory(void) {
    rename("clone_repo_urls.txt", "clone_repo_urls.sh");
}

void check_file_exists(void) {
    if (file) {
        cout << "File exists" << endl;
    } else {
        cout << "File does not exist" << endl;
    }
}

void append_file(void) {
    ofstream new_file;
    new_file.open("repo_urls.txt", ios::app);
    if (!new_file) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    new_file << "clone_repo_urls.txt" << endl;
    new_file.close();
}

void compare_files(void) {
    ifstream file1;
    ifstream file2;
    file1.open("repo_urls.txt");
    file2.open("clone_repo_urls.txt");
    if (!file1 || !file2) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    while (getline(file1, line)) {
        lines.push_back(line);
    }
    while (getline(file2, line)) {
        lines.push_back(line);
    }
    for (int i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }
}

bool compare_file_diffs(void) {
    ifstream file1;
    ifstream file2;
    file1.open("repo_urls.txt");
    file2.open("clone_repo_urls.txt");
    if (!file1 || !file2) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    while (getline(file1, line)) {
        lines.push_back(line);
    }
    while (getline(file2, line)) {
        lines.push_back(line);
    }
    for (int i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }
    return true;
}

int main(int argc, char **argv) {
    open_file();
    read_file();
    append_git_clone();
    write_file();
    close_file();
    display_file();
    rename_file_directory();
    append_file();
    compare_files();
    compare_file_diffs();
    return 0;
}

