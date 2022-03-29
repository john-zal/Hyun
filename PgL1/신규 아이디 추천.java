package programmers;

import java.util.ArrayList;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);

		String new_id = "...!@BaT#*..y.abcdefghijklm";
		System.out.println(s.solution(new_id));
	}
}

class Solution {
    public String solution(String new_id) {
        String answer = new_id.toLowerCase(); //1단계 대문자 소문자로 변경
       
        answer = answer.replaceAll("[^a-z0-9-_.]",""); //2단계 소문자,숫자  -, _, 마침표. 제외한 모든 특수문자 제거
        answer = answer.replaceAll("\\.{2,}","."); //3단계 \\.(마침표가) {2, }(2회 이상일 시) .으로 치환
        answer = answer.replaceAll("^[.]|[.]$", "");//4단계 ^[.] ^: 시작(마침표로 시작) $(끝)
        if(answer.isEmpty()) { //5단계?
        	answer = "a";
        }
        //6단계
        if(answer.length() >= 16) { //6단계 문자열 길이가 16이상이면 
        	answer = answer.substring(0, 15);
        	//만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거
        	answer = answer.replaceAll("[.]$","");
        }
        // 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
        while(answer.length()<3) {
        	answer += answer.charAt(answer.length()-1); //new id의 마지막 문자
        }
        System.out.println(answer);
        return answer;
    }
}