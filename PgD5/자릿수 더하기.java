import java.util.*;

public class Solution {
    public int solution(int n) {
        int answer = 0;
        while(0 != n){
            answer += n %10;
            n/=10;
        }
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

        return answer;
    }
}