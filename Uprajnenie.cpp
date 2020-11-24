

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	const float e = 10e-8;
	double x1, y1, x2, y2;
	double n, f, s;
	 
	ifstream inputfile("input.txt");
	inputfile >> x1;
	inputfile >> y1;
	inputfile >> x2;
	inputfile >> y2;
	cout << "Координаты первой точки: " << x1 << " " << y1 << endl;
	cout << "Координаты второй точки: " << x2 << " " << y2 << endl;
	n = abs((y2 * x1 - x2 * y1) / sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
	f = sqrt(pow(x1, 2) + pow(y1, 2));
	s = sqrt(pow(x2, 2) + pow(y2, 2));
	int peresechenia = 0;
	if (x1 != x2 or y1 != y2)
	{
		if ((2 * x1 * x1 - 2 * x1 * x2 + 2 * y1 * y1 - 2 * y1 * y2 < 0) or (2 * x2 * x2 - 2 * x1 * x2 + 2 * y2 * y2 - 2 * y1 * y2 < 0))
		{
			peresechenia = (int)(max(f, s) + e) - (int)(min(f, s) - e);
		}
		else
		{
			peresechenia = (int)(f + e) - (int)(n - e);
			peresechenia = peresechenia + (int)(s + e) - (int)(n - e);
			if ((abs(round(n) - n) < e) and (abs(n) > e))
			{
				peresechenia--;
			}
		}
	}
	else
	{
		peresechenia = 0;
	}
	cout << "Количесвто пересечений: " << peresechenia;

	ofstream outputfile("output.txt");
	outputfile << peresechenia;
	outputfile.close();
	return 0;
}


