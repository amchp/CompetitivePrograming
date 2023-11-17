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

string s;
int n, ini, jmp;
int visited[nax];

bool dfs(int ind){
    if(s[ind] == 'P')return false;
    if(visited[ind])return ind == ini;
    visited[ind] = true;
    bool ans = dfs((ind + jmp) % n);
    visited[ind] = false;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> s;
    n = sz(s);
    bool all = true;
    forn(i, n){
        all &= s[i] == 'R';
    }
    if(all){
        cout << n - 1 << el;
        return 0;
    }
    vector<bool> crv = vector<bool>(nax, true);
    vi primes;
    for(int i = 2; i < n; ++i){
        if(crv[i] == false)continue;
        primes.pb(i);
        for(int j = i + i; j < n; j += i){
            crv[j] = false;
        }
    }
    // for(int p : primes)cout << p << ' ';
    // cout << el;
    vi dprimes;
    int tN = n;
    for(int p : primes){
        while(tN % p == 0){
            tN = tN / p;
            dprimes.pb(p);
        }
    }
    vector<bool> wP(sz(dprimes));
    vi wPr;
    forn(i, n){
        if(s[i] == 'P');
        forn(j, sz(dprimes)){
            if(wP[j])continue;
            jmp = dprimes[j];
            ini = i;
            wP[j] = dfs(i);
            if(wP[j])wPr.pb(dprimes[j]);
        }
    }
    // for(int p : wPr){
    //     cout << p << ' ';
    // }
    // cout << el;
    int ans = 0;
    for(int i = 1; i < 1<<(sz(wPr)); ++i){
        int cnt = 0;
        int total = 1;
        forn(j, sz(wPr)){
            if(i & (1 << j)){
                total = lcm(total, wPr[j]);
                cnt++;
            }
        }
        // cout << cnt << ' ' << total << el;
        if(cnt % 2){
            ans += (n - 1) / total;
        }else{
            ans -= (n - 1) / total;
        }
    }
    // cout << el;
    cout << ans << el;
}
