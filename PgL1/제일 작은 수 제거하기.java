class Solution {
    public int[] solution(int[] arr) {

        //배열이 하나일때
         if(arr.length==1){ //배열의 길이가 하나면
            int[] answer = {-1}; //-1을 반환*/
             return answer;
        }
        
        //배열에 제일 작은 수 검출하기
        
        int min = 0; //가장 작은 수      
        for(int i = 0; i<arr.length; i++){ //i<4 0, 1, 2, 3
            if(arr[min] > arr[i]){ 
                min = i;
                }
            }
        
        //제일 작은 수 빠진 배열 만들기
        int[] answer = new int[arr.length-1];
        int cnt = 0;
        for(int i = 0; i<arr.length; i++){
            if(arr[min] < arr[i]){ // 0:4 1:3 2:2 3:1
                answer[cnt] = arr[i];
                cnt++;
            }
        }
        return answer;
        }
}