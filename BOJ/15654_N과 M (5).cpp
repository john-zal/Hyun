#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vec;
int buffer[9];
int isUsed[9];

void Recursive(int num)
{
	if (num == M)
	{
		for (int i = 0; i < M; i++)
			cout << buffer[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!isUsed[i])
		{
			buffer[num] = vec[i];
			isUsed[i] = true;

			Recursive(num + 1);
			isUsed[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;
	
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	Recursive(0);
}