#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	int N = 0;
	cin >> N;

	stack<int> stack;
	int stackNum = 1;
	string output = "";

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		if (stack.empty())
		{
			stack.push(stackNum);
			stackNum += 1;
			output += "+ \n";
		}

		while (!(stack.top() == num))
		{
			if (stackNum > N)
			{
				output = "NO";
				break;
			}
			//스택 탑이 num보다 크면 팝
			if (stack.top() > num)
			{
				stack.pop();
				output += "- \n";
			}
			//스택 탑이 num보다 작으면 푸시 
			else if (stack.top() < num)
			{
				stack.push(stackNum);
				stackNum+= 1;
				output += "+ \n";
			}
		}

		if (output != "NO")
		{
			stack.pop();
			output += "- \n";
		}
	}
	cout << output << '\n';
	return 0;
}