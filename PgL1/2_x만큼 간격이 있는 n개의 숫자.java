class Solution {
    public long[] solution(int x, int n) {
        long[] answer = new long[n]; //자연수 n갯수만큼의 배열 생성
        long number = x;  // 정수 x는 signed
        for(int i = 0; i<answer.length; i++){
            answer [i] =  number; //배열에 number(정수 반영)
            number += x;
        }
        return answer;
    }
}