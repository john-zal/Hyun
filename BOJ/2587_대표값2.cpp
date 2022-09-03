#include <bits/stdc++.h>
using namespace std;

int main() 
{
	//Æò±Õ°ú Áß¾Ó°ª ±¸ÇÏ±â
	vector<int> nums;
	int num[5] = {};
	int avg = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> num[i];
		avg += num[i];
	}

	avg /= 5;
	sort(num, num+5);

	cout << avg << endl;
	cout << num[2] << endl;

	return 0;
}