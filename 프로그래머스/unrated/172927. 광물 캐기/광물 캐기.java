class Solution {
    int DIA = 25, IRON = 5, STONE = 1;
    int answer = 0;
    int n;
    int[] mins = new int[50];
    
    public int f(int idx, int[] picks){
        if(idx>=n) return 0;
        
        int min = Integer.MAX_VALUE;
        //dia
        if(picks[0]!=0){
            picks[0]--;
            int pick = DIA;
            int energy = 0;
            for(int i=idx; i<n && i<idx+5; i++){
                energy++;
            }
            min = Math.min(min, energy + f(idx+5,picks));
            picks[0]++;
        }
        //iron
        if(picks[1]!=0){
            picks[1]--;
            int pick = IRON;
            int energy = 0;
            for(int i=idx; i<n && i<idx+5; i++){
                energy+=mins[i]/pick + mins[i]%pick;
            }
            min = Math.min(min, energy + f(idx+5,picks));
            picks[1]++;
        }
        //stone
        if(picks[2]!=0){
            picks[2]--;
            int pick = STONE;
            int energy = 0;
            for(int i=idx; i<n && i<idx+5; i++){
                energy+=mins[i];
            }
            min = Math.min(min, energy + f(idx+5,picks));
            picks[2]++;
        }
        if(min==Integer.MAX_VALUE) return 0;
        return min;
    }
    
    public int solution(int[] picks, String[] minerals) {
        n=minerals.length;
        for(int i=0;i<n;i++){
            if(minerals[i].equals("diamond")) mins[i]=DIA;
            if(minerals[i].equals("iron")) mins[i]=IRON;
            if(minerals[i].equals("stone")) mins[i]=STONE;
        }
        
        return f(0,picks);
    }
}