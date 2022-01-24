class Solution {
    public String solution(String phone_number) {
        String answer = "";
        for(int i = 0; i<phone_number.length()-4; i++){ //폰넘버
            answer += "*";
        }
        for(int i = phone_number.length()-4; i<phone_number.length(); i++){
            //폰넘버-4 부터~ 폰넘버 마지막까지
            answer += phone_number.charAt(i);
        }
            
        return answer;
    }
}