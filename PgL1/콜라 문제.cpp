#include <iostream>

using namespace std;
int answer = 0;

//�� n���� �� �� �� a���� �ָ� �ݶ� b���� �ִ�
int solution(int a, int b, int n) {
	if (n == 0 || n < a)
		return answer;
	
	int emptyBottle = n;
	
	int RecycleCola = (emptyBottle / a) * b; //���� �� �ִ� �ݶ�
	answer += RecycleCola;
	emptyBottle = (emptyBottle % a) + RecycleCola; //���� ��
	
	return solution(a, b, emptyBottle);
}

int main()
{
	int a = 0;	//a ��Ʈ�� �־�� �ϴ� �� ��
	int b = 0; 	//b ��Ʈ�� �ִ� �ݶ� �� �� �ּ� 1��, a���� ����
	int n = 0; 	//n �� ���� ���� // b���� ����

	cin >> a >> b >> n;

	

	cout << solution(a, b, n) << '\n';

	return 0;
}