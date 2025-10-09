# 9:51
class LinkedList:
    def __init__(self, n, k):
        self.ll = [Node(i) for i in range(n)]
        for i in range(n):
            if i == 0:
                self.ll[i].nxt = self.ll[i+1]
            elif i == n-1:
                self.ll[i].prev = self.ll[i-1]
            else:
                self.ll[i].prev = self.ll[i-1]
                self.ll[i].nxt = self.ll[i+1]
        
        self.cur = self.ll[k]
        self.stack = []
    
    def up(self, val): # 위로 선택행이 움직임
        for i in range(val):
            self.cur = self.cur.prev
    
    def down(self, val): # 아래로 선택행이 움직임
        for i in range(val):
            self.cur = self.cur.nxt
    
    def remove(self): # 현재 삭제 후 아래행 선택, 만약 맨 아래면 바로 윗행
        p = self.cur.prev
        n = self.cur.nxt
        
        # 삭제
        self.cur.exists = False
        self.stack.append(self.cur)
        
        # 앞뒤 연결
        if p != None and n != None: # 중간
            p.nxt = n 
            n.prev = p
            self.cur = n # 아래행 선택
        elif p != None: # cur가 마지막
            p.nxt = None 
            self.cur = p # 마지막이면 예외로 윗놈 선택
        elif n != None: # cur가 처음
            n.prev = None 
            self.cur = n # 아래행 선택
        else: # cur가 유일
            pass # 이 케이스 없음
        
        
    def undo(self): # 가장 최근 삭제 행 복구, 선택 행은 안 바뀜
        top = self.stack.pop()
        
        top.exists = True
        p = top.prev
        n = top.nxt
        # 앞뒤 연결
        if p != None and n != None: # 중간
            p.nxt = top
            n.prev = top
        elif p != None: # 삭제했던게 마지막
            p.nxt = top 
        elif n != None: # 삭제했던게 처음
            n.prev = top 
        else: # cur가 유일
            pass # 이 케이스 없음
    
    def print(self):
        s = ''
        for node in self.ll:
            s += "O" if node.exists else "X"
        return s
class Node:
    def __init__(self, idx):
        self.idx = idx
        self.prev = None
        self.nxt = None
        self.exists = True
    

def solution(n, k, cmd):
    answer = ''
    # n 100만, cmd 20만
    ll = LinkedList(n,k)
    
    for c in cmd:
        if c[0] == "U":
            _, sval = c.split()
            val = int(sval)
            ll.up(val)
        
        elif c[0] == "D":
            _, sval = c.split()
            val = int(sval)
            ll.down(val)
            
        elif c[0] == "C":
            ll.remove()
        else:
            ll.undo()
            
    return ll.print()