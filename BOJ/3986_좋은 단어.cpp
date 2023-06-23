#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int answer = 0;
	int N = 0;
	cin >> N;
	
	while (N--)
	{
		stack<char> stack;
		string s = "";
		
		cin >> s;

		//홀수는 나쁜단어
		if (s.size() % 2 == 1)
			continue;

		for (char c : s)
		{
			if (stack.size() > 0)
			{
				//같은지 체크하기
				if (stack.top() == c)
					stack.pop();
				else
					stack.push(c);
			}
			else
				stack.push(c);
		}

		if (stack.empty())
			answer += 1;
	}
	cout << answer << endl;
	return 0;
}