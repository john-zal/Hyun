#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vec;
int buf[8];

void Recursive(int num)
{
	if (num == M)
	{
		for (int i = 0; i < M; i++)
			cout << buf[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++)
	{
		buf[num] = vec[i];
		
		Recursive(num + 1);
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