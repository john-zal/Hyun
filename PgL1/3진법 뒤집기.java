class Solution {
    public int solution(int n) {
        int answer = 0;
        int a = n;
        String b = "";
        while(a  !=  0) {
           b += Integer.toString(a%3);	
           a = a/3;
        }
        for(int i = 0; i < b.length(); i++) { // 0 1 2 3                   
        	answer += Character.getNumericValue(b.charAt(i))*(int)Math.pow(3, b.length()-i-1);
        }
        return answer;
    }
}