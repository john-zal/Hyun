#include<iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		const int rotateTime = 3;
		int arrSize;
		cin >> arrSize;
		vector<vector<int>> vecRow;

		//입력
		for (int i = 0; i < arrSize; i++)
		{
			vector<int> vecCol(arrSize);
			for (int j = 0; j < arrSize; j++)
				cin >> vecCol[j];

			vecRow.push_back(vecCol);
		}

		// 출력용 배열 생성
		vector<vector<string>> vecAnswer;
		for (int i = 0; i < arrSize; i++)
		{
			vector<string> vecAnswer2(rotateTime);
			vecAnswer.push_back(vecAnswer2);
		}

		//90 180 270 회전
		for (int k = 0; k < rotateTime; k++)
		{
			//카피배열 생성
			vector<vector<int>> vecCopy;
			for (int i = 0; i < arrSize; i++)
			{
				vector<int> vecCopy2(arrSize);
				vecCopy.push_back(vecCopy2);
			}

			// 회전 정보 저장
			int size = arrSize - 1;
			for (int i = 0; i < arrSize; i++)
			{
				string numStr = "";
				for (int j = 0; j < arrSize; j++)
				{
					vecCopy[i][j] = vecRow[size - j][i];
					numStr += to_string(vecCopy[i][j]);
				}
				vecAnswer[i][k] = numStr;
			}

			vecRow = vecCopy;
		}

		cout << "#" << test_case << '\n';
		//결과 출력
		for (int i = 0; i < arrSize; i++)
		{
			for (int j = 0; j < rotateTime; j++)
				cout << vecAnswer[i][j] << " ";
			
			cout << '\n';
		}
		vecAnswer;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}