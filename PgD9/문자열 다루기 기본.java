class Solution {
    public boolean solution(String s) {
        boolean answer = true;
        char[] str = s.toCharArray();
        if(str.length == 4 || str.length == 6){ //길이 4 6사이
            for(int i = 0; i<str.length; i++){ 
                if(str[i] >= '0' && str[i]<= '9'){
                    answer = true;
                }else{
                    answer = false;
                    return answer;
                }
            }
        }else{
            answer = false;
        }      
        return answer;
    }
}