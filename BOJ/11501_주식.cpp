#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<int> vec(N);
		while (N--)
			cin >> vec[N];

		int max = -1;
		long long benefit = 0;

		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] > max)
				max = vec[i];
			else
				benefit += max - vec[i];
		}

		cout << benefit << endl;
	}
}