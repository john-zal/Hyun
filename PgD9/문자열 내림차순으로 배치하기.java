import java.util.*;
class Solution {
    public String solution(String s) {
        String answer = "";
        char[] ch = s.toCharArray();
        Arrays.sort(ch);
        String sorted_answer = String.valueOf(ch);
       for(int i = s.length()-1; i>=0; i--){
        answer = answer + sorted_answer.charAt(i);
       }
        
        return answer;
    }
}