class Solution {
    public boolean solution(int x) {
        boolean answer;
        int X =x;
        int sum = 0; //?먮┸?섏쓽 ??
        while(x!=0){ 
            sum += x%10;
            x /= 10;
        }
        if(X%sum == 0){
            answer = true;
            System.out.println(X%sum);
        }else
            answer = false;
      return answer;
    }
}
