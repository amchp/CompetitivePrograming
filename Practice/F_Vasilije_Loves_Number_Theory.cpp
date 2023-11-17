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
const int nax = 1e6 + 1;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

bool crb[nax];
map<int, int> primeFactors[nax];
vi primes;

map<int, int> prime_fact(int x){
    if(x == 1)return map<int, int>();
    if(sz(primeFactors[x]) > 0)return primeFactors[x];
    int tmp = x;
    for(int p : primes){
        int cnt = 0;
        while(tmp % p == 0){
            cnt++;
            tmp /= p;
        }
        if(cnt > 0)primeFactors[x][p] = cnt;
    }
    if(tmp != 1)primeFactors[x][tmp] = 1;
    return primeFactors[x];
}

bool fac(ll x, map<int, int> mp){
    // d(x);
    for(auto &[p, e] : mp){
        // d(p);
        // d(e);
        forn(i, e){
            if(x % p == 0)x /= p;
        }
    }
    // cout << x << el;
    return x == 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    for(int i = 2; i*i <= nax; ++i){
        if(crb[i])continue;
        primes.pb(i);
        for(int j = i + i; j < nax; j+=i){
            crb[j] = true;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        map<int, int> ini_fact = prime_fact(n);
        map<int, int> cur_fact = ini_fact;
        while(q--){
            int k;
            cin >> k;
            if(k == 1){
                int x;
                cin >> x;
                map<int, int> pX = prime_fact(x);
                int j = 0;
                for(auto &[p, e] : pX){
                    cur_fact[p] += e;
                }
                ll div = 1; 
                for(auto &[p, e] : cur_fact){
                    // d(e + 1);
                    div *= e + 1;
                }
                // d(div);
                if(fac(div, cur_fact)){
                    cout << "YES" << el;
                }else{
                    cout << "NO" << el;
                }
            }else{
                cur_fact = ini_fact;
            }
        }
        cout << el;
    }
}
