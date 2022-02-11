class Solution {
    public int solution(int left, int right) {
    	int answer = 0;
        int[] a = new int[right-left+1];
        int cnt = 0; //약수 개수 판별
        for(int i = left; i<=right; i++) {
        	for(int j = 1; j<=i; j++){//i의 약수를 구하는 for문 1~13
        		if(i%j == 0) {
        			cnt++;
        		}
        	}
    		if(cnt % 2 == 0) { //짝수면
    			answer += i; //더해줌
    		}else { //홀수면
    			answer -= i; //빼줌
    		}
    		cnt = 0;
        }  	
        return answer;
    }
}