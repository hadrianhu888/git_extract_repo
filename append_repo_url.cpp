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

void open_file(void) {
    file.open("repo_urls.txt");
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
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
    if (!new_file.is_open()) {
        cout << "Error opening file" << endl;
    }
    new_file.close();
}

void append_file(void) {
    ofstream new_file;
    new_file.open("clone_repo_urls.txt", ios::app);
    if (!new_file.is_open()) {
        cout << "Error opening file" << endl;
    }
    new_file.close();
}

void append_git_clone(void) {
    ofstream new_file;
    new_file.open("clone_repo_urls.txt", ios::app);
    if (!new_file.is_open()) {
        cout << "Error opening file" << endl;
    }
    for (int i = 0; i < lines.size(); i++) {
        new_file << "git clone " << lines[i] << endl;
    }
    new_file.close();
}

void close_file(void) {
    file.close();
}

void display_file(void) {
    ifstream new_file;
    new_file.open("clone_repo_urls.txt");
    if (!new_file.is_open()) {
        cout << "Error opening file" << endl;
    }
    while (getline(new_file, line)) {
        cout << line << endl;
    }
    new_file.close();
}

void output_results(void) {
    cout << "The file has been created" << endl;
}

void rename_file_directory(void) {
    int result = rename("clone_repo_urls.txt", "clone_repo_urls.sh");
    if (result == 0) {
        cout << "File successfully renamed" << endl;
    } else {
        cout << "Error renaming file" << endl;
    }
}

void check_file_exists(void) {
    ifstream new_file;
    new_file.open("clone_repo_urls.txt");
    if (!new_file.is_open()) {
        cout << "Error opening file" << endl;
    }
    new_file.close();
}

void compare_files(void) {
    ifstream new_file;
    new_file.open("clone_repo_urls.txt");
    if (!new_file.is_open()) {
        cout << "Error opening file" << endl;
    }
    while (getline(new_file, line)) {
        cout << line << endl;
    }
    new_file.close();
}

bool compare_file_diffs(void) {
    ifstream new_file;
    new_file.open("clone_repo_urls.txt");
    if (!new_file.is_open()) {
        cout << "Error opening file" << endl;
    }
    while (getline(new_file, line)) {
        cout << line << endl;
    }
    new_file.close();
}

int main(int argc, char **argv) {
    open_file();
    read_file();
    write_file();
    append_file();
    append_git_clone();
    close_file();
    display_file();
    output_results();
    rename_file_directory();
    check_file_exists();
    compare_files();
    compare_file_diffs();
    return 0;
}
