import java.util.Arrays;
class Solution {
	public int solution(int n, int[] lost, int[] reserve) {
		// n 전체 학생 수
		// lost: 체육복 잃어버린 학생 번호 lost
		// reserve 여벌 가지고있는 학생 1,3,5
		// 체육수업이 가능한 학생 answer
		//
		//

		int answer = 0;
		int[] student = new int[n]; // 0 1 2 3 4
		for (int i = 0; i < n; i++) {
			student[i] = 1; // 다 1로 초기화 //lost와 reserve에 없는애들은 기본적으로 1
		}

		Arrays.sort(lost); // 2 4
		Arrays.sort(reserve); // 1 3 5
		for (int i = 0; i < lost.length; i++) {
			student[lost[i] - 1] -= 1; // 체육복 없는 애들은 -1 (0)
		}
		for (int i = 0; i < reserve.length; i++) { // 1 3 5
			student[reserve[i] - 1] += 1; // 체육복 있는애들은 1개 추가 (2)
		}

		for (int i = 0; i < student.length; i++) { // 체육복 나눠주는 for문 2 1 0
			if (student[i] == 0) { // 없는 학생 있을 때
				if (i > 0 && student[i - 1] == 2) {
					student[i] += 1;
					student[i - 1] -= 1;
				} else if (i < student.length-1 && student[i + 1] == 2) {
					student[i] += 1;
					student[i + 1] -= 1;
				}
			}

		}
		for (int i = 0; i < student.length; i++) { // 체육복 나눠주는 for문 2 0 2 0 2
			if (student[i] >= 1) {
				answer++;
			}
		}
		return answer;
	}
}