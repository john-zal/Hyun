package programmers;

import java.util.ArrayList;


public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);

		int[] nums = { 1,2,7,6,4 };
		System.out.println(s.solution(nums));
	}
}

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int sum = 0;
       
        for(int i = 0; i<nums.length-2; i++) { // 1 , 2, 7
        	for(int j = i+1; j<nums.length-1; j++) { // 2 7 6
        		for(int k = j+1; k<nums.length; k++) { // 7 6 4
        			//더한 수 소수 판별
        			//System.out.println(nums[i]+" "+nums[j]+" "+nums[k]);
        			sum = nums[i]+nums[j]+nums[k];
        			int cnt = 0;
        			for(int m = 2; m<sum; m++) { //2,3,4,5,6 7       				
        				if(sum % m ==0) { //나눠지면
        					continue;
        				}else { //안나눠지면
        					cnt++;
        					if(sum-2 == cnt) {
        						answer++;
        						continue;
        					}
        				}
        			}
        		}
        	}
        }
        return answer;
    }
}