import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt(); //과목의 개수
		int[] sub = new int[N]; //각 과목의 점수
		int M = 0; //최고점수 과목
		for(int i = 0; i<N; i++) {
			sub[i] = sc.nextInt();//과목 입력받기
			if(M<sub[i]) {//최대점수 과목
				M = sub[i];
			}
		}
		double sum = 0;
		for(int i = 0; i<sub.length; i++) {
			sum += (double)sub[i]/(double)M*100;
		}
		sum = sum/N;
		System.out.println(sum);
	}
}