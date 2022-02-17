import java.util.Scanner;

public class Main {
    //static Solution s = new Solution();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int time = sc.nextInt(); //시
        int min = sc.nextInt(); //분
        int cook = sc.nextInt(); //요리 시간
        
        int[] answer = {0, 0};

        int sum = min+cook;
        while(sum >=60){
            sum -=60;
            time++;
            if(time>=24){
                time -= 24;
            }
        }
        answer[0] = time;
        answer[1] = sum;
        System.out.println(time+" "+sum);

        //System.out.println(s.solution(time, min, cook));        
    }
}

/*class Solution {
    public int solution(int time, int min, int cook) {
        int[] answer = {0, 0};

        int sum = min+cook;
        if(sum >=60){
            sum -=60;
            time++;
            if(time>=24){
                time -= 24;
            }
        }
        answer[0] = time;
        answer[1] = sum;
        System.out.println(time+" "+sum);
        return answer;
    }
}*/
