#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int answer = 0;

	//�׸���
	while (N > 0)
	{
		//5�� ��������
		if (!(N % 5))
		{
			answer += N / 5;
			N %= 5;
		}		
		else //3�� �ϳ��� ������
		{
			N -= 3;
			answer += 1;
		}			
	}
	if (N < 0)
		answer = -1;

	cout << answer;
}