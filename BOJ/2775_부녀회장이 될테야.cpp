#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//0���� iȣ�� i���� ���.
	
	int T, k, n; //k���� nȣ
	cin >> T;
	while (T--)
	{		
		cin >> k >> n;			

		vector<vector<int>> vec;

		for (int i = 0; i <= k; i++)
		{
			vector<int> v;			
			for (int j = 0; j < n; j++)
			{
				if (!i)
					v.push_back(j+1);
				else			 		
					!j ? v.push_back(1) : v.push_back(v[j - 1] + vec[i - 1][j]);
			}
			vec.push_back(v);
		}
 		cout << vec[k][n-1] << '\n';
	}
}
