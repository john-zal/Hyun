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

		//�迭 �Է�
		vector<vector<int>> vec;
		for (int i = 0; i < N; i++)
		{
			vector<int> vec2(N);
			for (int j = 0; j < N; j++)
				cin >> vec2[j];

			vec.push_back(vec2);
		}

		//�������� �Ѹ���
		int mostKillFly = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int sumA = vec[i][j];
				int sumB = vec[i][j];

				for (int k = 1; k < M; k++)
				{
					//��, ��, ��, ��, �»�, ����, ���, ����
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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}