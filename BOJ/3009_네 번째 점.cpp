#include <iostream>
#include <vector>
using namespace std;


bool check(vector<int>& v, int num)
{
	bool check = false;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == num)
		{
			v[i] = 0;
			check = true;
			break;
		}		
	}	
	return check;
}

int main()
{
	vector<int> x;
	vector<int> y;

	for (int i = 0; i < 3; i++)
	{
		int tempX, tempY;
		cin >> tempX;
		if(!check(x, tempX))
			x.push_back(tempX);

		cin >> tempY;
		if (!check(y, tempY))
			y.push_back(tempY);
	}

	int answerX = 0;
	int answerY = 0;

	for (int i = 0; i < x.size(); i++)
	{
		answerX += x[i];
		answerY += y[i];
	}

	cout << answerX << ' ' << answerY;

}