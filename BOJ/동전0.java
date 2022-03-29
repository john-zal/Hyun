package programmers;

import java.util.Scanner;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();//돈 종류
		int K = sc.nextInt();//가격
		int[] won = new int[N];
		for(int i =0; i<N; i++) {
			won[i]=sc.nextInt();
		}
		System.out.println(s.solution(N,K,won));
	}
}

class Solution {
	public int solution(int N, int K, int[] won) {
		int answer = 0;
		int price = K;
		//돈을 비교
		for(int i = N-1; i>=0; i--) { // 9 8 7 6 5 4 3 2 1 0
			if( K-won[i] < 0) {
				//System.out.println("생략"+won[i]);
				continue;
			}else {
				int cnt = 1;
				while(K >= won[i]*cnt) { //4790 1000 2000 3000 4000
					//System.out.println("작동");
					cnt++;
				}
				//System.out.println(+i+"번째cnt: "+(cnt-1));
				K -=won[i]*(cnt-1);
				answer+=(cnt-1);
				//System.out.println("answer"+answer);
			}
		}
		return answer;		
	}
}