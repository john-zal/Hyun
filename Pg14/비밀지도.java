class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        //n 한 변의 길이, 
        String[] answer = new String[n];
        String[] binarr = new String[n];
        
        		for(int i = 0; i<n; i++) {
			binarr[i] = Integer.toBinaryString(arr1[i] | arr2[i]);
    			while(binarr[i].length()<n) {
				binarr[i] = "0"+binarr[i];
			}
			answer[i] = "";
			for(int j =0; j<n; j++) {
				if(binarr[i].charAt(j)== '1') {
					answer[i] += "#";
				}else {
					answer[i] += " ";
				}
                }	
			}
			return answer;
    }
}