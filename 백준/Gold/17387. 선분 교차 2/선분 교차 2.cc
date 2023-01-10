#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include<math.h>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

pii a,b,c,d;

ll ccw(pii a, pii b, pii c) {
	ll ans = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first); //<- triangle S
	if (ans > 0) return 1; //counter clockwise
	else if (ans < 0) return -1; //clockwise
	else return 0; //parallel
}

bool check(pii a, pii b, pii c, pii d) {
	ll abc = ccw(a, b, c), abd = ccw(a, b, d);
	ll cda = ccw(c, d, a), cdb = ccw(c, d, b);

	
	if (abc * abd == 0 && cda * cdb == 0) { //parallel
		return a <= d && c <= b;
	}

	return abc * abd <= 0 && cda * cdb <= 0;
}

int main()
{
	FIO;
	cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;

	if (a>b) swap(a, b); //a<=b
	if (c>d) swap(c, d); //c<=d

	//2S = (b.x - a.x) * (c.y - a.y) - (b.y - a.y)* (c.x - a.x)
	cout << check(a,b,c,d);
}

/*
	if (abc * abd * cda * cdb != 0) {
		if (abc * abd < 0 && cda * cdb < 0) cout << 1;
		else cout << 0;
	}
	else {
		if (abc == 0 && abd == 0) { //한 직선 떼어져있을수도 겹쳐있을수도
			if (a.x <= c.x && c.x <= b.x && a.y <= c.y && c.y <= b.y || a.x <= d.x && d.x <= b.x && a.y <= d.y && d.y <= b.y) cout << 1;
			//else if (b.x <= c.x && c.x <= a.x && b.y <= c.y && c.y <= a.y || b.x <= d.x && d.x <= a.x && b.y <= d.y && d.y <= a.y) cout << 1;
			else cout << 0;
		}
		else if (abc == 0) {
			if (a.x <= c.x && c.x <= b.x && a.y <= c.y && c.y <= b.y ) cout << 1;
			//else if (b.x <= c.x && c.x <= a.x && b.y <= c.y && c.y <= a.y ) cout << 1;
			else cout << 0;
		}
		else { //abd==0
			if (a.x <= d.x && d.x <= b.x && a.y <= d.y && d.y <= b.y) cout << 1;
			//else if (b.x <= d.x && d.x <= a.x && b.y <= d.y && d.y <= a.y) cout << 1;
			else cout << 0;
		}
	}
	*/