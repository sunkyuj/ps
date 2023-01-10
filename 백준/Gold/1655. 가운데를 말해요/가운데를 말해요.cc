#include <iostream>
#include <queue>

using namespace std;


/// 0~중간값 : maxHeap --> pop 하면 이 중에서 제일 큰 값(중간값) 나옴
/// 중간값~끝 : minHeap --> pop 하면 이 중에서 제일 작은 값(중간값) 나옴

int subin[100001];
int n;
priority_queue <int> maxHeap; ///큰거 먼저 나옴 (작은거중 큰거!), 얘가 항상 더 많거나 같게
priority_queue <int, vector<int>, greater<int>> minHeap; ///작은거 먼저 나옴

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>subin[i];
        maxHeap.push(subin[i]);
        if(maxHeap.size()==minHeap.size()+2){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(!minHeap.empty()&&maxHeap.top()>minHeap.top()){
            int tmp=maxHeap.top();
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(tmp);
        }
        cout<<maxHeap.top()<<"\n";
    }
    return 0;
}