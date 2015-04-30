#include "file_reading.h"

int open_file_and_parse(const char* FILE_NAME, vector<float> &list_of_x, vector<float> &list_of_y, int &coord_count){
	ifstream fin;
	fin.open(FILE_NAME);

	float buff_num = 0.0;

	while (!fin.eof()){
		fin >> buff_num;
		list_of_x.push_back(buff_num);

		fin >> buff_num;
		list_of_y.push_back(buff_num);

		coord_count++;
	}

	fin.close();

	return 0;

}
