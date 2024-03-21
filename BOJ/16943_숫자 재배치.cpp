#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int A, B;

//1,000,000,000
bool isUsed[10];
vector<int>	arr;
vector<int> vecNum;
int maxNum = 0;

void ParseToVec(int num)
{
	if (!num)
		return;

	int temp = num / 10;
	ParseToVec(temp);
	vecNum.push_back(num % 10);
}

int ParseToInt(vector<int>& vec)
{
	int size = (int)vec.size();
	int sum = 0;
	for (int i = 1; i <= size; i++)
		sum += vec[i-1]  * (int)pow(10, size - i);

	return sum;
}

void Rec(int num)
{
	if (num == (int)vecNum.size())
	{
		if (!arr[0])
			return;

		int sum = ParseToInt(arr);

		if (B > sum)
			maxNum = max(sum, maxNum);

		return;
	}

	for (int i = 0; i < (int)vecNum.size(); i++)
	{
		if (!isUsed[i])
		{
			isUsed[i] = true;
			arr.push_back(vecNum[i]);
			Rec(num + 1);
			isUsed[i] = false;
			arr.pop_back();
		}
	}
}

int main()
{
	cin >> A >> B;
	ParseToVec(A);
	Rec(0);

	maxNum ? cout << maxNum : cout << -1;
}