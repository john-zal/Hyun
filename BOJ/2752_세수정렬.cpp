#include<bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v;
	int num = 0;
	for (int i = 0; i < 3; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
	return 0;
}