package programmers;

import java.util.Stack;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);
		// String a = sc.next();

		int[] prices = {1,2,3,2,3};
		System.out.println(s.solution(prices));
	}
}
class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<Integer> stack = new Stack<>(); // 1 2 3 2 3
        
        	for(int i =0; i<prices.length; i++) {  //가격이 떨어지는 주식찾기 4<5 스택이 프라이스보다 작아질때까지 반복
        		//스택이 이전값보다 작아지면 반복문
        		while(!stack.isEmpty() && (prices[i]< prices[stack.peek()])) {
        			answer[stack.peek()] = i - stack.peek(); // 총 걸린 시간 - 크기 줄어들때까지 걸린 시간
        			stack.pop(); //걸린 시간 구했으니 스택 제거
        		}
        		stack.push(i);
        	}
        	//남아있는 스택 : 가격이 떨어지지 않음, 스택의 인덱스가 지속시간동안 감소하지 않은것을 의미
    		while(!stack.isEmpty()) {
    			answer[stack.peek()] = prices.length-stack.peek() -1;
    			stack.pop();
    		}
    		/*for(int i = 0; i<answer.length; i++) {
    			System.out.println(answer[i]);
    		}*/
        return answer;        
    }
}