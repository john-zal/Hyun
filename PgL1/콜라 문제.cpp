#include <iostream>

using namespace std;
int answer = 0;

//총 n개의 빈 병 중 a개를 주면 콜라 b개를 주는
int solution(int a, int b, int n) {
	if (n == 0 || n < a)
		return answer;
	
	int emptyBottle = n;
	
	int RecycleCola = (emptyBottle / a) * b; //받을 수 있는 콜라
	answer += RecycleCola;
	emptyBottle = (emptyBottle % a) + RecycleCola; //남은 병
	
	return solution(a, b, emptyBottle);
}

int main()
{
	int a = 0;	//a 마트에 주어야 하는 병 수
	int b = 0; 	//b 마트가 주는 콜라 병 수 최소 1개, a보다 작음
	int n = 0; 	//n 빈 병의 개수 // b보다 작음

	cin >> a >> b >> n;

	

	cout << solution(a, b, n) << '\n';

	return 0;
}