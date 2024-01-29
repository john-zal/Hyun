#include <iostream>
#include <utility>

using namespace std;

#define x first
#define y second

//�� �����̸� �����ڸ� ���� ����ϴ� �ٸ� ������ �ʿ䰡 ����
//���, �� ,����, ��
//1��, 3��, 5��, 6�� ���⸸ ���� ��
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
			//�ٵϾ��� ã�´�
			if (board[j][i] == 1 || board[j][i] == 2)
			{
				int stone = board[j][i];

				//��� Ž��
				for (int k = 0; k < 4; k++)
				{
					int curDir[] = { j, i };

					//���� üũ
					int check6X = j - dir[k].x;
					int check6Y = i - dir[k].y;

					if (check6X >= 0 && check6X < 19 && check6Y >= 0 && check6Y < 19)
					{
						if (board[check6X][check6Y] == stone)
							continue;
					}

					//���� ����
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