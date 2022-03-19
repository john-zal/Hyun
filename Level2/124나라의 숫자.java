class Solution {
    public String solution(int n) {
        String answer = "";     
        int temp = 0;
        while(n != 0) {
        	temp =  n % 3;  //15 % 3
        	n /= 3;      	
        	if(temp == 0) //0으로 나누어 떨어지면
        	{
        		n -= 1; //n 5-> 4
        		answer = "4"+answer;
        	}
        	else {
        		answer = Integer.toString(temp) + answer;
        	}
        }
        return answer;
    }    	
}