#include <iostream>

#include <queue>
#include <vector>
#include <string>

using namespace std;

pair<int, int>GetDir(int num)
{
	switch (num)
	{
	case 0 :
		return { -1, 0 };
	case 1 :
		return { 1, 0 };
	case 2 :
		return { 0, -1 };
	case 3 :
		return { 0, 1 };
	}
	return { 0, 0 };
}

int BFS(vector<string>& v)
{
	enum class ERGB {
		None,
		Red,
		Green,
		Blue
	};

	int board[100][100] = { 0 };
	int result = 0;

	for (int i = 0; i < (int)v.size(); i++)
	{
		for (int j = 0; j < (int)v[0].size(); j++)
		{
			if (board[i][j] == 0)
			{
				//bfs
				ERGB RGB = ERGB::None;
				char c;
				queue<pair<int, int>> q;
				q.push({ i, j });				
				switch (v[i][j])
				{
				case 'R':
					RGB = ERGB::Red;
					c = 'R';
					break;
				case 'G':
					RGB = ERGB::Green;
					c = 'G';
					break;
				case 'B':
					RGB = ERGB::Blue;
					c = 'B';
					break;
				}
				board[i][j] = (int)RGB;

				if(RGB != ERGB::None)
					result += 1;

				//BFS Ω√¿€
				while (!q.empty())
				{
					auto cur = q.front();
					q.pop();

					for (int i = 0; i < 4; i++)
					{
						auto dir = GetDir(i);
						int UD = dir.first + cur.first;
						int LR = dir.second + cur.second;

						if (UD < 0 || UD >= v.size() ||
							LR < 0 || LR >= v.size())
							continue;

						if (board[UD][LR] > 0 || v[UD][LR] != c)
							continue;

						board[UD][LR] = (int)RGB;
						q.push({ UD, LR });
					}
				}
			}
		}
	}
	return result;
}
int main()
{	
	int N;
	vector<string> vec;
	vector<string> vec2;
	cin >> N;
	while (N--)
	{
		string s;
		cin >> s;
		string s2 = s;
		for (int i = 0; i < s2.size(); i++)
		{
			if (s2[i] == 'G')
				s2[i] = 'R';
		}
		vec.push_back(s);
		vec2.push_back(s2);
	}
	
	cout << BFS(vec) << " " << BFS(vec2) << endl;

	return 0;
}