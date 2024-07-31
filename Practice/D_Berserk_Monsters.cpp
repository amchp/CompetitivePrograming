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
        vi a(n), h(n);
        forn(i, n)cin >> a[i];
        forn(i, n)cin >> h[i];
        vi ans(n);
        if(n == 1){
            for(int& v : ans)cout << v << ' ';
            cout << el;
            continue;
        }
        set<int> s;
        forn(i, n)s.insert(i);
        int rnd = 0;
        vector<bool> eli(n);
        set<int> q, qq;
        forn(i, n)q.insert(i);
        while(rnd < n && !q.empty()){
            swap(q, qq);
            vi dsty;
            int cans = 0;
            for(int cur : qq){
                if(eli[cur])continue;
                auto it = s.lower_bound(cur);
                int l = -1;
                if(it != s.begin()){
                    --it;
                    l = (*it);
                }
                it = s.upper_bound(cur);
                int r = -1;
                if(it != s.end()){
                    r = (*it);
                }
                // d(l);
                // d(r);
                ll sm = 0;
                if(l != -1)sm += a[l];
                if(r != -1)sm += a[r];
                if(h[cur] < sm){
                    dsty.pb(cur);
                    if(l != -1){
                        q.insert(l);
                    }
                    if(r != -1){
                        q.insert(r);
                    }
                }
            }
            ans[rnd] = sz(dsty);
            for(int& cur : dsty){
                eli[cur] = true;
                s.erase(cur);
            }
            ++rnd;
            qq.clear();
        }
        for(int& v: ans)cout << v << ' ';
        cout << el;
    }
}
