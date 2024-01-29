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


    //�� �Ʒ����� �ι�°����(n-1) �����⿡ �ִ� ��ϱ��� ����� �ű��
    Hanoi(num - 1,left, right, mid);

    //1���� 3���� �ű��?
    answer.push_back({ left, right });

    //a�� ���� c�� �ű��.
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