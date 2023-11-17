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
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        set<int> grt;
        vector<vi> g(n + 1);
        queue<int> q;
        stack<int> zero;
        forn(i, n){
            cin >> a[i];
            if(a[i] > i + 1){
                grt.insert(i + 1);
            }
            if(a[i] != 0 && a[i] != n + 1)g[a[i]].pb(i + 1);
            if(a[i] == n + 1){
                // d(i + 1);
                q.push(i + 1);
            }
            if(a[i] == 0)zero.push(i + 1);
        }
        while(!zero.empty()){
            q.push(zero.top());
            zero.pop();
        }
        int thr = sz(grt) > 0 ? (*grt.rbegin()) : 1;
        // for1(i, n){
        //     cout << i << " : ";
        //     for(int v : g[i])cout << v << ' ';
        //     cout << el;
        // }
        vi ts;
        vector<bool> seen(n + 1, false);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ts.pb(u);
            for(int v : g[u]){
                if(!seen[v]){
                    seen[v] = true;
                    q.push(v);
                }
            }
        }
        cout << thr << el;
        assert(sz(ts) == n);
        forn(i , n){
            cout << ts[i] << ' ';
        }
        cout << el;
    }
}