import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";        
        String[] num = new String[numbers.length];
        for(int i = 0; i<num.length; i++) {
        	num[i] = Integer.toString(numbers[i]);        	
        }        
        //μ½λ
        Arrays.sort(num, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {				
				return (o2+o1).compareTo(o1+o2);
			}	
        });

         //0000μΌλ 
        if(num[0].equals("0"))        
        return "0";
        
        for(int i = 0; i<num.length; i++) {
        	answer +=num[i];
        }
        return answer;
    }
}