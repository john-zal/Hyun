class Solution {
    public String solution(String s) {
        String answer = "";
        s = s.toLowerCase();
        String temp = "";
        String[] arr = s.split(" "); //3people, unFollowed me
        if(s.substring(s.length()-1, s.length()).equals(" ")) {
        	//끝에가 존재하면
        	arr[arr.length-1]+=" ";
        }
        /*for(int i = 0; i<arr.length; i++) {
        	System.out.println(arr[i]);
        	System.out.println(arr[i].length());
        }*/
        for(int i = 0; i<arr.length; i++) {    	  
        	if(arr[i].length() == 0) {
        		continue;
        	}
        	temp = arr[i].substring(0, 1); // 3        	
        	temp = temp.toUpperCase(); //대문자 변환
     	
        	arr[i] = temp+arr[i].substring(1); // people        
        	//System.out.println(arr[i]);
        }
        for(int i=0; i<arr.length; i++) {
        	//System.out.println(arr[arr.length-1]);
        	if(arr[i] == arr[arr.length-1]) {
        	answer += arr[i];
        	break;
        	}
        	answer += arr[i]+" ";
        }
        return answer;
    }
}