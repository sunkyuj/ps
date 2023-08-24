import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = new String[players.length];
        
        HashMap<String, Integer> nameMap = new HashMap<>();
        HashMap<Integer, String> rankMap = new HashMap<>();
        
        for(int i=0; i<players.length; i++){
            nameMap.put(players[i], i);
            rankMap.put(i, players[i]);
        }
        
        for(String called: callings){
            int rank = nameMap.get(called);
            String enemy = rankMap.get(rank-1);
            
            nameMap.put(called, rank-1);
            nameMap.put(enemy, rank);
            
            rankMap.put(rank, enemy);
            rankMap.put(rank-1, called);
        }
        
        for(int i=0; i<players.length; i++){
            answer[i] = rankMap.get(i);
        } 
        
        return answer;
    }
}