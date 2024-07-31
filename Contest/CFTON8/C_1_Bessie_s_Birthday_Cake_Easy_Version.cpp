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
#define d(x) cerr<< #x<< " " << x<<el
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


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        vi xs(x);
        forn(i, x){
            cin >> xs[i];
            --xs[i];
        }
        sort(all(xs));
        map<int, int> rgt;
        vi ns;
        forn(i, x - 1){
            if(xs[i + 1] - xs[i] > 2){
                rgt[xs[i]] = xs[i + 1];
            }else{
                ns.pb(xs[i + 1] - xs[i]);
            }
        }
        if((n - 1 - xs[x - 1]) + xs[0] > 2){
            rgt[xs[x - 1]] = xs[0];
            ns.pb((n - xs[x - 1]) + xs[0]);
        }
        queue<int> q;
        forn(i, x)q.push(xs[i]);
        set<int> out;
        ll ans = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(out.count(u))continue;
            int r, rr;
            if(rgt.count(u))r = rgt[u];
            else r = (u + 1) % n;
            if(rgt.count(r))rr = rgt[r];
            else rr = (r + 1) % n;
            if(u == rr)continue;
            if(binary_search(all(xs), rr)){
                ++ans;
                out.insert(r);
                rgt[u] = rr;
                q.push(u);
            }
        }
        sort(all(ns));
        for(int& v : ns){
            if(v / 2 > y)break;
            ans += v - 1;
            y -= v / 2;
        }
        ans += y;
        cout << ans << el;
    }
}