#include <iostream>

using namespace std;

int mainPiece[6] = { 1, 1, 2, 2, 2, 8 };

int main()
{
	int piece[6];
	for (int i = 0; i < 6; i++)
		cin >> piece[i];

	for (int i = 0; i < 6; i++)
	{
		piece[i] = mainPiece[i] - piece[i];
		cout << piece[i] << " ";
	}	
}