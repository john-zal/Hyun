#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/*
* 3�� ���� 
CCTV 1	2	3	4	5
	 ��  ��   ��� ����  +
*/

//��, ��, ��, ��
pair<int, int> DIR[4] = { {-1,0}, {1,0}, {0, -1}, {0, 1} };
#define x first
#define y second 

class Camera
{
public:
	Camera() {};
	~Camera() {};

	vector<pair<int, int>> camDir;

	//ī�޶�, Default�� ��
	void SetCamDir(int num)
	{
		switch (num-1)
		{
		case 1: //1�� ī�޶�
			camDir.push_back(DIR[num]);
			break;
		case 2: //2�� ī�޶� ��, ��
			camDir.push_back(DIR[0]); 
			camDir.push_back(DIR[1]);
			break;
		case 3: //3�� ī�޶� ��, ��
			camDir.push_back(DIR[0]);
			camDir.push_back(DIR[3]);
			break;
		case 4: //4�� ī�޶� ��, ��, ��
			camDir.push_back(DIR[0]);
			camDir.push_back(DIR[2]);
			camDir.push_back(DIR[3]);
			break;
		case 5: //5�� ī�޶� ��, ��, ��, ��
			camDir.push_back(DIR[0]);
			camDir.push_back(DIR[1]);
			camDir.push_back(DIR[2]);
			camDir.push_back(DIR[3]);
			break;
		default:
			break;
		}
	}

	void ChangeCamDir(int count)
	{

	}

	void ResetCamDir()
	{
		for (int i = 0; i < 4; i++)
			camDir[i] = { 0, 0 };
	}
};


int main()
{
	int N, M;
	cin >> N >> M;
}
