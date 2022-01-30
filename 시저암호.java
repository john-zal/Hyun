class Solution {
    public String solution(String s, int n) {
        String answer = "";
        char[] ch = s.toCharArray();//문자열을 char 배열로 변환
        for(int i=0; i<ch.length; i++){
                if(ch[i] >= 'a' && ch[i] <= 'z' ){//소문자 a~z 사이
                    if(ch[i]+n > 'z'){ //z에서 넘어가면
                        
                        //ch[i] = 'a'-1;
                        ch[i] += n;
                        ch[i] -= 26;
                        
                    }else{
                        ch[i] += n;
                    }
            }else if (ch[i] >= 'A' && ch[i] <= 'Z'){ //대문자 A~Z 사이
                    if(ch[i]+n > 'Z'){ //Z에서 넘어가면
                        
                        //ch[i] = 'A'-1;
                        ch[i] += n;
                        ch[i] -= 26;
                        
                    }else{
                        ch[i] += n;
                    }
                }else{ //공백
                    ch[i] = ch[i];
                }
                
        }
        answer = new String(ch);
        ///System.out.println(ch[0]);
         return answer;
    }
}