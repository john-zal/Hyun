#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N; //토핑의 종류

	 //도우의 가격, 토핑의 가격, 도우의 열량
	int dohCost, topCost, douKal;
	
	//N개의 토핑의 열량 
	
	cin >> N >> dohCost >> topCost >> douKal;
	vector<int> topKal(N);

	for (int i = 0; i < N; i++)
		cin >> topKal[i];

	sort(topKal.begin(), topKal.end(), greater<>());

	//같은 토핑 2개 못씀, 토핑 아예 안써도 됨
	// 피자의 가격 douCost + (topCost * N)
	// 피자의 열량 douKal + topKal

	int maxCostValue = douKal / dohCost;

	int sumKal = 0;
	int costCount = 0;
	for (int i = 0; i < topKal.size(); i++)
	{
		costCount += 1;
		sumKal += topKal[i];
		int calcKal = (douKal + sumKal) / (dohCost + (topCost * costCount));
		
		//이거 > 에서 >=로 바꾸니까 됨
		//소숫점 비교하나..
		if (calcKal >= maxCostValue)
			maxCostValue = calcKal;
		else
		{
			costCount -= 1;
			sumKal -= topKal[i];
		}	
	}

	cout << maxCostValue;
}