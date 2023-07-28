#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N = 0;
int K = 0;

int Move(int num, int index)
{
	switch (num)
	{
	case 0: // back
		return index - 1;
	case 1: // forward
		return index + 1;
	case 2:// jump
		return index * 2;
	}
	return 0;
}

int BFS(vector<int>& v)
{
	queue<int> q;

	//ÁÂ, ¿ì¸¸ ÆÇ´Ü
	q.push(N);
	v[N] = 0;

	while (!q.empty())
	{
		int index = q.front();
		q.pop();
		
		//-1Ä­, +1Ä­, x2Ä­
		for (int i = 0; i < 3; i++)
		{
			int checkIndex = Move(i, index);
			//ÀÎµ¦½º°¡ 0 ÀÌÇÏ°Å³ª ÀÌ¹Ì´Ù¸¥ ¼ýÀÚ
			if (checkIndex < 0 || checkIndex > 100000)
				continue;
			if (v[checkIndex] > -1)
				continue;

			q.push(checkIndex);
			v[checkIndex] = v[index] + 1;
		}

		if (v[K] != -1)
			break;
	}
	return v[K];
}
int main()
{
	cin >> N >> K;

	vector<int> board(100002);
	fill(board.begin(), board.end(), -1);
	
	cout << BFS(board) << endl;
	return 0;
}