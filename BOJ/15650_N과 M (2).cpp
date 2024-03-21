#include <iostream>

using namespace std;

int N, M; //nCr
int arr[9];

void Comb(int dep, int start) //현재까지 뽑은 조합 개수, 조합할 원소의 시작 인덱스
{
	if (dep == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i <= N; i++)
	{
			arr[dep] = i;
			//중복없는 식이 되려면 다음 노드가 이전 노드 보다 크면 안된다.
			Comb(dep + 1, i +1); // 따라서 인덱스도 같이 올려준다.
	}
}

int main()
{
	cin >> N >> M;
	Comb(0, 1);
}