#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define ford(i, n) for(int i = (int)n - 1; i >= 0; --i)
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define el '\n'
#define d(x) cerr<<#x<<" "<<x<<el
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef double ld;

const ld PI = acos(-1);
const ld inf = 1e25;
struct pt{
    ld x,y;
    pt(){}
    pt(ld x, ld y):x(x),y(y){}
    // pt(int x, int y):x(x),y(y){}

    ld operator%(pt p){return x * p.y - y * p.x;}
    ld operator*(pt p){return x*p.x + y*p.y;}
    pt operator*(ld t){return pt(x*t, y*t);}
    pt rot(pt p){
        return pt(*this%p, *this*p);
    }
    pt rot(ld ang){
        return rot(pt(sin(ang), cos(ang)));
    }
};

vector<pt> pts;
const int nax = 15;
ld dp[nax][1<<nax];
ld dist(pt a, pt b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}
ld f(ld angle){
    vector<pt> arr = pts;
    int n = sz(pts);
    forn(i,n) {arr[i] = arr[i].rot(angle);}

    int N = 1<<n;
    forn(i,n)forn(j,N) dp[i][j] = inf;

    forn(i,n){ dp[i][1<<i] = 0;}

    for1(mask, N-2){
        forn(u, n){
            if(!((1<<u) & mask)) continue;
            ld &cur = dp[u][mask];
            forn(v, n){
                if(u == v || ((1<<v) & mask) ) continue;
                ld &nxt =dp[v][mask ^ (1<<v)];
                nxt = min(nxt, cur + dist(arr[u], arr[v]));
            }
        }
    }
    ld ans = inf;
    // d((dist(pt{0,0.555}, pt{1.2, 1})));
    forn(i,n){
        // d(dp[i][N-1]);
        ans = min(ans, dp[i][N-1]);
    }
    return ans;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.precision(20);
    cout << fixed;
    int n;
    cin>>n;
    pts = vector<pt> (n);
    forn(i,n){
        int x,y;
        cin>>x>>y;
        pts[i] = {ld(x),ld(y)};
    }

    ld ans = inf;
    forn(i, n){
        forn(j, n){
            ld ang = atan((pts[i].y - pts[j].y )/ (pts[i].x - pts[j].x));
            ans = min(ans, f(ang));
            ans = min(ans, f(-ang));
        }
    }
    cout<<ans<<el;
    // d(f(1.32581766366803));
}