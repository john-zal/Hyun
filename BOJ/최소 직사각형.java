class Solution {
    public int solution(int[][] sizes) {  //4 2
        int answer = 0;
        int minsize = 0; //세로 사이즈
        int maxsize = 0;
        int temp = 0;
        for(int i =0; i<sizes.length; i++){ //
                if(sizes[i][0] < sizes[i][1]){ //세로 길이가 더 길면 스위칭
                    temp = sizes[i][0];
                     sizes[i][0] = sizes[i][1];
                    sizes[i][1] = temp;
                }
                if(sizes[i][0]>maxsize){ //최대 길이 찾아내기(최대 길이가 가로)
                    maxsize = sizes[i][0];
                }
                 if(sizes[i][1]>minsize){
                     minsize = sizes[i][1];
                 }     
        }
        answer = maxsize * minsize;
        return answer;
    }
}