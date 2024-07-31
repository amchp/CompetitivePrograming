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

bool check(int st, int jmp){
    for(int i = st; i < sz(s); i += jmp){
        if(s[i] == 'P')return false;
    }
    return true;
}

bool sol(int f){
    forn(i, f){
        if(check(i, f))return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> s;
    int n = sz(s);
    vi factors;
    for(int i = 1; i*i <= n; ++i){
        if(n % i == 0){
            factors.pb(i);
            int j = n / i;
            if(i != j)factors.pb(j);
        }
    }
    sort(all(factors));

    vi bkt(sz(factors));
    for1(i, n - 1){
        int ind = lower_bound(all(factors), __gcd(n, i)) - factors.begin();
        ++bkt[ind];
    }
    int ans = 0;
    forn(i, sz(factors)){
        int& f = factors[i];
        if(sol(f)){
            ans += bkt[i];
        }
    }
    cout << ans << el;
}
