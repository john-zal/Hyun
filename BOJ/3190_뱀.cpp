#include <iostream>
#include <queue>
#include <deque>
#include <utility>
#define APPLE 2;
using namespace std;

/*
��
���� �ʱ� ���̴� 1�̰� ������ ó���� �������̴�.

#��Ģ
	- ���� �̵��� �� �Ӹ��� ���� ĭ���� �̵���Ų��.
	- ���̳� �ڽ��� ���� �΋H���� ������ ������.
	- ����� �ִٸ� ������ �������� ������. (�� ĭ �þ��.)

	# �� ó�� ���� ��ܿ��� ���� �־����� �̰����� ����� ����.

	15 D,�� 15�� �ڿ� ���������� 90�� �̵��Ѵٴ� ��

*/

int board[101][101];
queue<pair<int, char>> q;
int N;
int answer = 0;

class Snake
{
public:
	Snake()
	{
		snake.push_back({ 0, 0 });
		dir = { 0, 1 };
	};
	~Snake() {};

	deque<pair<int, int>> snake;
	pair<int, int> dir;

	pair<int, int> GetHead()
	{
		return snake.front();
	}

	pair<int, int> GetTail()
	{
		return snake.back();
	}

	bool CheckCollision(int x, int y)
	{
		for (pair<int, int> p : snake)
			if (p.first == x && p.second == y)
				return true;

		return false;
	}

	void Move(bool isApple)
	{
		int x = snake.front().first + dir.first;
		int y = snake.front().second + dir.second;
		snake.push_front({ x, y });

		if (!isApple)
			snake.pop_back();
	}

	void ChangeDir(char rot)
	{
		int x = dir.first;
		int y = dir.second;

		if (x == -1 && y == 0) //��
			rot == 'L' ? dir = { 0, -1 } : dir = { 0, 1 };
		else if (x == 1 && y == 0) //��
			rot == 'L' ? dir = { 0, 1 } : dir = { 0, -1 };  //���� , ������
		else if (x == 0 && y == -1) //��
			rot == 'L' ? dir = { 1, 0 } : dir = { -1, 0 };
		else if (x == 0 && y == 1) //��
			rot == 'L' ? dir = { -1, 0 } : dir = { 1, 0 };
	}
};

bool isWall(int x, int y)
{
	return x < 0 || x >= N || y < 0 || y >= N;
}

int GameStart()
{
	Snake* s = new Snake();

	while (true)
	{
		//####DEBUG
		//cout << answer << "��" << '\n';
		//char cboard[101][101] = {};
		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//	{
		//		cboard[i][j] = (board[i][j] == 0 ? 'X' : 'O');
		//	}
		//}

		//for (auto p : s->snake)
		//	cboard[p.first][p.second] = 'S';

		//for (int i = 0; i < N; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//		cout << cboard[i][j];

		//	cout << '\n';
		//}
		//cout << '\n';

		//######

		//�� ����
		answer++;

		int x = s->GetHead().first + s->dir.first;
		int y = s->GetHead().second + s->dir.second;

		if (isWall(x, y))
			break;
		if (s->CheckCollision(x, y))
			break;

		//��� ������ ����
		bool isApple = board[x][y] == 2;
		if (isApple)
			board[x][y] = 0;
		s->Move(isApple);

		if (!q.empty())
		{
			int moveTime = q.front().first;

			//�ش� �ð��� �Ǹ� ������ ��ȯ�Ѵ�.
			if (answer == moveTime)
			{
				s->ChangeDir(q.front().second);
				q.pop();
			}
		}
	}

	delete(s);
	return answer;
}

int main()
{
	int K, L;
	cin >> N >> K;
	while (K--)
	{
		int posX, posY;
		cin >> posX >> posY;

		//������ 1,1�� �������� ������
		//0,0�迭�������� �ۼ��߱⿡ 1 ���ֱ�
		board[posX - 1][posY - 1] = APPLE;
	}

	cin >> L;
	while (L--)
	{
		int time;
		char rot;

		cin >> time >> rot;
		q.push({ time, rot });
	}
	cout << GameStart();
}