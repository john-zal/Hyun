import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections; //array리스트 정렬에 필요
class Solution {
    public String[] solution(String[] strings, int n) {
       //인덱스 문자를 스트링 맨 앞에 가져온 다음 정렬 
        String[] answer = {};
        ArrayList<String> arr = new ArrayList<>();
        Arrays.sort(strings);
        
    
        for(int i = 0; i<strings.length; i++){
            arr.add(""+strings[i].charAt(n)+strings[i]); //usun, ebed, acar       
            }
            Collections.sort(arr); //정렬 acar ,ebed, usun
            
            //맨 앞에 있는 문자 빼주기
            answer = new String[arr.size()]; //arr 크기 3
            for(int i =0; i<arr.size(); i++){
                answer[i] = arr.get(i).substring(1, arr.get(i).length()); 
                //서브스트링으로 특정 위치 문자열 만 출력(인덱스 0 빼고 다)
            }
        return answer;
    }
}