#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

bool compare(int i, int j)
{
	return j > i;
}

pair<int, int> CheckDir(int num)
{
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

void BFS(vector<string>& v, int x, int y, vector<int>& answer)
{
	queue<pair<int, int>> q;
	int sum = 0;
	q.push({ x, y });
	sum += v[x][y] - '0';
	v[x][y] = 'X';

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			auto dir = CheckDir(i);

			int UD = cur.first + dir.first;
			int LR = cur.second + dir.second;

			//빠져나올 시
			if (UD < 0 || UD >= v.size() ||
				LR < 0 || LR >= v[0].size())
				continue;

			if (v[UD][LR] == 'X')
				continue;

			sum += v[UD][LR] - '0';

			v[UD][LR] = 'X'; // x로 바꿔주기
			q.push({ UD, LR });
		}
	}
	answer.push_back(sum);
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
	bool check = false;
	for (int i = 0; i < maps.size(); i++)
	{
		for (int j = 0; j < maps[0].size(); j++)
		{
			if (maps[i][j] != 'X')
				BFS(maps, i, j, answer);
		}
	}

	if (answer.empty())
		answer.push_back(-1);

	sort(answer.begin(), answer.end(), compare);
    return answer;
}

int main()
{
	vector<string> maps = { "X591X","X1X5X","X231X", "1XXX1" };
	vector<int> answer = solution(maps);

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
}