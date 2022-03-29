package programmers;

import java.util.Scanner;
import java.util.Stack;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		//Scanner sc = new Scanner(System.in);
		int brown = 24;
		int yellow = 24;
		
		System.out.println(s.solution(brown,yellow));
	}
}
class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int area = brown+yellow;

        for(int i = 3; i<=(area/2); i++) {
        	if(area%i == 0) {// i=3 48/3  3, 16
        		if((i-2)*((area/i)-2) == yellow) {        
        			answer[0] += (area/i);
        			answer[1] += i;
        			break;
        		}
        	}
        }
        return answer;
    }
}