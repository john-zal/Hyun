#include <iostream>
#include <queue>
using namespace std;
#define VISIT true
int DestHeight = 0;
int DestWidth = 0;

pair<int, int> GetDir(int num)
{
	switch (num)
	{
	case 0: //»óÁÂ
		return {-2, -1};
	case 1: //»ó¿ì
		return { -2, 1};
	case 2: //ÇÏÁÂ
		return {2, -1};
	case 3: //ÇÏ¿ì
		return {2, 1};
	case 4: //ÁÂ»ó
		return {-1, -2};
	case 5: //ÁÂÇÏ
		return {1, -2};
	case 6: //¿ì»ó
		return {-1, 2};
	case 7: //¿ìÇÏ
		return {1, 2};

	}
	return { 0, 0 };
}

int BFS(vector<vector<int>>& v, queue<pair<int, int>>& q)
{
	//½ÃÀÛÁöÁ¡ÀÌ¶û Á¾ÂøÁö¶û °°À¸¸é
	if (q.front().first == DestHeight && q.front().second == DestWidth)
		return 0;

	vector<vector<bool>> board;
	for (int i = 0; i < v.size(); i++)
	{
		vector<bool> column(v.size());
		board.push_back(column);
	}

	board[q.front().first][q.front().second] = VISIT;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			auto dir = GetDir(i);
			int height = dir.first + cur.first;
			int width = dir.second + cur.second;

			if (height < 0 || height >= v.size() ||
				width < 0 || width >= v.size())
				continue;

			if (board[height][width] == VISIT)
				continue;
				
			int boardCount = v[cur.first][cur.second] + 1;
			v[height][width] = boardCount;
			board[height][width] = VISIT;
			q.push({ height, width });

			if (height == DestHeight && width == DestWidth)
				return boardCount;
		}

	}
	return v[DestHeight][DestWidth];
}

int main()
{
	int T, I;

	cin >> T;
	while (T--)
	{
		cin >> I;
		queue<pair<int, int>> q;
		vector<vector<int>> board;
		for (int i = 0; i < I; i++)
		{
			vector<int> column(I);
			board.push_back(column);
		}

		int StartX, StartY;
		cin >> StartX >> StartY;
		q.push({StartX, StartY});

		cin >> DestHeight >> DestWidth;
		cout << BFS(board, q) << '\n';
	}

	return 0;
}