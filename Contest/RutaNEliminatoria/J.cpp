#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define fore(i, l, r) for(int i = l; i < (int)r; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define el '\n'

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

const int inf = 1e9;

int main(){
    int n, q;
    cin >> n >> q;
    vi a(n);
    forn(i, n){
        cin >> a[i];
    }
    sort(all(a));
    map<int, vector<ii>> m;
    forn(i, n){
        fore(j, i + 1, n - 1){
            m[a[i] + a[j]].pb({i, j});
        }
    }
    forn(i, q){
        int k;
        cin >> k;
        int ind = lower_bound(all(a), k) - a.begin();
        if(a[ind] != k){
            cout << "NO" << el;
            continue;
        }
        int ans1 = -1, ans2, ans3;
        forn(i, ind){
            if(m.count(k - a[i])){
                vector<ii>& mp = m[k - a[i]];
                int ind = upper_bound(all(mp), (ii){i, inf}) - mp.begin();
                if(ind < mp.size()){
                    ans1 = a[i];
                    ans2 = a[mp[ind].first];
                    ans3 = a[mp[ind].second];
                    break;
                }
            }
        }
        if(ans1 == -1){
            cout << "NO" << el;
        }else{
            cout << ans1 << ' ' << ans2 << ' ' << ans3 << el;
        }
    }
}