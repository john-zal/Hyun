#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	//��ȣ�� ¦������ �˵ǰ� �����ִ� stack size�� ��� �����ָ� ������� ���´�.
	int answer = 0;
	stack<char> stack;

	string s = "";
	cin >> s;

	
	//�������� �ƴ� �� �߸� ������, 
	//���� �������� ���� �� ������ �߰��ǰ� 0�̵ȴ�.
	int dummyPipe = 0;
	for (int i = 0; i< s.size(); i++)
	{
		if (stack.empty())
		{
			if (dummyPipe)
			{
				answer += dummyPipe;
				dummyPipe = 0;
			}
			stack.push(s[i]);
		}
			
		else
		{
			if (stack.top() != s[i]) //��ȣ�� ���� ��
			{
				if (s[i] == ')' && (s[i - 1] != s[i])) // () �������Ͻ�
				{
					stack.pop();
					answer += (int)stack.size() + dummyPipe;
					dummyPipe = 0;
				}
				else //��ȣ�� �����µ� �������� �ƴ�
				{
					//�������� ���������� ���� ������������ ���ش�.
					stack.pop();
					dummyPipe += 1;
				}				
			}
			else //��ȣ �ȴ���
				stack.push(s[i]);			
		}
	}

	//���� �������� �߰��Ѵ�.
	if (dummyPipe)
		answer += dummyPipe;

	cout << answer << endl;
	return 0;
}