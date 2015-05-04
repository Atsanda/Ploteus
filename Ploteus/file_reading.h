#include <iostream>
#include <fstream>
#include <string>
//#include <malloc.h>
#include <vector>
//#include <conio.h>
#include <iomanip>
#include <aproximator.h>
using namespace std;

int open_file_and_parse(const char* FILE_NAME, QVector<float> &list_of_x, QVector<float> &list_of_y, int &coord_count);
