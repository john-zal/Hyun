#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

char chess1[8][8];
char chess2[8][8];

char Reverse(char c)
{
	return c == 'B' ? 'W' : 'B';
}

int compare(vector<vector<char>> vec, int x, int y)
{
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = x; i < x+8; i++)
	{
		for (int j = y; j < y+8; j++)
		{
			if (vec[i][j] != chess1[i - x][j - y])
				cnt1++;
			if (vec[i][j] != chess2[i - x][j - y])
				cnt2++;
		}
	}
	return min(cnt1, cnt2);
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<char>> vec;

	int answer = 2147483647;

	for (int i = 0; i < N; i++)
	{
		vector<char> vec2(M);
		for (int j = 0; j < M; j++)
			cin >> vec2[j];

		vec.push_back(vec2);
	}

	char start1 = 'B';
	char start2 = 'W';
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			chess1[i][j] = start1;
			chess2[i][j] = start2;			
			start1 = Reverse(start1);
			start2 = Reverse(start2);
		}
		start1 = Reverse(start1);
		start2 = Reverse(start2);
	}

	for (int i = 0; i <= N-8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			int mins = compare(vec, i, j);

			answer = min(mins , answer);
		}
	}
	cout << answer;
}