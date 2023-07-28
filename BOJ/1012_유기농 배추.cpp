#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//bool board[50][50] = { false };

pair<int, int> CheckDir(int num)
{
	//»óÇÏÁÂ¿ì
	switch (num)
	{
	case 0:
		return { -1, 0 };
	case 1:
		return { 1, 0 };
	case 2:
		return { 0, -1 };
	case 3:
		return { 0, 1 };
	}
	return { 0, 0 };
}

void BFS(vector<vector<int>>& v, int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	//board[x][y] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			auto dir = CheckDir(i);

			int UD = cur.first + dir.first;
			int LR = cur.second + dir.second;

			if (UD < 0 || UD >= v.size() ||
				LR < 0 || LR >= v[0].size())
				continue;

			if (v[UD][LR] != -1)
				continue;

			v[UD][LR] = 1;
			q.push({ UD, LR });
		}		
	}	
}

int main()
{
	int T, M, N, K;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N;
		vector<vector<int>> vec;
		

		for (int j = 0; j < N; j++)
		{
			vector<int> column(M);
			vec.push_back(column);
		}
		queue<pair<int, int>> q;
		
		//ÁÂÇ¥ ÀÔ·Â
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			int x, y;
			cin >> y >> x;
			vec[x][y] = -1;
			q.push({ x, y });
		}
		
		int answer = 0;

		while (!q.empty())
		{
			auto cur = q.front();
			if (vec[cur.first][cur.second] == -1)
			{
				BFS(vec, cur.first, cur.second);
				answer += 1;
			}
			q.pop();
		}

		cout << answer << endl;
	}
	return 0;
}