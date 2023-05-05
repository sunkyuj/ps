class Solution {
    public int MAX = 24*60 + 10; // 청소시간 포함
    
    public int getTime(String stime){
        int h = Integer.parseInt(stime.split(":")[0]) * 60;
        int m = Integer.parseInt(stime.split(":")[1]);
        return h+m;        
    }
    public int solution(String[][] book_time) {
        int answer = 0;
        int[] room = new int[MAX+1];
        for(String[] bt: book_time){
            int start = getTime(bt[0]), end = getTime(bt[1]);
            room[start]++;
            room[end+10]--; // 청소시간 포함
        }
        
        for(int i=1; i<MAX;i++){
            room[i] += room[i-1];
            answer = Math.max(answer,room[i]);
        }
        return answer;
    }
}