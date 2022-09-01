#include <bits/stdc++.h>

using namespace std;
#define X  first
#define Y second
bool visited[500][500];
int main() 
{

	int arr[500][500] = {};
	

	int n; //����
	int m; //����
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int dx[4] = { 1,0,-1,0 }; //�� �� �� ��
	int dy[4] = { 0,1,0,-1 };

	//ù°�� �׸� ����
	int paint_count = 0;
	//�ι� ° ���� ���� �׸��� ����
	int paint_max = 0;
	queue<pair<int, int>> Q;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0 || visited[i][j])
				continue;

				int temp = 0;
				visited[i][j] = true;
				
				Q.push({ i, j });
				temp++;

				//���⼭ bfs Ž��
				while (!Q.empty()) 
				{				
					pair<int, int> cur = Q.front();
					Q.pop();
					//Ŀ�������
					
					//�����¿� Ž��
					for (int k = 0; k < 4; k++)
					{							
							int nx = cur.X + dx[k]; //  ������ǥ+x��
							int ny = cur.Y + dy[k];// ������ǥ + y��

							//�ٱ��� ����� ����ó��
							if (nx < 0 || nx >= n || ny < 0 || ny >= m)
								continue;

							//�̹� �湮�� �迭�̰ų� 1�� �ƴϸ�
							if (visited[nx][ny] || arr[nx][ny] != 1)
								continue;

							visited[nx][ny] = 1; //�湮ó��
							Q.push({ nx, ny }); 
							temp++;						
					}
				}
				if (temp > paint_max) 
				{
					paint_max = temp;
				}
					paint_count++;
		}
	}
	std::cout << paint_count << std::endl;
	std::cout << paint_max << std::endl;
	return 0;
}