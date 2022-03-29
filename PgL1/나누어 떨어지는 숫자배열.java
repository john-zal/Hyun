import java.util.Arrays;
class Solution {
    public int[] solution(int[] arr, int divisor) {
        
        int[] noanswer = {-1};
        int cntA = 0;
        int cntB = 0;
        int n = arr.length;
                for(int i = 0; i< arr.length; i++){ //나누어 떨어지는 
            if(arr[i] % divisor == 0){ //n에 나누어 떨어질 때     
                cntA++;
            }
        }                    
        int[] answer = new int[cntA];
        int j = 0;       
        for(int i = 0; i< arr.length; i++){
            if(arr[i] % divisor == 0){ //n에 나누어 떨어질 때
                answer[j] = arr[i];
                j++;
            }else{
                cntB++;
            }
        }
   
        //하나도 나누어 떨어지지 않을 때
        if(cntB == n){
           return noanswer;
        }
        Arrays.sort(answer);
        return answer;
    }
}