#include <iostream>

using namespace std;
bool paper[100][100] = {};

int main()
{
	int N = 0;
	int x, y;
	cin >> N;

	while (N--)
	{
		cin >> x >> y;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				paper[i + y][j + x] = true;
	}

	int cnt = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (paper[i][j])
				cnt++;	

	cout << cnt;
}