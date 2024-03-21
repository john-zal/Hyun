#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int recursive(int size, int num)
{
	if (size == 0)
		return 1;
	
	return num * recursive(size -1, num);
}

int main()
{
	string N;
	int B;
	int size;

	cin >> N >> B;
	size = (int)N.size();

	int add = size <=1 ? 0 : 1;
	cout << recursive(size, B) - 1;
}