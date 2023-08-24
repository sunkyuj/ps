import java.util.*;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = new int[photo.length];
        
        Map<String, Integer> scoreMap = new HashMap<>();
        
        for(int i=0; i<name.length;i++){
            scoreMap.put(name[i], yearning[i]);
        }
        for(int i=0;i<photo.length;i++){
            for(String nm: photo[i]){
                if(!scoreMap.containsKey(nm)) continue;
                answer[i] += scoreMap.get(nm);
            }
        }
        
        return answer;
    }
}