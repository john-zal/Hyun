import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int[] arr = new int[9];
		int max = 0;
		int idx = 0;
		for(int i = 0; i<arr.length; i++) {
			arr[i] = sc.nextInt();
			if(max<arr[i]) {
				max = arr[i];
				idx = i+1;
			}
		}
		System.out.println(max+"\n"+idx);
	}
}