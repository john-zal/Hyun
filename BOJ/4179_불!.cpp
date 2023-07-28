#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
pair<int, int> J;
vector<pair<int, int>> F;

pair<int, int> CheckDir(int num)
{
	switch (num)
	{
	case 0: //동
		return { 0, 1 };
	case 1://서
		return { 0, -1 };
	case 2://남
		return { 1, 0 };
	case 3://북
		return{ -1, 0 };
	}
	return { 0, 0 };
}


void BFSFire(vector<vector<int>>& vec)
{
	//불은 여러 개 주어질 수 있음
	queue<pair<int, int>> q;
	int width = (int)vec[0].size();
	int height = (int)vec.size();

	//시작지점 방문
	for (int i = 0; i < F.size(); i++)
	{
		q.push(F[i]);
		vec[F[i].first][F[i].second] = 1;
	}
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			//첫 시작점을 1로 해두었다. 주변 칸들은 1+n.
			int	length = vec[cur.first][cur.second] + 1;

			pair<int, int> dir = CheckDir(i);
			int UD = cur.first + dir.first;
			int LR = cur.second + dir.second;

			if (UD < 0 || UD >= height ||
				LR < 0 || LR >= width)
				continue;

			//-1이면 벽이고 0보다 크면 지나갔다는 소리
			if (vec[UD][LR] == -1 || vec[UD][LR] > 0)
				continue;

			vec[UD][LR] = length;
			q.push({ UD, LR });
		}
	}
}

int BFSJ(vector<vector<int>>& board)
{
	////불이 지나간 시간을 기점으로  체크
	queue<pair<int, int>> q;
	int width = (int)board[0].size();
	int height = (int)board.size();

	q.push(J);
	board[J.first][J.second] = 10001;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> dir = CheckDir(i);
			int UD = dir.first + cur.first;
			int LR = dir.second + cur.second;

			//얘는 빠져나가면 끝
			if (UD < 0 || UD >= height ||
				LR < 0 || LR >= width)
				return board[cur.first][cur.second] - 10000;

			int boardLength = board[cur.first][cur.second] + 1;

			//못가는 지점 체크 벽이거나 (현재 불이 붙은 곳)
			if (board[UD][LR] == -1 || board[UD][LR] == 1 || board[UD][LR] > 10000 ||
				((board[UD][LR] != 0) && (board[UD][LR] <= boardLength - 10000)))
				continue;

			q.push({ UD, LR });
			board[UD][LR] = boardLength;
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int R, C;
	cin >> R >> C;

	vector<vector<int>> board;

	//배열 등록
	for (int i = 0; i < R; i++)
	{
		string s;
		cin >> s;
		vector<int> boardColumn(C);

		for (int j = 0; j < C; j++)
		{
			if (s[j] == '#')
				boardColumn[j] = -1;
			else if (s[j] == 'F')
				F.push_back({ i, j });
			else if (s[j] == 'J')
				J = { i, j };
		}
		board.push_back(boardColumn);
	}

	BFSFire(board);

	int answer = BFSJ(board);

	if (answer == -1)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << answer << endl;

	return 0;
}