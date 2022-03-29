import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cnt = 0; //N의 사이클
		int N = sc.nextInt(); //입력받는 수 N
		int result = N; //결과값
		int a = 0;
		int b = 0;
		int sum = 0; //더한 숫자
		boolean check = true;
			
		while(true){							
					a = N/10; 
					b = N%10;
					sum = a+b; 
					if(sum>=10) {
						sum %= 10;
					}
					cnt++;
					N = (b*10)+sum;
					
					if(N==result) {
						check = false;
						break;
					}
		
		}
		//System.out.println("sum: "+sum);
		System.out.println(cnt);	
		return;
	}
}
