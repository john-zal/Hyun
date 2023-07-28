#include <iostream>

using namespace std;

int arr[2187][2187]; // 3^7
int answer[3];

bool CheckRect(int n, int x, int y)
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (arr[x][y] != arr[i][j])
				return false;
	
	return true;
}

void ReCUTsive(int n, int x, int y)
{
	if (CheckRect(n, x, y))
	{
		//공통조건 : 정사각형일 시 빠져나온다
		answer[arr[x][y]+1]++;
		return;
	}

	//9번 재귀
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			ReCUTsive(n / 3, x + i * (n / 3), y + j * (n / 3));
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	ReCUTsive(N, 0, 0);

	for (int i = 0; i < 3; i++)
		cout << answer[i] << '\n';

	return 0;
}