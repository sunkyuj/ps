#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <string>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

string T, P;

vector<int> ans;
int k[1000001];


/*
ABABCABABABCABABAB
ABABCABABAB
*/


int main()
{
    FIO;

    getline(cin, T);
    getline(cin, P);
    int Tl = T.size(), Pl = P.size();


    if (Tl < Pl) {
        cout << "0\n";
        return 0;
    }

    int cnt = 0;
    int begin = 1;
    int m = 0;

    while (begin + m < Pl) { //접두사와 접미사 같은 부분의 개수
        if (P[begin + m] == P[m]) {
            m++;
            k[begin + m - 1] = m;
        }
        else { //m번째 P (P[m])에서 틀림
            if (m == 0) {
                begin++;
            }
            else {
                begin += (m - k[m - 1]);
                m = k[m - 1];
            }
        }
        //if (k[begin] < cnt) k[begin] = cnt;
    }
    /*
    for (int j = 1; j < P.size(); j++) {// get k
        if (P[m] == P[j+m]) cnt++;
        else m = 0;
        if (k[j] < cnt) k[j] = cnt;
    }

    for (int j = 0; j < P.size(); j++) {
        cout << k[j] << " ";
    }
    cout << "\n";
    */
    /*

ABABCABABABCABABAB
ABABCABABAB

    */

    begin = 0;
    m = 0;

    while (begin<= Tl - Pl) {
        if (m<P.size()&&T[begin + m] == P[m]) {
            m++;

            if (m == Pl) ans.push_back(begin + 1);
           
        }
        else {
            if (m == 0) {
                begin++;
            }
            else {
                begin += (m - k[m - 1]);
                m = k[m - 1];
            }
        }

        
    }

    cout << ans.size() << "\n";
    for (int& i : ans) cout << i << " ";
}
