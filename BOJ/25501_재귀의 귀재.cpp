#include <iostream>
#include <string.h>

using namespace std;
int CNT = 0;

int recursion(const string& str, int l, int r)
{
	CNT++;

	if (l >= r) //l r�� �����ϸ� (�� �̻� ���� �� ������)
		return 1;
	else if (str[l] != str[r]) //�糡�� �ٸ��� ���� ����
		return 0;
	else //�� ���� ������ �̾ �����Ѵ�.
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