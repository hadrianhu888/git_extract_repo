/**
*/
#ifndef APPEND_REPO_URL_HPP
#define APPEND_REPO_URL_HPP
#ifdef __cplusplus
#include <iostream>
#include <cstdio> 
#include <cstdlib> 
#include <fstream>
#include <string>
#include <sstream> 
#include <vector>
#include <algorithm>
#include <iterator>
#include <regex>
#include <cctype> 
#include <algorithm>
#endif 
using namespace std;

// global variables
ifstream file;
char **urls; 
string line;
vector<string> lines;
string new_line;
string new_file_name;
string file_name;

/**
 * @brief Open the file "repo_urls.txt"
 *  Append each line with "git clone "
    *  Check that the file exists 
    *  Write the new line to a new file "clone_repo_urls.txt"
    *  Save and close the file 
    *  Display the new file
    *  Rename the file directory to "clone_repo_urls.sh"
 */

int main(int argc, char **argv); // default main function
void open_file(void); // open the file
void read_file(void); // read the file
void write_file(void); // write to the file
void append_file(void); // append to the file
void append_git_clone(void); // append "git clone " to each line
void close_file(void); // close the file
void display_file(void); // display the file
void output_results(void); // output results
void rename_file_directory(void); // rename
void check_file_exists(void); // check if the file exists. If exists, override. If it does not exist, write the file. 
void compare_files(void); // compare the files
bool compare_file_diffs(void); // compare the files boolean wise

#endif // APPEND_REPO_HPP