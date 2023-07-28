#include <iostream>
#include <string.h>

using namespace std;
int CNT = 0;

int recursion(const string& str, int l, int r)
{
	CNT++;

	if (l >= r) //l r이 교차하면 (더 이상 비교할 게 없으면)
		return 1;
	else if (str[l] != str[r]) //양끝이 다르면 빠져 나옴
		return 0;
	else //양 끝이 같으면 이어서 수행한다.
		return recursion(str, l + 1, r - 1);
}

int main()
{
	int num;
	string s;
	cin >> num;

	while (num--)
	{
		cin >> s;
		cout << recursion(s, 0, (int)s.size()-1) << " " << CNT << endl;
		CNT = 0;
	}
	return 0;
}