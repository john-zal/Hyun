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

    //������ ���ϱ�
    while ((sqrtNum * sqrtNum) < num)
        sqrtNum++;

    //1. num�� 1���� �����ٱ��� �������� 0�� ���� ã�´�
    for (int i = 1; i <= sqrtNum; i++)
    {
        if (num % i == 0)
            v.push_back(i);
    }

    //2. ���� ������ �ٽ� num�� ���� ���� �߰��Ѵ�.
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        v.push_back(num / v[i]);
    }


    //3. �ߺ����� ���� ���� �����Ѵ�.
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