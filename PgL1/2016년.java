class Solution {
    public String solution(int a, int b) {
       String answer = "";
       String[] date = new String[]{"SUN","MON","TUE","WED","THU","FRI","SAT"};
        //일 월 화 수 목 금 토
        int[] month = new int[] {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                             //1/31 2/28 3/31 4/30 5/31 6/30 7/31 8/31 9/30 10/31 11/30 12/31
        int day= 0;
        int day2 =4; //1월 1일은 금요일
        //윤년 2/29
        for(int i= 1; i< a; i++){ //월
             day += month[i-1];
            }
            day += b;
        
            for(int j = 0; j<day; j++){
                day2++;
                if(day2 > 6){
                    day2 = 0;
                }                                                      
            }            
        answer = date[day2];
        return answer;
    }
}