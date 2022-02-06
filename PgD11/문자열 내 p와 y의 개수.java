class Solution {
    boolean solution(String s) {
        boolean answer = true;
        int a = 0;
        int b = 0;
        char[] ch = s.toCharArray();
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        for(int i =0; i<s.length(); i++){
            if(ch[i] == 'p' || ch[i] == 'P'){
                a++;
                
            }else if(ch[i] == 'y' || ch[i] == 'Y'){
                b++;
            }
        }
        if(a!=b)
            answer=false;
            System.out.println("Hello Java");

        return answer;
    }
}