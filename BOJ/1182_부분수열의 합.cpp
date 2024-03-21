#include <iostream>

using namespace std;
int N, S;
int arr[20];
int cnt = 0;

void F(int num, int total)
{
	if (num == N)
	{
		if (total == S)
			cnt++;
		return;
	}

		F(num + 1, total);
		F(num + 1, total + arr[num]);
}

int main()
{
	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	F(0, 0);

	if (S == 0)
		cnt--;
	cout << cnt;
}