#include <iostream>

using namespace std;
int main()
{
	int HH, MM, SS, TT;

	cin >> HH >> MM >> SS >> TT;

	if (TT / 3600)
	{
		HH += TT / 3600;
		TT %= 3600;
	}
	if (TT / 60)
	{
		MM += TT / 60;
		TT %= 60;
	}
		
	SS += TT;

	if (SS >= 60)
	{
		MM++;
		SS %= 60;
	}
	if (MM >= 60)
	{
		HH++;
		MM %= 60;
	}

	HH %= 24;

	cout << HH << " " << MM << " " << SS;
}