#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int arrSize = (int)number.size();
    sort(number.begin(), number.end());
    
    vector<bool> vecBool(arrSize, false);
    vecBool[arrSize - 1] = true;
    vecBool[arrSize - 2] = true;
    vecBool[arrSize - 3] = true;

    do {     
        int tripleCount = 0;
        for (int i = 0; i < arrSize; i++)
        {
            if (vecBool[i])
                tripleCount += number[i];
        }
        if (tripleCount == 0)
            answer++;
    } 
    while (next_permutation(vecBool.begin(), vecBool.end()));

    return answer;
}

//====================================================
int main()
{
    vector<int> vec = { -1, 1, -1, 1 };
    cout << solution(vec) << '\n';

    return 0;
}