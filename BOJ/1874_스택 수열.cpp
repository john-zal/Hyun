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
			//���� ž�� num���� ũ�� ��
			if (stack.top() > num)
			{
				stack.pop();
				output += "- \n";
			}
			//���� ž�� num���� ������ Ǫ�� 
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