import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public int[] solution(int[] numbers) {
        ArrayList<Integer> num = new ArrayList<Integer>();
        
        
        
        for(int i = 0; i<numbers.length; i++){
            for(int j = i+1; j<numbers.length; j++){
                int add = numbers[i] + numbers[j];            
                if(num.indexOf(add) < 0){ 
                //인덱스 검색 결과 값이 0 (안들어있으면)
                    num.add(add);
                }
            }
        }
        int[] answer = new int[num.size()];
        for(int i = 0; i<num.size(); i++){
            answer[i] = num.get(i);
        }
        Arrays.sort(answer);
        
        return answer;
    }
}