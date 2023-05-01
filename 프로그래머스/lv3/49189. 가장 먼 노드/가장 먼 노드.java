import java.util.*;

class Solution {
    
    public int[] dist = new int[20001];
    public int MAX = 50001;
    public PriorityQueue<Integer> pq = new PriorityQueue<>();
    public HashMap<Integer,List<Integer>> conn = new HashMap<>();
    
    public void dijkstra(){
        dist[1] = 0;
        pq.add(1);
        
        while(!pq.isEmpty()){
            int x = pq.poll();            
            for(int next: conn.get(x)){
                if(dist[next] > dist[x] + 1){
                    dist[next] = dist[x] + 1;
                    pq.add(next);
                }
            }
        }
    }
    
    public int solution(int n, int[][] edge) {
        int answer = 0;
        for(int i=1;i<=n;i++) dist[i] = MAX;
        for(int[] e : edge){
            int a = e[0], b = e[1];
            if(!conn.containsKey(a)) conn.put(a, new ArrayList<Integer>());
            if(!conn.containsKey(b)) conn.put(b, new ArrayList<Integer>());
            conn.get(a).add(b);
            conn.get(b).add(a);
        }
        // for(int key: conn.keySet()){
        //     System.out.print(key);
        //     System.out.println(conn.get(key));
        // }
        dijkstra();
        int max_val = 0;
        for(int i=1;i<=n;i++) max_val = Math.max(max_val,dist[i]);
        for(int i=1; i<=n; i++){
            // System.out.println(dist[i]);
            if(dist[i]==max_val) answer+=1;
        }
        return answer;
    }
}