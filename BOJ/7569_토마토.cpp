#include <iostream>
#include <vector>
#include <queue>
#define VISITED true;
using namespace std;

struct Vector3
{
	int floor;
	int height;
	int width;
};

Vector3 GetDir(int num)
{
	switch (num)
	{
	case 0: //위
		return { 1, 0, 0 };
	case 1: //아래
		return { -1, 0, 0 };
	case 2: // 뒤(상)
		return { 0, -1, 0 };
	case 3: // 앞(하)
		return { 0, 1, 0 };
	case 4: //좌
		return { 0, 0, -1 };
	case 5: //우
		return { 0, 0, 1 };
	}
	return { 0, 0, 0 };
}

int BFS(vector<vector<vector<int>>>& v, vector<vector<vector<bool>>>& board, queue<Vector3>& q)
{
	int day = 0;
	board[q.front().floor][q.front().height][q.front().width] = VISITED;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			Vector3 dir = GetDir(i);

			int UD = dir.floor + cur.floor;
			int FB = dir.height + cur.height;
			int LR = dir.width + cur.width;

			if (UD < 0 || UD >= v.size() ||
				FB < 0 || FB >= v[0].size() ||
				LR < 0 || LR >= v[0][0].size())
				continue;

			if (board[UD][FB][LR] == true)
				continue;

			int boardCount = v[cur.floor][cur.height][cur.width] + 1;
			v[UD][FB][LR] = boardCount;
			board[UD][FB][LR] = true;
			q.push({ UD, FB, LR });

			if (boardCount > day)
				day = boardCount;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			for (int k = 0; k < v[0][0].size(); k++)
			{
				if (v[i][j][k] == 0)
					return -1;
			}
		}
	}

	if (day > 1)
		day -= 1;

	return day;
}

int main()
{
	//3차원 공간에서 토마토
	//상하좌우앞뒤
	int M, N, H;
	cin >> M >> N >> H;
	vector<vector<vector<int>>> vec;
	vector<vector<vector<bool>>> vecBoard;
	
	queue<Vector3> q;

	for (int i = 0; i < H; i++) //층
	{
		vector<vector<int>> row;
		vector<vector<bool>> boardRow;

		for (int j = 0; j < N; j++) //행
		{
			vector<int> column;
			vector<bool> boardColumn;

			for (int k = 0; k < M; k++)//열
			{
				int num;
				cin >> num;
				column.push_back(num);
				boardColumn.push_back(false);
				if (num == 1)
				{
					Vector3 xyz;
					xyz.floor = i;
					xyz.height = j;
					xyz.width = k;
					q.push(xyz);
					boardColumn[k] = true;
				}
				else if (num == -1)
					boardColumn[k] = true;
			}
			row.push_back(column);
			boardRow.push_back(boardColumn);
		}
		vec.push_back(row);
		vecBoard.push_back(boardRow);
	}

	cout << BFS(vec, vecBoard, q) << endl;

	return 0;
}
