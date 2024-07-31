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
        vector<ii> sa(n);
        forn(i, n){
            cin >> a[i];
            sa[i].fi = a[i];
            sa[i].se = i + 1;
        }
        sort(all(sa), greater<ii>());
        set<int> s;
        set<ii> ns;
        ns.insert({2e9, 1});
        forn(i, n){
            int nxt = sa[i].fi + sa[i].se;
            if(s.count(nxt)){
                auto it = ns.lower_bound({nxt, -1});
                if(it == ns.begin())continue;
                it--;
                int r = (*it).fi;
                int l = (*it).se;
                if(r <= sa[i].fi)continue;
                s.insert(r);
                ns.erase(it);
                if(l <= r - 1)ns.insert({r - 1, l});
                continue;
            }
            s.insert(nxt);
            auto it = ns.lower_bound({nxt, -1});
            int r = (*it).fi;
            int l = (*it).se;
            ns.erase(it);
            if(l <= nxt - 1)ns.insert({nxt - 1, l});
            if(nxt + 1 <= r)ns.insert({r, nxt + 1});
        }
        for(auto it = s.rbegin(); it != s.rend(); it++){
            cout << (*it) << ' ';
        }
        cout << el;
    }
}
