#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < n; ++i)
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
    int n;
    cin >> n;
    vi a(n);
    forn(i, n)cin >> a[i];
    set<ii> ns;
    ns.insert({2e9, 1});
    forn(i, n){
        a[i] = a[i] + (i + 1);
    }
    vi ans;
    forn(i, n){
        auto it = ns.lower_bound({a[i], -inf});
        if((*it).se <= a[i]){
            ans.pb(a[i]);
            int r = (*it).fi;
            int l = (*it).se;
            ns.erase(it);
            if(l < a[i])ns.insert({a[i] - 1, l});
            if(a[i] < r)ns.insert({r, a[i] + 1});
            continue;
        }
        if(it == ns.begin())assert(false);
        --it;
        int r = (*it).fi;
        int l = (*it).se;
        ans.pb(r);
        ns.erase(it);
        if(l < r)ns.insert({r - 1, l});
    }
    sort(all(ans), greater<int>());
    for(int& v : ans)cout << v << ' ';
    cout << el;
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