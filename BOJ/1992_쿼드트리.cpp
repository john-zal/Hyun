#include <iostream>
#include <string>
using namespace std;

int arr[64][64];
string answer = "";

bool CheckRect(int n, int x, int y)
{
	for (int i = x; i < n+x; i++)
		for (int j = y; j < n+y; j++)
			if (arr[x][y] != arr[i][j])
				return false;

	return true;
}

void QuadTree(int n, int x, int y)
{
	if (CheckRect(n, x, y))
		answer += to_string(arr[x][y]);
	else
	{
		answer += '(';
		QuadTree(n / 2, x + 0 * n / 2, y + 0 * n / 2);
		QuadTree(n / 2, x + 0 * n / 2, y + 1 * n / 2);
		QuadTree(n / 2, x + 1 * n / 2, y + 0 * n / 2);
		QuadTree(n / 2, x + 1 * n / 2, y + 1 * n / 2);
		answer += ')';
	}	
}

int main()
{
	int N;

	cin >> N;
	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < N; j++)
			arr[i][j] = s[j] - '0';
	}

	QuadTree(N, 0, 0);
	cout << answer << '\n';
}