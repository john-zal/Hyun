#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vec;
int buf[9];

void Recursive(int num, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << buf[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = num; i <= N; i++)
	{
		buf[cnt] = vec[i-1];
		
		Recursive(i, cnt + 1);
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

	Recursive(1, 0);
}