#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int answer = 0;

	//그리디
	while (N > 0)
	{
		//5로 나눠질때
		if (!(N % 5))
		{
			answer += N / 5;
			N %= 5;
		}		
		else //3을 하나씩 빼보기
		{
			N -= 3;
			answer += 1;
		}			
	}
	if (N < 0)
		answer = -1;

	cout << answer;
}