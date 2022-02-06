class Solution {
    public String solution(String[] seoul) {
        String answer = "";
        for(int i=0; i<seoul.length; i++){
         if(seoul[i].equals("Kim")){ 
         //if(seoul[i] == "Kim"){ // 이렇게 쓰면 틀림
             answer = "김서방은 "+i+2+"에 있다";      
         }
        }
        return answer;
    }
}