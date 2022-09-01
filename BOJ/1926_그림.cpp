#include <bits/stdc++.h>

using namespace std;
#define X  first
#define Y second
bool visited[500][500];
int main() 
{

	int arr[500][500] = {};
	

	int n; //세로
	int m; //가로
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int dx[4] = { 1,0,-1,0 }; //상 하 좌 우
	int dy[4] = { 0,1,0,-1 };

	//첫째줄 그림 개수
	int paint_count = 0;
	//두번 째 가장 넓은 그림의 넓이
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

				//여기서 bfs 탐색
				while (!Q.empty()) 
				{				
					pair<int, int> cur = Q.front();
					Q.pop();
					//커서만들고
					
					//상하좌우 탐색
					for (int k = 0; k < 4; k++)
					{							
							int nx = cur.X + dx[k]; //  현재좌표+x값
							int ny = cur.Y + dy[k];// 현재좌표 + y값

							//바깥을 벗어나는 예외처리
							if (nx < 0 || nx >= n || ny < 0 || ny >= m)
								continue;

							//이미 방문한 배열이거나 1이 아니면
							if (visited[nx][ny] || arr[nx][ny] != 1)
								continue;

							visited[nx][ny] = 1; //방문처리
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