#include <iostream>

using namespace std;
void Shuffle(int arr[], int start, int end)
{
	int tempArr[101];
	int length = end - start + 1;
	
	for (int i = 0; i < length; i++)
		tempArr[i] = arr[end - i];

	for (int i = start; i <= end; i++)
		arr[start + (i - start)] = tempArr[i - start];

}
int main()
{
	int basket, count;
	cin >> basket >> count;

	int basketArr[101];

	for (int i = 1; i <= basket; i++)
		basketArr[i] = i;

	for (int i = 0; i < count; i++)
	{
		int start, end;
		cin >> start >> end;

		Shuffle(basketArr, start, end);
	}

	for (int i = 1; i <= basket; i++)
		cout << basketArr[i] << " ";
	
	cout << '\n';
	return 0;
}