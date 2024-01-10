#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		cin >> N >> M;

		//배열 입력
		vector<vector<int>> vec;
		for (int i = 0; i < N; i++)
		{
			vector<int> vec2(N);
			for (int j = 0; j < N; j++)
				cin >> vec2[j];

			vec.push_back(vec2);
		}

		//스프레이 뿌리기
		int mostKillFly = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int sumA = vec[i][j];
				int sumB = vec[i][j];

				for (int k = 1; k < M; k++)
				{
					//상, 하, 좌, 우, 좌상, 좌하, 우상, 우하
					int dir[8][2] = { {-1,0}, {1,0}, {0,-1}, {0, 1}, 
									{ -1, -1 }, { 1, -1 }, { -1, 1 }, { 1, 1 } };
					
					for (int l = 0; l < 8; l++)
					{
						if (i == 1 && j == 1)
							int a = 0;

						int x = i + (k * dir[l][0]);
						int y = j + (k * dir[l][1]);

						if ((x >= 0 && x < N) && (y >= 0 && y < N))
							l <= 3 ? sumA += vec[x][y] : sumB += vec[x][y];		
					}
					int multiKillMax = max(sumA, sumB);

					mostKillFly = max(multiKillMax, mostKillFly);
				}
			}
		}
		cout << "#" << test_case << " " << mostKillFly << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}