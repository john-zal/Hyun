#include <iostream>
#include <vector>
using namespace std;

int main()
{
	while (1)
	{
		int num = 0;
		cin >> num;
		
		if (num == -1)
			break;

		int sum = 0;
		vector<int> vec;
		for (int i = 1; i <= num/2; i++)
		{
			if (!(num % i))
			{
				sum += i;
				vec.push_back(i);
			}		
		}
		if (num == sum)
		{
			cout << num << " = ";
			int size = (int)vec.size();
			for (int i = 0; i < size; i++)
			{
				cout <<vec[i];
				if (i < size -1)
					cout << " + ";
			}
			cout << '\n';
		}
		else
			cout << num << " is NOT perfect.\n";		
	}	
}