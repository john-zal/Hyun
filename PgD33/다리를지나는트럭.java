import java.util.LinkedList;
import java.util.Queue;

public class Main {
	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);
		// int n = sc.nextInt();
		Solution s = new Solution();

		int bridge_length = 2;
		int weight = 10;
		int[] truck_weights = { 7, 4, 5, 6 };

		System.out.println(s.solution(bridge_length, weight, truck_weights));
	}
}

class Solution {
	public int solution(int bridge_length, int weight, int[] truck_weights) {

		Queue<Integer> q = new LinkedList<>(); // 트럭 넣을 큐
		int answer = 0; // 몇 초?
		int isfull = 0; // 무게 초과했는지 확인하는 변수
		for (int i = 0; i < truck_weights.length; i++) {
			while(true) {
				if(q.isEmpty()) {
					q.add(truck_weights[i]);
					isfull += truck_weights[i];
					answer++;
					break;
				}else if(q.size() == bridge_length) {
					isfull -= q.poll(); //제일 앞에있던 애가 빠짐
				}else {
					if(isfull + truck_weights[i] <= weight) {
						//덜 찼으면 더 넣어봄
						q.add(truck_weights[i]);
						isfull += truck_weights[i];
						answer++;
						break;
					}else {
						q.add(0);
						answer++;
					}
				}
			}
		}
		return answer+bridge_length;
	}
}
