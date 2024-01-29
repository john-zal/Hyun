#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> answer;

void Hanoi(int num, int left, int mid, int right)
{
    if (num == 1)
    {        
        answer.push_back({ left, right });
        return;
    }


    //맨 아래에서 두번째에서(n-1) 꼭데기에 있는 블록까지 가운데로 옮긴다
    Hanoi(num - 1,left, right, mid);

    //1에서 3으로 옮긴다?
    answer.push_back({ left, right });

    //a를 거쳐 c로 옮긴다.
    Hanoi(num - 1, mid, left, right);

}

vector<vector<int>> solution(int n) {
    

    int hanoi[3] = { 1, 2, 3 };
    
    Hanoi(n, 1, 2, 3);
    
    return answer;

}

int main()
{
    solution(3);
}