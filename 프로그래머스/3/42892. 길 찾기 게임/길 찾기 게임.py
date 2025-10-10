# 3:08

from collections import defaultdict

class BinTree:
    def __init__(self, tup):
        self.root = Node(tup)
        
    def add(self, tup):
        node = Node(tup)
        
        # 내 부모랑, 내 위치 찾기
        p = self.root
        loc = -1
        while True:
            if node.x < p.x:
                loc = 0
            else:
                loc = 1
            
            if p.childs[loc] == None:
                break
            p = p.childs[loc]
    
        p.childs[loc] = node
        
    
    def pre_trav(self):
        path = []
        st = [self.root]
        
        while st:
            node = st.pop()
            path.append(node.idx) # 이거
            if node.childs[1] != None:
                st.append(node.childs[1])
            if node.childs[0] != None:
                st.append(node.childs[0])
        return path
    
    def post_trav(self):
        path = []
        st = [self.root]
        visited = set()
        while st:
            node = st[-1]
            if node.idx in visited:
                st.pop()
                path.append(node.idx) # 이거
                continue
            
            visited.add(node.idx)
            if node.childs[1] != None:
                st.append(node.childs[1])
            if node.childs[0] != None:
                st.append(node.childs[0])
            
        return path

class Node:
    def __init__(self, tup):
        self.idx = tup[2]
        self.x = tup[0]
        self.y = tup[1]
        self.childs = [None, None]

def solution(nodeinfo):
    # 좌표들이 주어짐 (nodeinfo)
    nodeinfo = [nodeinfo[i] + [i+1] for i in range(len(nodeinfo))]
    nodeinfo = list(map(tuple, nodeinfo))
    nodeinfo.sort(key=lambda x: (-x[1], x[0]))
    # print(nodeinfo)
    
    # 트리를 구성한다 (좌표값은 1000이하, 트리 깊이 1000이하인 경우만)
    tree = BinTree(nodeinfo[0])
    for i in range(1,len(nodeinfo)):
        tree.add(nodeinfo[i]) # (x,y)
        
    # 답: [전위순회, 후위순회] 결과
    return [tree.pre_trav(), tree.post_trav()]
    