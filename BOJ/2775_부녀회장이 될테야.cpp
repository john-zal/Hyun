#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//0층은 i호는 i명이 산다.
	
	int T, k, n; //k층의 n호
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
