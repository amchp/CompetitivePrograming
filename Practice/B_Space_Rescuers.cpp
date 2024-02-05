#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ld inf = 1e4;
const int nax = 110;
const ld pi = acos(-1);
const ld eps = 1e-7;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct pt{
    ld x, y, z;
    pt(){}
    pt(int x, int y, int z): x(x), y(y), z(z){}
    pt(ld x, ld y, ld z): x(x), y(y), z(z){}
    ld dis(pt o){
        ld dx = x - o.x;
        ld dy = y - o.y;
        ld dz = z - o.z;
        return dx*dx+dy*dy+dz*dz;
    }
};

int n;
pt plnts[nax];
ld ax, ay, az;

ld f(ld x, ld y, ld z){
    ld ans = 0;
    pt cur = pt(x, y, z);
    forn(i, n)ans = max(ans, cur.dis(plnts[i]));
    return ans;
}

ld ternary_search_z(ld x, ld y){
    ld l = -inf, r = inf;
    while (r - l > eps) {
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l) / 3;
        ld f1 = f(x, y, m1), f2 = f(x, y, m2);
        if (f1 > f2) l = m1;
        else r = m2;
    }
    az = l;
    return f(x, y, l); 
}

ld ternary_search_y(ld x){
    ld l = -inf, r = inf;
    while (r - l > eps) {
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l) / 3;
        ld f1 = ternary_search_z(x, m1), f2 = ternary_search_z(x, m2);
        if (f1 > f2) l = m1;
        else r = m2;
    }
    ay = l;
    return ternary_search_z(x, l); 
}

ld ternary_search_x() {
  ld l = -inf, r = inf;
  while (r - l > eps) {
    ld m1 = l + (r - l) / 3;
    ld m2 = r - (r - l) / 3;
    ld f1 = ternary_search_y(m1), f2 = ternary_search_y(m2);
    if (f1 > f2) l = m1;
    else r = m2;
  }
  ax = l;
  return ternary_search_y(l);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20) << fixed;
    cin >> n;
    forn(i, n){
        int x, y, z;
        cin >> x >> y >> z;
        plnts[i] = pt(x, y, z);
    }
    // d(f(0, 0, 0));
    ternary_search_x();
    cout << ax << ' ' << ay << ' ' << az << el;
}
