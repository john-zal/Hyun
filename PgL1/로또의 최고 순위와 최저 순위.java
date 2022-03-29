class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        
    	int[] answer = {0, 0};
    	int cnt = 0; //일치하는 번호
    	int zero = 0; //가능성 있는 번호
    	int rank = 6 ;
    	for(int i = 0; i<win_nums.length; i++) {
    		if(lottos[i] == 0) {
				zero++;}
    		for(int j = 0; j<lottos.length; j++) {
    			if(win_nums[i] == lottos[j]) {
    				cnt++;   				
    			}
    		}
    	}
    	System.out.println("cnt, zero"+cnt+" "+zero);
    	answer[0] = (rank+1)-(cnt+zero);//
    	answer[1] = (rank+1)-(cnt);//
    	for(int i =0; i<answer.length; i++) {
    		if(answer[i] >6) {
    			answer[i] = 6;
    		}
    	}
    	System.out.println(answer[0]+" "+answer[1]);
        return answer;
    }
}