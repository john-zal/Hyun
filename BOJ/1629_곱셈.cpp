#include <iostream>
using namespace std;
using ll = long long;

/*����: https://www.youtube.com/watch?v=mzLx_NWpuSY
 �� (A * C)MOD B �� A MOD B* C MOD B �� ����.
	�̸� �̿��Ͽ� ������ �� ���·� ġȯ�Ͽ� �����ϴ� �ڷ����� ���� 
	������ �ʰ��ϴ� ��Ȳ�� �����Ѵ�. 
*/
//�ͳ��� ��� ù��° ����� �Ǹ� �ι�° ����� �ȴ�. -> ...N��° ����� �� ���̴�.

ll A; // ���
ll B; // ��
ll C; // mod

ll Mod(ll num)
{
	if (num == 1)
		return A % C;

	ll sum = Mod(num /2); // 2�� 7���̸� 2^3 * 2^3 * 2^1�� �����Ѵ�.
	sum = sum * sum % C;
	//��� �Լ� ���� ��
	return num % 2 == 0 ? sum : sum * A % C;
}

int main()
{
	cin >> A >> B >> C;
	cout << Mod(B) << endl;
	return 0;
}