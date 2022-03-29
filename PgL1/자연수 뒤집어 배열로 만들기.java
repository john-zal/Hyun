class Solution {
    public int[] solution(long n) {
        String str = String.valueOf(n); 
        //long n을 valueOf로 String형으로 변환
        
        int[] answer = new int[str.length()];
        int count = 0;
        
        while(n>0){
            answer[count]=(int)(n%10);
            n/=10;
            count++;
            //12345
            //answer[0] = 5 1234
            //answer[1] = 4 123
            //answer[2] = 3 12
            //answer[3] = 2 1
            //answer[4] = 1 null
        }
        
        return answer;
    }
}