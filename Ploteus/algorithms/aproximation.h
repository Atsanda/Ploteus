#include <iostream>
#include <fstream>
#include <string>
//#include <malloc.h>
#include <vector>

using namespace std;

struct lagrange_points{
	vector<float> x_coordinates;
	vector<float> y_coordinates;
};
typedef struct lagrange_points lagrange_points;

vector<float> linear_aproximation(vector<float> list_of_x, vector<float> list_of_y);

lagrange_points lagrange_poly_aproximation(vector<float> list_of_x, vector<float> list_of_y, int num_of_points);
