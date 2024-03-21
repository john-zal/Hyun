#include <iostream>

using namespace std;

int N, M;
int arr[8];
bool isUsed[8];

void Recursive(int num)
{
	if (num == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		//if (!isUsed[i])
		//{
			arr[num] = i;
			//isUsed[i] = true;

			Recursive(num + 1);
			//isUsed[i] = false;
		//}
	}
}

int main()
{
	cin >> N >> M;

	Recursive(0);
}