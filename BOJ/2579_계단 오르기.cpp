#include <iostream>
#include <utility>

using namespace std;

pair<int, int> dp[301];

#define NUM first
#define MAXNUM second

int main()
{
	//N ==4부터 DP 시작
	int N;
	cin >> N;
	int num;
	int maxNum;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;

		if (i == 1)
			dp[i] = { num, num }; //현재 값이 최대			
		else if (i == 2) //이전값과 현재 값을 더한 것이 최대값
			dp[i] = { num, dp[i - 1].NUM + num };
		else if (i == 3) //1과 2의 숫자 중 큰 것을 선택			
			dp[i] = { num, max(dp[i - 1].NUM, dp[i - 2].NUM) + num };
		else //DP
		{
			//계단을 넘는 방식
			/*
			계단이 A B C D가 있으면
			A C D 방식이 있고
			A B D 방식이 있다.
			AB D 방식은 B가 어차피 A를 지났으므로  B D만 보면 된다?
			*/

			//A C D ? A B D
			int ACD = dp[i - 3].MAXNUM + num + dp[i - 1].NUM;
			int ABD = dp[i - 2].MAXNUM + num;
			dp[i] = { num, max(ACD, ABD) };
		}
	}
	cout << dp[N].MAXNUM;
}