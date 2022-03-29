class Solution {
    public long solution(int a, int b) {
        long answer = 0;
        int temp = 0;
        if(a == b){
            answer = a;
        }else if(b < a){ //a가 크면
            temp = a;
             a = b;
             b = temp;
        }else if(a < b){ //b가 크면
            temp = b;
        }
        for(int i = a; i<=temp; i++){
            answer += (long)i;
        }
        return answer;
    }
}