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

int m, n;
ll k;
int b[nax];

void sol1(){
    ll sum = 0;
    forn(i, m)sum += b[i];
    ll pre = 0;
    int l = -1;
    int r = 1e9;
    forn(i, m){
        ll suf = 0;
        ford(j, m){
            suf += b[j];
            ll val = (k - pre - suf);
            if(val % sum == 0 && val / sum >= 0){
                int cl = (j != m - 1 ? j : 0) + 1;
                ll cr = m + (val / sum) * m + i;
                if(cr <= n){
                    if(cr - cl + 1 < r - l + 1){
                        l = cl;
                        r = cr;
                    }
                }
            }
        }
        pre += b[i];
    }
    if(l == -1)cout << -1 << el;
    else cout << l << ' ' << r << el;
}

void sol2(){
    map<ll, ll> suf;
    ll sum = 0;
    ford(i, m){
        if(!suf.count(sum))suf[sum] = i;
        sum += b[i];
    }
    suf[0] = 0;
    int div = n / m;
    ll pre = 0;
    int l = -1;
    int r = 1e9;
    forn(i, m){
        forn(x, div){
            ll val = k - sum*x - pre;
            if(suf.count(val)){
                int cl = suf[val] + 1;
                int cr = cl + m*x + i;
                if(cr <= n){
                    if(cr - cl + 1 < r - l + 1){
                        l = cl;
                        r = cr;
                    }
                }
            }
        }
        pre += b[i];
    }
    if(l == -1)cout << -1 << el;
    else cout << l << ' ' << r << el;
}

void sol(){
    cin >> m >> n >> k;
    forn(i, m)cin >> b[i];
    if(m <= 1e3){
        sol1();
    }else{
        sol2();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}
