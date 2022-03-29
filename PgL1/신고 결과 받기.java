package programmers;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);
		// String a = sc.next();

		String[] id_list = { "con", "ryan" }; // 이용자 ID 문자열 배열
		String[] report = { "ryan con", "ryan con", "ryan con", "ryan con"};
		// 각 이용자가 신고한 이용자의 ID정보가 담긴 문자열 배열
		// 유저 id를 값 1 값 2로 나눠본다
		int k = 2; // 신고 횟수 기준
		System.out.println(s.solution(id_list, report, k));
	}
}

class Solution {
	public int[] solution(String[] id_list, String[] report, int k) {

		
		// 중복 제거
		ArrayList<String> report2 = new ArrayList<String>();
		for(int i = 0; i<report.length; i++) {
			report2.add(report[i]);
		}
		Set<String> set = new HashSet<String>(report2);
		ArrayList<String> report3 =new ArrayList<String>(set);
		//System.out.println("리폿3: "+report3);
		String[] report4 = new String[report3.size()];
		for(int i = 0; i<report3.size(); i++) {
			report4[i] = report3.get(i);
			//System.out.println(" dd "+report4[i]);
		}
	
		
		Map<String, Integer> ban = new HashMap(); // 해시맵 생성 정지된 아이디
		Map<String, String> rep = new HashMap(); // 리폿한 아이디

		// 초기화
		for (int i = 0; i < id_list.length; i++) {
			rep.put(id_list[i], null);
			//System.out.println("멤버"+rep);
			ban.put(id_list[i], 0);
		}
		

		for (int i = 0; i < report4.length; i++) { // 신고당한 멤버, 신고한 멤버 분류
			String[] temp = report4[i].split(" "); // 신고 멤버 짜르기

			ban.put(temp[1], ban.get(temp[1]) + 1); // 밴카운트 ++

			if (rep.get(temp[0]) == null) { // 처음에 빈 공간일때
				rep.put(temp[0], temp[1]);
			} else {
				temp[1] = rep.get(temp[0]) + " " + temp[1]; // 단어 추가
				rep.put(temp[0], temp[1]);
			}
			//System.out.println("리폿: " + rep);
			//System.out.println("밴: " + ban);			
		}
		// 밴 추출
		ArrayList<String> ban_members = new ArrayList<>();   
		for(int i = 0; i<ban.size(); i++) {
			if(ban.get(id_list[i]) >= k) { //벤 수치 k보다 값이 크거나 같으면
				ban_members.add(id_list[i]);				
			}
		}
		//System.out.println(ban_members);
		//처리 결과 메일 신고한 아이디와 비교해서 카운트 추가
		
		int cnt = 0;
		int[] answer = new int[id_list.length];
		for(int i = 0; i<rep.size(); i++) {
			//쪼개기			
			String temp = rep.get(id_list[i]);
			String[] splitemp = {""};
			//System.out.println("템프: "+temp);
			if(temp == null) {
				//System.out.println("템프 빈값");				
			}else {
				splitemp = temp.split(" ");
			}	
			for(int j = 0; j<splitemp.length; j++) {
				for(int l = 0; l<ban_members.size(); l++) {
					if(splitemp[j].equals(ban_members.get(l))) {
						//System.out.println(splitemp[j]+"와"+ban_members.get(l)+"가 같음");
						answer[i] += 1;
					}
				}
			}
		}
		/*for(int i=0; i<answer.length; i++) {
			System.out.println(answer[i]);
		}*/
		return answer;
	}
}