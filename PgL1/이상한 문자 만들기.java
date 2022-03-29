class Solution {
    public String solution(String s) {
        String answer = "";
        String[] arr = s.split(""); //띄어쓴걸 배열로 나눔
        int cnt = 0; //카운트, 자릿수
        
        for(int i = 0; i<arr.length; i++){ // [0] [1] [2]
            if(arr[i].equals(" ")){ 
                cnt = 0; //띄어쓰기면 0으로 초기화(한 단어)
            }else if(cnt % 2 == 0){ //짝수일때 대문자
                arr[i] = arr[i].toUpperCase();
                cnt++;
            }else if(cnt % 2 != 0){ //홀수일때 소문자
                arr[i] = arr[i].toLowerCase();
                cnt++;
            }
            
            answer += arr[i];
            //arr [0] try
            //arr [1] hello
            //arr [2] world
        }
        return answer;
    }
}