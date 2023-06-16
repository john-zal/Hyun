#include <iostream>
#include <stack>

using namespace std;

void reverse(int arr[], int start, int end)
{
	int length = end - start + 1;
	stack<int> stack;
	for (int i = start; i <= end; i++)
		stack.push(arr[i]);
	
	for (int i = start; i <= end; i++)
	{
		arr[i] = stack.top();
		stack.pop();
	}
}

int main()
{
	int arr[21];
	for (int i = 0; i < 21; i++)
		arr[i] = i;

	int startIdx = 0;
	int endIdx = 0;

	for (int i = 0; i < 10; i++)
	{
		cin >> startIdx;
		cin >> endIdx;
		reverse(arr, startIdx, endIdx);
	}

	for (int i = 1; i < 21; i++)
		cout << arr[i] << " ";

	return 0;
}