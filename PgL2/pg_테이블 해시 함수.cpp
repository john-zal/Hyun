#include<iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int g_Column;

int Module(const vector<int>& v, int row)
{
    int sum = 0;
    for (int i : v)
        sum += i % row;

    return sum;
}

bool Compare(const vector<int>& v1, const vector<int>& v2)
{
    //컬럼 같은 숫자면 첫번째 항을 비교해서 내림차순, else 컬럼기준 오름차순
        return v1[g_Column] == v2[g_Column] ? v1[0] > v2[0] : v1[g_Column] < v2[g_Column];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    g_Column = col - 1;
    sort(data.begin(), data.end(), Compare);

    int sum = Module(data[row_begin -1], row_begin);
    for (int i = row_begin; i < row_end; i++)
        sum ^= Module(data[i], i+1);
    
    return sum;
}

int main()
{
    vector<vector<int>> vec= { {2, 2, 6},{1, 5, 10},{4, 2, 9},{3, 8, 3} };
    cout << solution(vec, 2, 2, 3);
}