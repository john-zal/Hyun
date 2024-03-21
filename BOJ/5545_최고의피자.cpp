#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N; //������ ����

	 //������ ����, ������ ����, ������ ����
	int dohCost, topCost, douKal;
	
	//N���� ������ ���� 
	
	cin >> N >> dohCost >> topCost >> douKal;
	vector<int> topKal(N);

	for (int i = 0; i < N; i++)
		cin >> topKal[i];

	sort(topKal.begin(), topKal.end(), greater<>());

	//���� ���� 2�� ����, ���� �ƿ� �Ƚᵵ ��
	// ������ ���� douCost + (topCost * N)
	// ������ ���� douKal + topKal

	int maxCostValue = douKal / dohCost;

	int sumKal = 0;
	int costCount = 0;
	for (int i = 0; i < topKal.size(); i++)
	{
		costCount += 1;
		sumKal += topKal[i];
		int calcKal = (douKal + sumKal) / (dohCost + (topCost * costCount));
		
		//�̰� > ���� >=�� �ٲٴϱ� ��
		//�Ҽ��� ���ϳ�..
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