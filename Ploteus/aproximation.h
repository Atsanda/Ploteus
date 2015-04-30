#include <iostream>
#include <fstream>
#include <string>
//#include <malloc.h>
#include <vector>
#include "aproximator.h"

using namespace std;

struct lagrange_points{
	vector<float> x_coordinates;
	vector<float> y_coordinates;
};
typedef struct lagrange_points lagrange_points;

QVector<float> linear_aproximation(QVector<float> list_of_x, QVector<float> list_of_y);

lagrange_points lagrange_poly_aproximation(QVector<float> list_of_x, QVector<float> list_of_y, int num_of_points);
