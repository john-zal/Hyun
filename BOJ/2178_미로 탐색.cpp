#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <queue>
#define VISITED 0;

pair<int, int> SetKey(int keynum)
{
	enum class EKey {
		up,
		down,
		left,
		right
	};

	EKey key = (EKey)keynum;
	pair<int, int> p;

	switch (key)
	{
	case EKey::up:
		p = { 1, 0 };
		break;
	case EKey::down:
		p = { -1, 0 };
		break;
	case EKey::left:
		p = { 0, -1 };
		break;
	case EKey::right:
		p = { 0, 1 };
		break;
	}
	return p;
}

int bfs(vector<vector<int>>& vec)
{
	int sizeI = (int)vec.size();
	int sizeJ = (int)vec[0].size();
	queue<pair<int, int>> q;
	vector<vector<int>> board;

	for (int i = 0; i < sizeI; i++)
	{
		vector<int> boardJ(sizeJ);
		board.push_back(boardJ);
	}

	q.push(make_pair(0, 0));
	vec[0][0] = VISITED;
	

	//bfs
	while (!q.empty())
	{	
		pair<int, int> cur = q.front();
		q.pop();

		//상하좌우 탐색
		for (int i = 0; i < 4; i++)
		{
			int num = board[cur.first][cur.second] + 1;
			pair<int, int> dir = SetKey(i);
			int UD = cur.first + dir.first; //상하
			int LR = cur.second + dir.second; //좌우
			//배열 넘어가는지 체크
			if (UD < 0 || UD >= sizeI ||
				LR < 0 || LR >= sizeJ)
				continue;

			//1이 아닐 시 패스
			if (vec[UD][LR] != 1)
				continue;

			//방문 표시 남김
			vec[UD][LR] = VISITED;
			board[UD][LR] = num;
			q.push({ UD, LR });
		}
	}

	return board[sizeI-1][sizeJ-1]+1;
}

int main()
{
	int answer = 0;
	int N, M = 0;
	
	cin >> N >> M;
	
	//배열 입력받기
	vector<vector<int>> vec;
	for (int i = 0; i < N; i++)
	{
		vector<int> vecJ;
		string s;
		cin >> s;
		for (int j = 0; j< M; j++)
			vecJ.push_back(stoi(s.substr(j, 1)));
		
		vec.push_back(vecJ);
	}

	answer = bfs(vec);
	cout << answer << endl;
	return 0;
}