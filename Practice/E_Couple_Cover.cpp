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
const int nax = 3e6 + 1;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

vector<ii> factors[nax];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    vl mp(nax, 0);
    forn(i, n){
        int v;
        cin >> v;
        mp[v]++;
    }
    vl suf(nax, 0);
    vl mps(nax, 0);
    mps[nax - 1] = mp[nax - 1];
    // for(int i = 0; i*i <= nax; ++i){
    //     if(nax % i == 0){
    //         cout << i << ' ' << nax / i << el;
    //     }
    // }
    ford(i, nax - 1){
        mps[i] = mp[i] + mps[i + 1]; 
    }
    for1(i, nax - 1){
        ll j = i;
        for(; i*j < nax; ++j){
            suf[i*j] += 1LL*((i != j) + 1)*mp[i]*(mp[j] - (i == j));
        }
        if(j < nax)suf[nax - 1] += mp[i]*(mps[j] - (i >= j));
    }
    ford(i, nax - 1){
        suf[i] += suf[i + 1];
    }
    int m;
    cin >> m;
    forn(i, m){
        int ind;
        cin >> ind;
        cout << suf[ind] << el;
    }
}
