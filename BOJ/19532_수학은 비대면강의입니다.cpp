#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	
	int y1 = (b * d) - (a * e);
	int y2 = (c * d) - (a * f);
	if (y1)
		y2 /= y1;

	int x1 = (a * e) - (b * d);
	int x2 = (c * e) - (b * f);
	if (x1)
		x2 /= x1;
	//adx + bdy = cd
	//adx + aey = af
	//bd - ae = cd - af

	//aex + bey = ce
	//bdx + bey = bf
	//ae - bd = ce - bf
	cout << x2 << " " << y2;
}