#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int sudoku[9][9] = {};
		bool checkArr[9] = { false };

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				cin >> sudoku[i][j];
			
	//가로검증
		bool checkFail = false;

		for (int i = 0; i < 9; i++)
		{
			int sum = 0;
			for (int j = 0; j < 9; j++)
				sum += sudoku[i][j];

			if (sum != 45)
				checkFail = true;
		}

	//세로검증
		if (!checkFail)
		{
			for (int i = 0; i < 9; i++)
			{
				int sum = 0;
				for (int j = 0; j < 9; j++)
					sum += sudoku[j][i];

				if (sum != 45)
					checkFail = true;
			}
		}
	//3x3검증
		if (!checkFail)
		{
			for (int i = 0; i < 9; i++)
			{
				int sum = 0;
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						int calcNum = sudoku[j + (3 * (i % 3))][k + (3 * (i / 3))];
						sum += calcNum;
					}
				}
				if (sum != 45)
					checkFail = true;
			}
		}
		cout << "#" << test_case << " " << !checkFail << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}