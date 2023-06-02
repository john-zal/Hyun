#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int DivisorCount(int num)
{
    vector<int> v;
    //int count = -1;
    int sqrtNum = 1;

    //제곱근 구하기
    while ((sqrtNum * sqrtNum) < num)
        sqrtNum++;

    //1. num을 1부터 제곱근까지 나머지가 0인 수를 찾는다
    for (int i = 1; i <= sqrtNum; i++)
    {
        if (num % i == 0)
            v.push_back(i);
    }

    //2. 나온 수들을 다시 num에 나눈 값을 추가한다.
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        v.push_back(num / v[i]);
    }


    //3. 중복으로 나온 수를 제거한다.
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0)
        {
            if (v[i - 1] == v[i])
                v.erase(v.begin() + i);
        }
    }

    return (int)v.size();
}

int solution(int number, int limit, int power) {
    int answer = 0;

    for (int i = 1; i <= number; i++)
    {
        int div = DivisorCount(i);
        if (div > limit)
            div = power;

        answer += div;
    }

    return answer;
}

int main()
{
    cout << solution(10, 3, 2) << endl;
    return 0;
}