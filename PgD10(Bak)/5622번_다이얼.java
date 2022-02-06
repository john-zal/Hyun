import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//대문자 입력
		int cnt = 0;
		String str = sc.nextLine();
		char[] arr = str.toCharArray();
		for(int i= 0; i<str.length(); i++) {
			if(arr[i] >= 'A' && arr[i] <= 'C') {
				arr[i] = '2';
				cnt += 3;
			}else if(arr[i] >= 'D' && arr[i] <= 'F') {
				arr[i] = '3';
				cnt += 4;
			}else if(arr[i] >= 'G' && arr[i] <= 'I') {
				arr[i] = '4';
				cnt += 5;
			}else if(arr[i] >= 'J' && arr[i] <= 'L') {
				arr[i] = '5';
				cnt += 6;
			}else if(arr[i] >= 'M' && arr[i] <= 'O') {
				arr[i] = '6';
				cnt += 7;
			}else if(arr[i] >= 'P' && arr[i] <= 'S') {
				arr[i] = '7';
				cnt += 8;
			}else if(arr[i] >= 'T' && arr[i] <= 'V') {
				arr[i] = '8';
				cnt += 9;
			}else if(arr[i] >= 'W' && arr[i] <= 'Z') {
				arr[i] = '9';
				cnt += 10;
			}
		}
		System.out.println(cnt);
	}
}
