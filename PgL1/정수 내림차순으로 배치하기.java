import java.util.Arrays;
import java.util.Collections;
class Solution {
    public long solution(long n) {
        //입력받은 자릿수만큼 배열을만듦
        int cnt = 0; //자릿수
        long N = n; 
        long answer = 0;
        while(n!=0){ //몇자릿수인지 판단
            n/=10;
            cnt++; //11837 1183 118 11 1
        }
        long arr [] = new long[(int)cnt];
        int length = (int)cnt;
        while(N !=0){
            for(int i= 0; i<length; i++){
                arr[i] = N%10;
                N/=10;
            }
        }
        Arrays.sort(arr);
        for(int i=0; i<arr.length; i++){
            answer += arr[i]*Math.pow(10, i);
            
        }
        return answer;
    }
}
//형변환, 정렬