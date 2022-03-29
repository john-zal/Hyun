class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        int[] arr = new int[3];//점수 입력 배열
        char[] ch = dartResult.toCharArray();
        int cnt = 0;
        int temp = 0;
        for(int i = 0; i<dartResult.length(); i++){
            switch(dartResult.charAt(i)){
             case'S': //싱글 
                    arr[cnt] = temp;
                    cnt++;
                    temp = 0;
                    break;
             case'D': //더블 제곱
                    arr[cnt] = temp * temp;
                    cnt++;
                    temp = 0;
                    break;
             case'T': //트리플 세제곱
                    arr[cnt] = temp * temp * temp;
                    cnt++;
                    temp = 0;
                    break;
             case'*': //보너스 (*2)
                    arr[cnt-1] *= 2;
                    if(cnt > 1)
                        arr[cnt-2] *= 2; //앞에 있는것도
                    break;       
             case'#': //패널티 (*-1)
                    arr[cnt-1] *= -1;
                    break;
             default: //정수를 입력 받을 때
                   
                    temp += Character.getNumericValue(ch[i]); //int로 바뀜
                    if(ch[i] == '1' && ch[i+1] == '0')
                        temp = 10;
                    //System.out.println(temp);
            }
            System.out.println(arr[0]+" "+arr[1]+" "+arr[2]);
        }
        for(int i =0; i<arr.length; i++){
            answer +=arr[i];
        }
        
        return answer;
        
    }
}