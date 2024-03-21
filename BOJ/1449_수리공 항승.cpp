#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;

	int N, L;
	cin >> N >> L;
	int num;
	bool check[1001] = {};
	int maxPipe = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vec.push_back(num);
		check[num] = true;

		if (maxPipe < num)
			maxPipe = num;
	}

	//solution
	int useTape = 0;

	for (int i = 0; i <= maxPipe; i++)
	{
		if (check[i])
		{
			for (int j = i; j < i+L; j++)
				check[j] = false;
			
			i += L - 1;
			useTape++;
		}
	}
	cout << useTape;
}