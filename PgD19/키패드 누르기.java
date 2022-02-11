package programmers;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);
		
		//7 0 8 2 8 3 1 5 7 6 2
		
		//LLLLLRLLLRR
		//LRLLRRLLLRR
		//  *   *  
		// 가운데 2580 현재 위치에서 더 가까운 손가락
		// 둘 다 같으면 손잡이 여부로 결정

		int[] numbers = { 2,5,8,0 }; //
		String hand = "right";
		System.out.println(s.solution(numbers, hand));
	}
}

class Solution {
	public String solution(int[] numbers, String hand) {
		int range = 0;
		String answer = "";
		int[][] keypad = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 0, 12 } }; // * 0 #
		int[] Lhand = { 3, 0 }; // 10 , *
		int[] Rhand = { 3, 2 };// 12, #
		int[] MRange = { 0, 0 };

		for (int i = 0; i < numbers.length; i++) { // 입력받은 넘버값 1 3 4 5 8 2 1 4 5 9 5
			
			if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7 || numbers[i] == 10) {
				// 1 4 7 10				
				answer += "L";
				for (int j = 0; j < 4; j++) { // 키패드 2차원 배열
					for (int k = 0; k < 3; k++) {
						if (keypad[j][k] == numbers[i]) { // j, k 값
							Lhand[0] = j;
							Lhand[1] = k;
						}
					}
				}

			} else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9 || numbers[i] == 12) {
				answer += "R";
				for (int j = 0; j < 4; j++) { // 키패드 2차원 배열
					for (int k = 0; k < 3; k++) {
						if (keypad[j][k] == numbers[i]) { // j, k 값
							Rhand[0] = j;
							Rhand[1] = k;
						}
					}
				}
			} else if (numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0) {
				// 가운데 패드
				//System.out.println("2580 눌림");
				for (int j = 0; j < 4; j++) { // 키패드 2차원 배열
					for (int k = 0; k < 3; k++) {
						if (keypad[j][k] == numbers[i]) { // j, k 값
							MRange[0] = j;
							MRange[1] = k;
							//System.out.println(MRange[0]+" "+MRange[1]+"값");														
						}
					}
				}
				
				int LhandRange = Math.abs(Lhand[0] - MRange[0]) + Math.abs(Lhand[1] - MRange[1]);
				//System.out.println("numbers[i]"+numbers[i]+"의LhandRange"+LhandRange);
				int RhandRange = Math.abs(Rhand[0] - MRange[0]) + Math.abs(Rhand[1] - MRange[1]);
				//System.out.println("numbers[i]"+numbers[i]+"의RhandRange"+RhandRange);
				//System.out.println(Rhand[0]+","+MRange[0]+","+Rhand[1]+","+MRange[1]);
				
				if (LhandRange < RhandRange) { //거리가 더 작은 수
					//System.out.println("L R 중 L이 더 작음");
					answer += "L";
					for (int l = 0; l < 4; l++) { // 키패드 2차원 배열
						for (int m = 0; m < 3; m++) {
							if (keypad[l][m] == numbers[i]) { // j, k 값
								Lhand[0] = l;
								Lhand[1] = m;
							}
						}
					}
				} else if (LhandRange > RhandRange) {
					//System.out.println("L R 중 R이 더 작음");
					answer += "R";
					for (int l = 0; l < 4; l++) { // 키패드 2차원 배열
						for (int m = 0; m < 3; m++) {
							if (keypad[l][m] == numbers[i]) { // j, k 값
								Rhand[0] = l;
								Rhand[1] = m;
							}
						}
					}
				}  
					if (LhandRange == RhandRange) {
						//System.out.println("LR이 같음");
						
					if (hand.equals("left")) {
						//System.out.println("왼쪽");
						answer += "L";
						for (int l = 0; l < 4; l++) { // 키패드 2차원 배열
							for (int m = 0; m < 3; m++) {
								if (keypad[l][m] == numbers[i]) { // j, k 값
									Lhand[0] = l;
									Lhand[1] = m;
								}
							}
						}
					} else if (hand.equals("right")) {
						//System.out.println("오른");
						answer += "R";
						for (int l = 0; l < 4; l++) { // 키패드 2차원 배열
							for (int m = 0; m < 3; m++) {
								if (keypad[l][m] == numbers[i]) { // j, k 값
									Rhand[0] = l;
									Rhand[1] = m;
								}
							}
						}
					} 
				}
				

			}
			//for문 종료
			
		}
		return answer;
	}
}