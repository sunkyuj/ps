class Solution {
    String[] org_board;
    char[][] bd = new char[][] {{'.','.','.'},{'.','.','.'},{'.','.','.'}}; 
    int answer = 0;
    
    public void f(char ox){
        if(answer==1) return;
        if(same()){
            answer=1;
            return;
        }
        if(win()) return;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(bd[i][j]=='.' && org_board[i].charAt(j)!='.'){
                    bd[i][j]=ox;
                    f((ox=='O')? 'X':'O');
                    bd[i][j]='.';
                }
            }
        } 
    }
    public boolean same(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(bd[i][j]!=org_board[i].charAt(j)) return false;
            }
        }
        return true;
    }
    public boolean win(){
        
        for(int i=0;i<3;i++){
            if(bd[i][1] != '.' && bd[i][0]==bd[i][1] && bd[i][1]==bd[i][2]) return true;
        }
        for(int j=0;j<3;j++){
            if(bd[1][j] != '.' && bd[0][j]==bd[1][j] && bd[1][j]==bd[2][j]) return true;
        }
        if(bd[1][1] != '.' && bd[0][0]==bd[1][1] && bd[1][1]==bd[2][2]) return true;
        if(bd[1][1] != '.' && bd[2][0]==bd[1][1] && bd[1][1]==bd[0][2]) return true;
        return false;
    }
    
    public int solution(String[] board) {
        org_board = board;
        f('O');
        return answer;
    }
}