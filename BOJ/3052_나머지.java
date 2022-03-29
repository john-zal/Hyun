import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		ArrayList<Integer> arr = new ArrayList<Integer>(10);
		ArrayList<Integer> arr2 = new ArrayList<Integer>(); //중복 제거 배열 
		for(int i = 0; i<10; i++) {
			int temp = 0;
			temp = sc.nextInt();
			temp%=42;
			arr.add(temp);			
		}
		for(Integer dup : arr) {
			if(!arr2.contains(dup)) //arr2에 arr값이 포함되지 않으면
				arr2.add(dup);
		}
		System.out.println(arr2.size());
	}
}