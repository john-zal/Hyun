import java.util.Arrays;
class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int pick = nums.length/2;
        //N 마리중 절반 가져가기
        int temp = 0;
        Arrays.sort(nums);
             
        for(int i =0; i<nums.length; i++) { //0 1 2 3
        	if(temp != nums[i]) {
        		temp = nums[i];
        		answer++;
        	}	
        }
        if(answer > pick) {
        	answer = pick;
        }        
        return answer;
    }
}