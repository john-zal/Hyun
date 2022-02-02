import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//
		int N = sc.nextInt();
		int X = sc.nextInt();
		ArrayList<Integer> num = new ArrayList<>(); 
		
		for(int i =0; i<N; i++) {
			int Y = sc.nextInt();
			if(Y < X) {
				num.add(Y);
			}
		}
		for(int i =0; i<num.size(); i++) {
			System.out.print(num.get(i)+" ");
		}
	}
}