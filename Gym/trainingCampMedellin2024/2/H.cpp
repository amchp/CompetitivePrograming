#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < n; ++i)
#define fore(i,l, r) for(int i = l; i <= r; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define el '\n'
#define all(x) x.begin(), x.end()
#define d(x) cerr<<#x<<" "<<x<<el
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
const int inf = 1e9 + 10;

void sol(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vi l(k), r(k);
    forn(i,k){cin>>l[i];--l[i];}
    forn(i,k){cin>>r[i];--r[i];}
    int q;
    cin>>q;
    vi op(n);
    forn(i,q){
        int x;
        cin>>x;
        --x;
        op[x] ^= 1;
        int ind = lower_bound(all(r), x) - r.begin();
        op[r[ind] - (x - l[ind])]^=1;
    }
    forn(i,k){
        int lazy = 0;
        int L = l[i], R = r[i];
        fore(j, l[i], (L+R) / 2){
            lazy^=op[j];
            if(lazy){
                swap(s[j], s[R - (j - L)]);
            }
        }
    }
    cout<<s<<el;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}