package programmers;

import java.util.Scanner;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);		
		String a = sc.next();		
		//String a = "55+50-40";
		System.out.println(s.solution(a));
		//55+50-40 = 
		
	}
}

class Solution {
	public int solution(String a) {
		int answer = 0;

		//55+50-40 예시로 설명
		a = a.replaceAll("-", " "); //-부호 기준으로 쪼갠다. 55+50 40
		String[] b = a.split(" "); //b[0] = 55+50, b[1] = 40
		
		for(int i = 0; i< b.length; i++) {
			for(int j = 0; j<b[i].length(); j++) {
				if(b[i].charAt(j) == '+') {// 55+50 이 걸러진다
					String[] c = b[i].split("\\+"); // 55, 50으로 다시 쪼갠다
					int temp = 0;
					for(int k = 0; k<c.length; k++) {
						temp += Integer.parseInt(c[k]); //55, 50을 temp에 더해준다(105)
						//System.out.println("temp: "+temp);
					}
					b[i] = Integer.toString(temp); //55+50 이 105 string로 바뀐다.
				}
			}			
		}
		answer = Integer.parseInt(b[0]); //초기값은 무조건 양수
		for(int i =1; i<b.length; i++) {
			answer -= Integer.parseInt(b[i]);
		}		
		return answer;
	}
}