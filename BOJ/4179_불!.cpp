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
	case 0: //��
		return { 0, 1 };
	case 1://��
		return { 0, -1 };
	case 2://��
		return { 1, 0 };
	case 3://��
		return{ -1, 0 };
	}
	return { 0, 0 };
}


void BFSFire(vector<vector<int>>& vec)
{
	//���� ���� �� �־��� �� ����
	queue<pair<int, int>> q;
	int width = (int)vec[0].size();
	int height = (int)vec.size();

	//�������� �湮
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
			//ù �������� 1�� �صξ���. �ֺ� ĭ���� 1+n.
			int	length = vec[cur.first][cur.second] + 1;

			pair<int, int> dir = CheckDir(i);
			int UD = cur.first + dir.first;
			int LR = cur.second + dir.second;

			if (UD < 0 || UD >= height ||
				LR < 0 || LR >= width)
				continue;

			//-1�̸� ���̰� 0���� ũ�� �������ٴ� �Ҹ�
			if (vec[UD][LR] == -1 || vec[UD][LR] > 0)
				continue;

			vec[UD][LR] = length;
			q.push({ UD, LR });
		}
	}
}

int BFSJ(vector<vector<int>>& board)
{
	////���� ������ �ð��� ��������  üũ
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

			//��� ���������� ��
			if (UD < 0 || UD >= height ||
				LR < 0 || LR >= width)
				return board[cur.first][cur.second] - 10000;

			int boardLength = board[cur.first][cur.second] + 1;

			//������ ���� üũ ���̰ų� (���� ���� ���� ��)
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

	//�迭 ���
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