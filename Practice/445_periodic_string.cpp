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

// O(|s|)
vi z_function(string &s){
    int n = s.size();
    vi z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; ++i)
    {
        z[i] = max(0, min(z[i - x], y - i + 1));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            x = i, y = i + z[i], z[i]++;
    }
    return z;
}

int sol(){
    string s;
    cin >> s;
    vi z = z_function(s);
    z.pb(0);
    int n = sz(s);
    assert(n != 0);
    vi factors;
    for(int i = 1; i*i <= n; ++i){
        if(n % i == 0){
            int j = n / i;
            factors.pb(i);
            if(i != j)factors.pb(j);
        }
    }
    sort(all(factors));
    // for(int& factor: factors)cout << factor << ' ';
    // cout << el;
    for(int& factor: factors){
        if(factor + z[factor] == n){
            return factor;
        }
    }
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    string s;
    while(t--){
        cout << sol() << el;
        if(t)cout << el;
    }
    // cout << el;
}
