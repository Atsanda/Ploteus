#include <iostream>
#include <fstream>
#include <string>
//#include <malloc.h>
#include <vector>
//#include <conio.h>
#include <iomanip>

using namespace std;

int open_file_and_parse(const char* FILE_NAME, vector<float> &list_of_x, vector<float> &list_of_y, int &coord_count);