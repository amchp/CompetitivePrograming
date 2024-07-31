#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define ford(i, n) for(int i = (int)n - 1; i >= 0; --i)
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define el '\n'
#define d(x) cerr<<#x<<" "<<x<<el
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int, int> mp;
    int ones = 0;
    int twos = 0;
    forn(i, n){
        int v;
        cin >> v;
        ++mp[v];
    }
    if(n == 1){
        cout << (*mp.begin()).fi << el;
        return 0;
    }
    int e = min(mp[1], mp[2]);
    string ans = "";
    forn(i, e){
        string t = "(1+2)*";
        ans.insert(ans.end(), all(t));
        --mp[1];
        --mp[2];
    }
    if(mp[1] > 0){
        while(mp[1] >= 3){
            string t = "(1+1+1)*";
            ans.insert(ans.end(), all(t));
            mp[1] -= 3;
        }
        if(mp[1] == 1 && sz(ans)){
            ans.pop_back();
            ans.pop_back();
            string t = "+1)*";
            ans.insert(ans.end(), all(t));
            --mp[1];
        }
        if(mp[1] == 2){
            string t = "(1+1)*";
            ans.insert(ans.end(), all(t));
            mp[1] -= 2;
        }
    }
    for(auto& [val, cnt] : mp){
        if(val == 1 || cnt == 0)continue;
        if(mp[1] == 1){
            string t = "(1+" + to_string(val) + ")*";
            ans.insert(ans.end(), all(t));
            --cnt;
            --mp[1];
        }
        forn(i, cnt){
            string t = to_string(val) + "*";
            ans.insert(ans.end(), all(t));
        }
    }
    ans.pop_back();
    cout << ans << el;
}