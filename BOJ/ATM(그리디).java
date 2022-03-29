import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static Solution s = new Solution();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(); // 동전의 종류
        int[] time = new int[N]; //
        for (int i = 0; i < N; i++) {
            time[i] = sc.nextInt();
        }

        System.out.println(s.solution(N, time));
    }
}

class Solution {
    public int solution(int N, int[] time) {
        // 그리디 알고리즘:
        // 가장 가치가 높은 동전을 먼저 선택 -> 가격이 초과하면 한단계 낮은 동전
        int answer = 0;

        Arrays.sort(time); //1 2 3 3 4
        for(int i = 0; i<time.length; i++){
            //System.out.println("i:"+i);
            for(int j = N-1; j>=0; j--){
                answer += time[j];
                //System.out.println(answer);
            }
            N--;          
        }
        return answer;
    }
}