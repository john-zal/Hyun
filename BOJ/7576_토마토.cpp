#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <queue>
#define VISITED 1
vector<pair<int, int>> STARTPAIR;
pair<int, int> SetKey(int num)
{
	pair<int, int> p;
	enum class EKey {
		up,
		down,
		left,
		right
	};

	EKey key = (EKey)num;
	switch (key)
	{
	case EKey::up:
		p = { -1, 0 };
		break;
	case EKey::down:
		p = { 1, 0 };
		break;
	case EKey::left:
		p = { 0, -1 };
		break;
	case EKey::right:
		p = { 0, 1 };
		break;
	default:
		break;
	}
	return p;
}

int BFS(vector<vector<int>>& vec)
{
	int day = 0;
	int height = vec.size();
	int width = vec[0].size();
	queue<pair<int, int>> q;
	vector<vector<int>> board;
	
	//거리보드 생성
	for (int i = 0; i < height; i++)
	{
		vector<int> boardJ(width);
		board.push_back(boardJ);
	}
	
	//처음 1인 위치 등록
	for (int i = 0; i < STARTPAIR.size(); i++)
	{
		q.push(STARTPAIR[i]);
		//board[STARTPAIR[i].first][STARTPAIR[i].second] = 1;
		vec[STARTPAIR[i].first][STARTPAIR[i].second] = VISITED;
	}
		

	while (!q.empty())
	{
		//현재 커서
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{	
			int boardCount = board[cur.first][cur.second] + 1;

			pair<int, int> dir = SetKey(i);
			int UD = cur.first + dir.first; //상하
			int LR = cur.second + dir.second;//좌우

			if (UD < 0 || UD >= height ||
				LR < 0 || LR >= width)
				continue;

			if (vec[UD][LR] == 1 || vec[UD][LR] == -1)
				continue;

			vec[UD][LR] = VISITED;
			board[UD][LR] = boardCount;

			if (day < boardCount)
				day = boardCount;

			q.push({ UD, LR });

		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[0].size(); j++)
		{
			if (vec[i][j] == 0)
			{
				day = -1;
				break;
			}		
		}
	}

	return day;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> vec;

	//입력받기
	for (int i = 0; i < M; i++)
	{
		vector<int> vecJ;
		for (int j = 0; j < N; j++)
		{
			int num = 0;
			cin >> num;
			if (num == 1)
				STARTPAIR.push_back({ i, j });

			vecJ.push_back(num);
		}
		vec.push_back(vecJ);
	}

	cout << BFS(vec) << endl;
	

	return 0;
}