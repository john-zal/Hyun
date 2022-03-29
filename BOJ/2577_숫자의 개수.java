import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int[] arr = new int[3]; //ABC
		int sum = 1;
		int[] cnt = new int[10]; //0~9
		String s = "";
		for(int i = 0; i<arr.length; i++) {
			arr[i] = sc.nextInt();
			sum *= arr[i];
		}
		s = Integer.toString(sum);
		for(int i=0; i<s.length(); i++) {
			cnt[Character.getNumericValue(s.charAt(i))] += 1;
		}
		
		for(int i = 0; i<cnt.length; i++) {
			System.out.println(cnt[i]);
		}	
	}
}