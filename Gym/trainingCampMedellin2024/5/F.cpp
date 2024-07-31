#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define el '\n'
#define db(x) cerr<<#x<<" "<<x<<el
#define pb push_back
#define sz(a) (int) a.size()
#define all(x) x.begin(), x.end()

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef array<int, 3>  a3;
const int nax = 2501;

bool sol(){
    int n;
    cin >> n;
    vector<bitset<nax>> bts(n, bitset<nax>(0));
    vector<vi> a(n, vi(n));
    vector<a3> vals(n*n);
    int mx = 0;
    forn(i, n){
        forn(j, n){
            cin >> a[i][j];
            vals[i*n + j] = {a[i][j], i, j};
        }
    }
    forn(i, n){
        forn(j, n){
            if(i == j && a[i][j] != 0)return false;
            if(a[i][j] != a[j][i])return false;
        }
    }
    sort(all(vals));
    int pval = -1;
    vector<int> prv(nax*nax);
    int ind = 0;
    forn(x, sz(vals)){
        auto& [val, i, j] = vals[x];
        // cout << i << ' ' << j << el;
        if(val != pval){
            forn(k, ind){
                int& cur = prv[k];
                bts[vals[cur][1]].set(vals[cur][2]);
            }
            ind = 0;
        }
        if((bts[i] & bts[j]).any())return false;
        prv[ind] = x;
        pval = val;
        ++ind;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(sol())cout << "MAGIC" << el;
    else cout << "NOT MAGIC" << el;
}