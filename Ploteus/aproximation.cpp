#include "aproximation.h"

vector<float> linear_aproximation(vector<float> list_of_x, vector<float> list_of_y){
	float sum_x = 0.0;
	float sum_y = 0.0;
	float sum_xy = 0.0;
	float sum_xx = 0.0;

	int n = list_of_x.size();

	vector<float> coefficient_of_linear_aproximation;

	for (vector<float>::iterator iter = list_of_x.begin(); iter != list_of_x.end(); iter++)
	{
		sum_x = sum_x + *iter;
	}

	for (vector<float>::iterator iter = list_of_y.begin(); iter != list_of_y.end(); iter++)
	{
		sum_y = sum_y + *iter;
	}

	for (vector<float>::iterator iter = list_of_x.begin(); iter != list_of_x.end(); iter++)
	{
		sum_xx = sum_xx + *iter*(*iter);
	}

	for (int i = 0; i < list_of_x.size(); i++)
	{
		sum_xy = sum_xy + list_of_x[i] * list_of_y[i];
	}

	coefficient_of_linear_aproximation.push_back((n*sum_xy - sum_x*sum_y) / (n*sum_xx - sum_x*sum_x));
	coefficient_of_linear_aproximation.push_back((sum_y - coefficient_of_linear_aproximation[0] * sum_x) / float(n));

	return coefficient_of_linear_aproximation;

}

lagrange_points lagrange_poly_aproximation(vector<float> list_of_x, vector<float> list_of_y, int num_of_points){
	
	//if (num_of_points > (list_of_x.size() + 1)*list_of_y.size())
	{
		printf("Ne polyschinsya \n");
	}

	float start = list_of_x[0];
	float end = list_of_x[list_of_x.size() - 1];

	lagrange_points lagrange_points;

	float DELTA = (end - start)/num_of_points;

	for (double x = start; x <= end; x += DELTA)
	{
		float y = 0.0;

		for (int i = 0; i < list_of_x.size(); i++)
		{
			float P = 1.0;

			for (int j = 0; j < list_of_x.size(); j++)
			{
				if (i != j)
					P *= (x - list_of_x[j]) / (list_of_x[i] - list_of_x[j]);
			}
			y += list_of_y[i] * P;
		}
		lagrange_points.x_coordinates.push_back(x);
		lagrange_points.y_coordinates.push_back(y);
	}
			
	return lagrange_points;

}

