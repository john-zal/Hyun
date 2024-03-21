#include <iostream>
#include <utility>

using namespace std;

pair<int, int> dp[301];

#define NUM first
#define MAXNUM second

int main()
{
	//N ==4���� DP ����
	int N;
	cin >> N;
	int num;
	int maxNum;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;

		if (i == 1)
			dp[i] = { num, num }; //���� ���� �ִ�			
		else if (i == 2) //�������� ���� ���� ���� ���� �ִ밪
			dp[i] = { num, dp[i - 1].NUM + num };
		else if (i == 3) //1�� 2�� ���� �� ū ���� ����			
			dp[i] = { num, max(dp[i - 1].NUM, dp[i - 2].NUM) + num };
		else //DP
		{
			//����� �Ѵ� ���
			/*
			����� A B C D�� ������
			A C D ����� �ְ�
			A B D ����� �ִ�.
			AB D ����� B�� ������ A�� �������Ƿ�  B D�� ���� �ȴ�?
			*/

			//A C D ? A B D
			int ACD = dp[i - 3].MAXNUM + num + dp[i - 1].NUM;
			int ABD = dp[i - 2].MAXNUM + num;
			dp[i] = { num, max(ACD, ABD) };
		}
	}
	cout << dp[N].MAXNUM;
}