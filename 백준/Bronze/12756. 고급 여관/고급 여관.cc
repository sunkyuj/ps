#include <iostream>

using namespace std;
void f(int a_dmg,int a_life,int b_dmg,int b_life){
    if(a_life<=0&&b_life<=0){
        cout<<"DRAW";
        return;
    }
    else if(a_life<=0){
        cout <<"PLAYER B";
        return;
    }
    else if(b_life<=0){
        cout <<"PLAYER A";
        return;
    }
    else
        f(a_dmg, a_life-b_dmg, b_dmg, b_life-a_dmg);
}
int main()
{
    int a_dmg,a_life,b_dmg,b_life;
    cin >> a_dmg >> a_life >> b_dmg >> b_life;
    f(a_dmg, a_life, b_dmg, b_life);
    return 0;
}
