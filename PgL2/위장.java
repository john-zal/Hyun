import java.util.ArrayList;
import java.util.HashMap;

class Solution {
	public int solution(String[][] clothes) {
		HashMap<String, ArrayList<String>> hash = new HashMap<>();
		ArrayList<String> list;
		int answer = 1;

		for (int i = 0; i < clothes.length; i++) { // 3
			list = new ArrayList<>();
			if (hash.get(clothes[i][1]) != null) { // 얻을 키값이 비어있지 않으면(중복이면)
					list = hash.get(clothes[i][1]);// 키값 얻어옴
			}
				list.add(clothes[i][0]); // 그 키값 항목에 밸류값 추가
				hash.put(clothes[i][1], list);// 해시로 정리			
		}
		for(String s : hash.keySet()) { //현존하는 모든 키값의 개수를 알려주는 함수
									    //헤드기어, 아이웨어, 헤드기어 반환
			answer *= hash.get(s).size()+1;
		}			
		return --answer;
	}
}