class Solution {
    public long solution(int price, int money, int count) {
        
        long answer = 0;
        long sum = 0;
        int p = price;
        long fullprice= 0;
        for (int i = 1; i<= count; i++){
              price = price * i;
              sum = price;
              fullprice += sum;  
              price =(int)p;                
              //System.out.println(sum);
         }
            if((long)(fullprice-money)> 0){
            answer =(long)(fullprice-money);
            }else {
                answer = 0;
            }    
        return answer;
    }
}