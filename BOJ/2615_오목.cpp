#include <iostream>
#include <utility>

using namespace std;

#define x first
#define y second

//★ 오목이면 가장자리 값을 출력하니 다른 방향은 필요가 없음
//우상, 우 ,우하, 하
//1시, 3시, 5시, 6시 방향만 보면 됨
pair<int, int> dir[] = { {-1, 1}, {0,1}, {1,1}, {1,0}};

int board[19][19];

int main() {

	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			cin >> board[i][j];

	int count = 0;
	bool omok = false;

	for (int i = 0; i < 19; i++)
	{
		if (omok)
			break;

		for (int j = 0; j < 19; j++)
		{
			//바둑알을 찾는다
			if (board[j][i] == 1 || board[j][i] == 2)
			{
				int stone = board[j][i];

				//사방 탐색
				for (int k = 0; k < 4; k++)
				{
					int curDir[] = { j, i };

					//뒤쪽 체크
					int check6X = j - dir[k].x;
					int check6Y = i - dir[k].y;

					if (check6X >= 0 && check6X < 19 && check6Y >= 0 && check6Y < 19)
					{
						if (board[check6X][check6Y] == stone)
							continue;
					}

					//오목 판정
					int count = 1;
					while (!omok)
					{
						int X = curDir[0] += dir[k].x;
						int Y = curDir[1] += dir[k].y;

						if (X >= 0 && X < 19 && Y >= 0 && Y < 19)
						{
							if (board[X][Y] == stone)
								count++;
							else
								break;
						}
						else
							break;
					}

					if (count == 5)
					{
						omok = true;
						cout << stone << '\n';
						cout << j + 1 << " " << i + 1;
						break;
					}					
				}
			}
		}
	}
	if (!omok)
		cout << 0 << '\n';
}