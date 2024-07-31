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
const int nax = 3e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n;
int a[nax];
map<int, int> same;
int smi[nax];
ll pre[nax];

bool check(int l, int r, int cur){
    ll sm = pre[r] - (l != 0 ? pre[l - 1] : 0);
    if(a[l] == a[r]){
        int sl = smi[l];
        int sr = smi[r];
        if(sr - sl == r - l)return false;
    }
    return sm > a[cur];
}

int sol(int i){
    // d(i);
    if(i != 0 && a[i - 1] > a[i])return 1;
    if(i != n - 1 && a[i + 1] > a[i])return 1;
    int ans = inf;
    int l = -1;
    int r = i;
    while(l + 1 < r){
        int m = l + (r - l) / 2;
        if(check(m, i - 1, i)){
            l = m;
        }else{
            r = m;
        }
    }
    // d(l);
    if(l != -1)ans = min(ans, i - l);
    l = i;
    r = n;
    while(l + 1 < r){
        int m = l + (r - l) / 2;
        if(check(i + 1, m, i)){
            r = m;
        }else{
            l = m;
        }
    }
    // d(r);
    if(r != n)ans = min(ans, r - i);
    if(ans == inf)return -1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        forn(i, n){
            cin >> a[i];
            smi[i] = same[a[i]];
            same[a[i]]++;
        }
        pre[0] = a[0];
        for1(i, n - 1)pre[i] = pre[i - 1] + a[i];
        vi ans(n);
        forn(i, n){
            ans[i] = sol(i);
        }
        for(int& v : ans)cout << v << ' ';
        cout << el;
        same.clear();
    }
}
