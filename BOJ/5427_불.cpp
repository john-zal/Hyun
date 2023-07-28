#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100000000

int StartHeight = 0;
int StartWidth = 0;

pair<int, int>GetDir(int num)
{
	switch (num)
	{
	case 0: //동
		return {0, 1};
	case 1://서
		return {0, -1};
	case 2://남
		return { 1, 0};
	case 3://북
		return{-1, 0};
	}
	return { 0, 0 };
}

void  BFSFire(vector<vector<int>>& vec, queue<pair<int, int>>& q)
{
	//불이 부딫히는 순간
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			auto dir = GetDir(i);
			int UD = dir.first + cur.first;
			int LR = dir.second + cur.second;

			if (UD < 0 || UD >= (int)vec.size() ||
				LR < 0 || LR >= (int)vec[0].size())
				continue;

			if (vec[UD][LR] == -1 || vec[UD][LR] > 0)
				continue;

			int count = vec[cur.first][cur.second] + 1;
		
			vec[UD][LR] = count;
			q.push({ UD, LR });
		}
	}
}

void BFSMan(vector<vector<int>>& vec)
{
	queue<pair<int, int>> q;

	q.push({ StartHeight, StartWidth });
	vec[StartHeight][StartWidth] = MAX+1;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			auto dir = GetDir(i);
			int UD = cur.first + dir.first;
			int LR = cur.second + dir.second;

			//탈출에 성공할 시
			if (UD < 0 || UD >= vec.size() ||
				LR < 0 || LR >= vec[0].size())
			{
				cout << vec[cur.first][cur.second] - MAX << endl;
				return;
			}
			
			int length = vec[cur.first][cur.second] + 1;

			// 벽이거나, 처음 불 붙은곳, 지나왔던곳
			if (vec[UD][LR] == -1 || vec[UD][LR] == 1 ||
				vec[UD][LR] > MAX ||
				((vec[UD][LR] != 0) && vec[UD][LR] <= (length - MAX)))
				continue;
					
			q.push({ UD, LR });
			vec[UD][LR] = length;
		}		
	}
	cout << "IMPOSSIBLE" << endl;
}
int main()
{
	int T, W, H;
	cin >> T;

	while(T--)
	{
		vector<vector<int>> vec = {};
		queue <pair<int, int>> q = {};

		cin >> W >> H;
		for (int i = 0; i < H; i++)
		{
			vector<int> column;
			for (int j = 0; j < W; j++)
			{
				char c;
				cin >> c;
				switch (c)
				{
				case '#':
					column.push_back(-1);
					break;
				case '.':
					column.push_back(0);
					break;
				case '*':
					q.push({ i, j });
					column.push_back(1);
					break;
				case '@':
					StartHeight = i;
					StartWidth = j;
					column.push_back(0);
					break;
				}
			}
			vec.push_back(column);
		}

		BFSFire(vec, q);
		BFSMan(vec);
	}
	return 0;
}