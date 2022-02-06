import java.util.*;
import java.util.ArrayList;

public class Solution {
    public ArrayList<Integer> solution(int []arr) {
        ArrayList<Integer> num = new ArrayList<Integer>();
        
            
        for(int i=0; i<arr.length; i++){            
            if(i>0 && arr[i-1] == arr[i]){
              continue;
            }
                num.add(arr[i]);
        }
            return num;        
    }
}