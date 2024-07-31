#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define db(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef array<ll, 3> a3;


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

ll k;

ll dist(ll x1, ll y1, ll x2, ll y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

vector<a3> dist_large(ll x, ll y){
    ll cx = x / k;
    ll cy = y / k;
    if((cx + cy)&1){
        return {{x, y, 0}};
    }
    return {
        {cx*k-1, y, dist(cx*k-1, y, x, y)},
        {x, cy*k-1, dist(x, cy*k-1, x, y)},
        {k*(cx + 1), y, dist(k*(cx + 1), y, x, y)},
        {x, k*(cy + 1), dist(x, k*(cy + 1), x, y)},
    };
}

ll dist_large_large(a3& st, a3& ed){
    ll mx = max(
        abs(((st[0] + k) / k) - ((ed[0] + k) / k)),
        abs(((st[1] + k) / k) - ((ed[1] + k) / k))
    );
    if(k == 2){
        ll mn = min(
            abs(((st[0] + k) / k) - ((ed[0] + k) / k)),
            abs(((st[1] + k) / k) - ((ed[1] + k) / k))
        );
        return 2LL*mn + 3*(mx - mn) / 2 + st[2] + ed[2];
    }
    // db(mx);
    return 2LL*mx + st[2] + ed[2];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    ll sx, sy, tx, ty;
    cin >> k >> sx >> sy >> tx >> ty;
    ll ans = dist(sx, sy, tx, ty);
    vector<a3> sts = dist_large(sx, sy);
    vector<a3> eds = dist_large(tx, ty);
    // for(a3& st : sts){
    //     cout << st[0] << ' ' << st[1] << ' ' << st[2] << el;
    // }
    // cout << "#####" << el;
    // for(a3& ed : eds){
    //     cout << ed[0] << ' ' << ed[1] << ' ' << ed[2] << el;
    // }
    for(a3& st : sts){
        // cout << st[0] << ' ' << st[1] << ' ' << st[2] << el;
        for(a3& ed : eds){
            // cout << ed[0] << ' ' << ed[1] << ' ' << ed[2] << el;
            ans = min(ans, dist_large_large(st, ed));
            // db(dist_large_large(st, ed));
        }
        // cout << "#####" << el;
    }
    cout << ans << el;
}