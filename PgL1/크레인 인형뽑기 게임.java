package programmers;

import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	static Solution s = new Solution();

	public static void main(String[] args) {
		// Scanner sc = new Scanner(System.in);
		
		int[][] board ={{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
		int[] moves = {1,5,3,5,1,2,1,4};
		System.out.println(s.solution(board, moves));
	}
}

class Solution {
	public int solution(int[][] board, int[] moves) {
        // 스택 사용    	
    	//같은 인형 2칸쌓으면 터짐
    	//인형이 없는곳에서 크레인 작동시 아무 일도 일어나지 앟음
    	//result 사라진 인형 = answer
    	
    	Stack<Integer> stack = new Stack<>();
    	int answer = 0; //터진 인형 개수

    	for(int i = 0; i<moves.length; i++) { // 크레인 횟수만큼 반복 0 1 2 3 4 5 6 7
    		for(int j = 0; j<board.length; j++) { //5번
    			if(board[j][moves[i]-1] != 0){ //맨 위에서 시작해서 해당위치에 인형값이 나올때까지 반복
    				stack.add(board[j][moves[i]-1]); //인형을 찾으면 스택에 추가   				 				
    				//System.out.println("추가된 스택: "+stack);   				

    				//스택 삭제 연산
    				if(stack.size() > 1 && stack.get(stack.size()-1) == stack.get(stack.size()-2)) {
    					//쌓은 스택과 그 이전 스택 크기를 비교하여 같으면
    					stack.pop();
    					stack.pop();
    					//System.out.println("스택 수정: "+stack);
    					answer +=2;
    						
    				}
    				
					board[j][moves[i]-1] = 0; //가져온 인형 부분은 0으로 초기화
					break;  
    			}    				
    		}

    	}//i for문 종료
        return answer;
    }
}