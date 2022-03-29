class Solution {
    public int solution(int n) {
        int answer = 0;
        
        for(int i = 2; i<=n; i++){ // 2~10 숫자 중
            boolean check = true;
            for(int j = 2; j*j<=i; j++){ //만족하지 못하면 i값 증가 2x2 = 4로 같아지고
                if(i%j == 0){ //나머지가 없어졌다면 이 숫자는 소수 아님
                    check =false;
                    break;
                } 
               }
            if(check)
                answer += 1;
               
        }
        return answer;
    }
}