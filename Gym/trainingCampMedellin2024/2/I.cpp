#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define el '\n'
#define all(x) x.begin(), x.end()
#define d(x) cerr<<#x<<" "<<x<<el
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const ll inf = 2e18;

struct pt{
    ll x, y;
    pt(){}
    pt(ll x, ll y):x(x),y(y){}

    ll operator*(pt p){return x*p.x + y * p.y;}
    pt operator-(pt p){return {x- p.x, y-p.y};}
};
void sol(){
    int n; 
    pt p1, p2;
    cin>>n>>p1.x>>p1.y>>p2.x>>p2.y;
    vector<pt> pts(n);

    forn(i,n){
        cin>>pts[i].x>>pts[i].y;
    }
    ll ans = inf;
    forn(i,n){
        pt sub = pts[i] - p1;
        ll r1 = sub*sub;
        ll mx = 0;
        forn(j,n){
            if(i == j)continue;
            if((p1 - pts[j]) * (p1 - pts[j]) > r1){
                ll r2 = (p2 - pts[j]) * (p2-pts[j]);
                mx = max(r2, mx);
            }
        }
        ans = min(ans, r1 + mx);
    }
    forn(i,n){
        pt sub = pts[i] - p2;
        ll r1 = sub*sub;
        ll mx = 0;
        forn(j,n){
            if(i == j)continue;
            if((p2 - pts[j]) * (p2 - pts[j]) > r1){
                ll r2 = (p1 - pts[j]) * (p1-pts[j]);
                mx = max(r2, mx);
            }
        }
        ans = min(ans, r1 + mx);
    }
    cout<<ans<<el;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
}