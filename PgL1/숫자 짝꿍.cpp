#include <iostream>
#include <algorithm>

#define ASCIIZERO 48

using namespace std;

bool ReverseSort(int x, int y)
{
	return y < x;
}
	

string solution(string X, string Y) 
{
	if (X[0] == '0' || Y[0] == '0')
		return "0";

	string answer = "";
	int numArr[10];
	memset(numArr, 0, 40);
	
	if (X.size() < Y.size())
		swap(X, Y);
	
	for (size_t i = 0; i < X.size(); i++)
		numArr[X[i] - ASCIIZERO]++;

	for (size_t i = 0; i < Y.size(); i++)
	{
		if (numArr[Y[i] - ASCIIZERO] > 0)
		{
			numArr[Y[i] - ASCIIZERO]--;
			answer += Y[i];
		}
	}					

	//Áßº¹ ¾øÀ» ½Ã
	if (answer == "")
		answer = "-1";
	else
	{
		sort(answer.begin(), answer.end(), ReverseSort);
		if (answer[0] == '0')
			answer = "0";
	}

	return answer;
}

int main() 
{
	//¼ýÀÚ Â¦²á
	string numX = "";
	string numY = "";
	
	cin >> numX;
	cin >> numY;
	
	//solution(numX, numY);

	//sort(numX.begin(), numX.end());

	cout << solution(numX, numY) << endl;

	return 0;
}