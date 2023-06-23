#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	//괄호가 짝지어져 팝되고 남아있는 stack size를 모두 더해주면 결과값이 나온다.
	int answer = 0;
	stack<char> stack;

	string s = "";
	cin >> s;

	
	//레이저가 아닐 시 잘린 파이프, 
	//다음 레이저를 만날 때 개수가 추가되고 0이된다.
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
			if (stack.top() != s[i]) //괄호가 닫힐 시
			{
				if (s[i] == ')' && (s[i - 1] != s[i])) // () 레이저일시
				{
					stack.pop();
					answer += (int)stack.size() + dummyPipe;
					dummyPipe = 0;
				}
				else //괄호는 닫혔는데 레이저가 아님
				{
					//파이프가 끊어졌으니 다음 레이저까지만 세준다.
					stack.pop();
					dummyPipe += 1;
				}				
			}
			else //괄호 안닫힘
				stack.push(s[i]);			
		}
	}

	//남은 파이프를 추가한다.
	if (dummyPipe)
		answer += dummyPipe;

	cout << answer << endl;
	return 0;
}