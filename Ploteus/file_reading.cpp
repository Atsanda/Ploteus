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

    for(int i = 0; i<list_of_x.size(); i++)
    {
        cout << list_of_x[i] << endl;
        cout << list_of_y[i] << endl;
    }

	fin.close();

	return 0;

}
