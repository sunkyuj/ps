#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Node
{
public:
    int parent;
    vector<int> cs;
    Node(){};
    Node(int p) : parent(p){};
    void add(int c)
    {
        cs.push_back(c);
    }
};

int getCommonNode(unordered_map<int, Node> &tree, bool visited[], int a, int b)
{

    int tmp = a;
    while (tmp != 0)
    {
        visited[tmp] = true;
        tmp = tree[tmp].parent;
    }
    tmp = b;

    while (1)
    {
        if (visited[tmp])
            return tmp;
        tmp = tree[tmp].parent;
    }
}

int getTreeSize(unordered_map<int, Node> &tree, int node)
{
    int size = 1;
    for (int c : tree[node].cs)
        size += getTreeSize(tree, c);
    return size;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        int v, e, a, b;
        unordered_map<int, Node> tree;

        cin >> v >> e >> a >> b;
        for (int i = 1; i <= v; i++)
            tree[i] = Node(0);

        for (int i = 0; i < e; i++)
        {
            int p, c;
            cin >> p >> c;
            tree[p].add(c);
            tree[c].parent = p;
        }
        bool visited[10001] = {false};
        int common_node = getCommonNode(tree, visited, a, b);
        int size = getTreeSize(tree, common_node);
        cout << "#" << tc + 1 << " " << common_node << " " << size << "\n";
    }

    return 0;
}