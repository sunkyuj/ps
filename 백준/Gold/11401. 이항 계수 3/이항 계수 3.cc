#include <iostream>

using namespace std;
int n,k;
const long long MOD = 1e9+7;

typedef long long ll;


ll POW(ll a, ll b) {
	if (b == 0) return 1;
	if (b % 2 > 0) return (POW(a, b - 1) * a) % MOD;
	ll half = POW(a, b / 2) % MOD;
	return (half * half) % MOD;
}

int main()
{

    cin>>n>>k;
    int up=1,down=1;

/// (n!/A)%M = (n! * A^)%M = ((n!%M)*(A^%M))%M
/// A^ = k!(n-k)!

    for(ll i=1;i<=n;i++){
        up = (up%MOD * i)%MOD;
    }
    for(ll i=1;i<=k;i++){
        down = (down%MOD * i)%MOD;
    }
    for(ll i=1;i<=n-k;i++){
        down = (down%MOD * i)%MOD;
    }

    ll inv=POW(down,MOD-2)%MOD;

    cout<< (up%MOD*inv%MOD)%MOD;


    return 0;
}

