import java.util.*;



class Solution {
    public static class Node implements Comparable<Node>{
        private int num;
        private int idx;
        
        public Node(int num, int idx){
            this.num = num;
            this.idx = idx;
        }
        
        public int getNum(){
            return num;
        }
        public int getIdx(){
            return idx;
        }
        
        @Override
        public int compareTo(Node o){
            return this.num - o.num;
        }
    }
    
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        for(int i=0; i<answer.length;i++) answer[i] = -1;
        
        PriorityQueue<Node> minHeap = new PriorityQueue<>();
        for(int i=0; i<numbers.length;i++) {
            if(minHeap.isEmpty() || minHeap.peek().getNum() >= numbers[i]) minHeap.add(new Node(numbers[i],i));
            else{
                while(!minHeap.isEmpty() && minHeap.peek().getNum() < numbers[i]){
                    Node node = minHeap.poll();
                    int idx = node.getIdx();
                    answer[idx] = numbers[i];
                }
                minHeap.add(new Node(numbers[i],i));
            }
        }
        
        // while(!minHeap.isEmpty()) System.out.println(minHeap.poll().getNum());
        
        
        
        return answer;
    }
}