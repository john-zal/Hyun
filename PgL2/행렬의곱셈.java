class Solution {
	public int[][] solution(int[][] arr1, int[][] arr2) {

		int[][] answer = new int[arr1.length][arr2[0].length];
		for (int i = 0; i < arr1.length; i++) { // 3
			for (int k = 0; k < arr2[0].length; k++) { // 2,3,2
				int sum = 0;
				for (int l = 0; l < arr2.length; l++) {
					sum += arr1[i][l] * arr2[l][k];
					//System.out.println("i,k : "+i+" "+k+"  # l,k : "+l+" "+k+" arr1 x arr2: "+arr1[i][k]+ " "+arr2[l][k]);
					//System.out.println(sum);
				}
				answer[i][k] = sum;
				System.out.println(answer[i][k]);
			}
		}
		return answer;
	}
}