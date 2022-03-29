class Solution {
    public int[] solution(int n, int m) {
        //최대공약수: 서로 공통된 약수 중 가장 큰 자연수
        //최소공배수: 두 수의 공통된 배수 중 가장 작은 수
        int[] answer = new int[2];
        int a = n;
        int b = m;
        answer[0] = 0; //gcd(greatest common division)
        
        while(m!=0){
            int r= n%m;
            n=m;
            m=r;
        }
        answer[0] = n;
        answer[1] = (a*b)/answer[0]; //lcm(lowest common multiple)
        return answer;
        }
}