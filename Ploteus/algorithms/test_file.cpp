#include "file_reading.h"
#include "aproximation.h"

int main()
{

	vector<float> list_of_x;
	vector<float> list_of_y;
	int coord_count = 0;

	open_file_and_parse("test1.txt", list_of_x, list_of_y, coord_count);

	for (int i = 0; i < coord_count; i++){
		cout << list_of_x[i] << endl;
		cout << list_of_y[i] << endl;
	}

	vector<float> coefficient_of_linear_aproximation;

	coefficient_of_linear_aproximation = linear_aproximation(list_of_x, list_of_y);

	for (int i = 0; i < coefficient_of_linear_aproximation.size(); i++){
		cout << "This is coefficient of linear aproximation number " << i << " " << coefficient_of_linear_aproximation[i] << endl;
	}

	lagrange_points lagrange_points;

	lagrange_points = lagrange_poly_aproximation(list_of_x, list_of_y, 40);

    for (int i = 0; i < lagrange_points.x_coordinates.size(); i++)
	{
		cout << i << " Lagrange poly x coord - " << lagrange_points.x_coordinates[i] << " y coord - " << lagrange_points.y_coordinates[i] << endl;
	}

	system("pause");

}

