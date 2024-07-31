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
typedef pair<string, string> pss;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

bool sol(){
    int n;
    cin >> n;
    char ts;
    cin >> ts;
    int n2 = 2*n;
    vector<char> sts = {'C', 'D', 'H', 'S'};
    vector<vi> a(4, vi());
    forn(i, n2){
        string crd;
        cin >> crd;
        int ist = lower_bound(all(sts), crd[1]) - sts.begin();
        a[ist].pb(crd[0] - '0');
    }
    forn(i, 4)sort(all(a[i]));
    vector<pss> ans;
    vector<string> lft;
    int its = -1;
    forn(i, 4){
        if(sts[i] == ts){
            its = i;
            continue;
        }
        for(int j = 1; j < sz(a[i]); j += 2){
            string s1, s2;
            s1.pb(char(a[i][j - 1] + '0'));
            s1.pb(sts[i]);
            s2.pb(char(a[i][j] + '0'));
            s2.pb(sts[i]);
            pss tmp = {s1, s2};
            ans.pb(tmp);
        }
        if(sz(a[i]) & 1){
            string s1;
            s1.pb(char(a[i].back() + '0'));
            s1.pb(sts[i]);
            lft.pb(s1);
        }
    }
    if(sz(a[its]) < sz(lft))return false;
    if((sz(a[its]) + sz(lft)) & 1)return false;
    for(string& s1 : lft){
        string s2;
        s2.pb(char(a[its].back() + '0'));
        s2.pb(sts[its]);
        ans.pb({s1, s2});
        a[its].pop_back();
    }
    for(int j = 1; j < sz(a[its]); j += 2){
        string s1, s2;
        s1.pb(char(a[its][j - 1] + '0'));
        s1.pb(sts[its]);
        s2.pb(char(a[its][j] + '0'));
        s2.pb(sts[its]);
        pss tmp = {s1, s2};
        ans.pb(tmp);
    }
    if(sz(a[its]) & 1)return false;
    for(pss v : ans)cout << v.fi << ' ' << v.se << el;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        if(!sol())cout << "IMPOSSIBLE" << el;
    }
}
