#include <iostream>
using namespace std;
using ll = long long;

/*참고: https://www.youtube.com/watch?v=mzLx_NWpuSY
 ■ (A * C)MOD B 는 A MOD B* C MOD B 와 같다.
	이를 이용하여 오른쪽 식 형태로 치환하여 연산하는 자료형의 값이 
	범위를 초과하는 상황을 방지한다. 
*/
//귀납적 사고 첫번째 방법이 되면 두번째 방법도 된다. -> ...N번째 방법도 될 것이다.

ll A; // 계수
ll B; // 승
ll C; // mod

ll Mod(ll num)
{
	if (num == 1)
		return A % C;

	ll sum = Mod(num /2); // 2의 7승이면 2^3 * 2^3 * 2^1로 분할한다.
	sum = sum * sum % C;
	//재귀 함수 끝날 시
	return num % 2 == 0 ? sum : sum * A % C;
}

int main()
{
	cin >> A >> B >> C;
	cout << Mod(B) << endl;
	return 0;
}