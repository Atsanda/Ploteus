#include "file_reading.h"
#include "aproximator.h"


int open_file_and_parse(const char* FILE_NAME, QVector<float> &list_of_x, QVector<float> &list_of_y, int &coord_count){

    ifstream fin;


	fin.open(FILE_NAME);

    if(!fin.good())
    {
        throw QString("Invalid filename,please try again");
    }

	float buff_num = 0.0;

    while (!fin.eof()){
        fin >> buff_num;
        if(fin.fail()){
            fin.close();
            throw QString("Invalid file format");
        }
        list_of_x.push_back(buff_num);


        fin >> buff_num;
        if(fin.fail()){
            fin.close();
            throw QString("Invalid file format");
        }
        list_of_y.push_back(buff_num);
        coord_count++;

	}

	fin.close();

	return 0;

}
