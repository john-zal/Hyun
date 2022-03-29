import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//
		int n = sc.nextInt();
		Solution s = new Solution();		
		System.out.println(s.fibo(n));
	}
}
class Solution{
	public int fibo(int n) {
		if(n<=1)
			return n;
		else
			return fibo(n-1)+fibo(n-2);
	}
}
