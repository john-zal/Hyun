class Solution {
    public int solution(int[] arr) {    	    	
    	Arrays.sort(arr);
    	int answer = arr[arr.length-1];
        	for(int j = 0; j<arr.length; j++) {
        		if(answer % arr[j] != 0) {
        			answer += arr[arr.length-1];
        			j = 0;
        		}
        	}       
        return answer;
    }
}