#include <iostream>
#include <string>
#include <stack>
using namespace std;

int OpenBlock(char c)
{
	int num = 1;

	if (c == '(')
		num = 2;
	else if (c == '[')
		num = 3;
	else if (c == ')' || c == ']')
		num = -1;

	return num;
}
int CloseBlock(char open, char close)
{
	int num = 1;

	if (open == '(' && close == ')')
		num = 2;
	if (open == '[' && close == ']')
		num = 3;
	if ((open == '(' && close == ']') ||
		(open == '[' && close == ')'))
		num = -1;

	return num;
}

int main()
{
	string s;
	cin >> s;
	
	int answer = 0;
	int num = 1;//��ġ�� ���
	stack<char> stk;

	if (s.size() % 2 == 1)//Ȧ��
	{
		cout << 0 << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (stk.empty())
			{
				stk.push(s[i]);
				num *= OpenBlock(s[i]);
				if (num < 0)
					break;
			}
			else// ������ �ϳ� �̻�
			{
				//������ȣ 
				if (s[i] == '(' || s[i] == '[')
				{
					stk.push(s[i]);
					num *= OpenBlock(s[i]);
					if (num < 0)
						break;
				}
				else if (CloseBlock(s[i - 1], s[i]) > 1)//���� ��ȣ�϶�
				{
					int j = CloseBlock(s[i - 1], s[i]);
					if (j < 0)
					{
						num = -1;
						break;
					}
					answer += num;
					num /= j;
					stk.pop();
				}
				else if (CloseBlock(stk.top(), s[i]) > 1) //���ڴ� �ƴϰ� ��� ��������
				{
					int j = CloseBlock(stk.top(), s[i]);
					if (j < 0)
					{
						num = -1;
						break;
					}
					num /= j;
					stk.pop();
				}
				else
				{
					num = -1;
					break;
				}
			}
		}
	}
	if (num < 0)
		answer = 0;
	cout << answer << endl;
	return 0;
}