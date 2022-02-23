import java.util.Arrays;
class Solution {
	public int solution(int[] people, int limit) {
        int answer = 0;
        int sum =0;    
        int idx = 0;
        Arrays.sort(people); //50/50/70/80
        
        for(int i= people.length-1; i>=idx; i--) { //제일 무거운놈
        	if(people[i] + people[idx] <= limit) { //초과안하거나 같으면
        		idx++; //앞에 있는애도 태웠음
        		answer++; //태워보냄        		
        	}else { //혼자밖에 못타면
        		answer++;
        	}
        	
        }        	
        	return answer;
    }
}