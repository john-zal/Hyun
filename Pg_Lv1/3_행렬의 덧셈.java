class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int[][] answer = new int[arr1.length][arr1[0].length];
        // [arr1 행의 크기], [arr1 열의 크기]
        
        for(int i = 0; i<arr1.length; i++){ //행
            for(int j = 0; j<arr1[0].length; j++){ // 열
                answer[i][j] = arr1[i][j]+arr2[i][j];
            }
        }
            return answer;
    }
}