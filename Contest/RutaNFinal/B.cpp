#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for(int i = (int)n-1; i >= 0; --i)
#define el '\n'
#define sz(x) x.size()
#define pb push_back
#define d(x) cout << #x << ' ' << x << el;
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void sol(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<string, int> w;
    map<int, string> wI;
    forn(i, n){
        string s;
        cin >> s;
        w[s] = i;
        wI[i] = s;
    }
    vector<vector<set<int>>> don(m, vector<set<int>>(2));
    map<int, vi> donToPeople;
    vi one;
    set<int> glazed;
    forn(i, m){
        int szs;
        cin >> szs;
        forn(j, szs){
            int g;
            cin >> g;
            string s;
            cin >> s;
            g--;
            don[i][g].insert(w[s]);
            donToPeople[w[s]].pb(i);
        }
        if(sz(don[i][0]) == 1 && sz(don[i][1]) == 0)one.pb(i);
    }
    bool pass = true;
    int i = 0;
    while(i < sz(one)){
        int u = (*don[one[i]][0].begin());
        if(glazed.count(u)){
            i++;
            continue;
        }
        glazed.insert(u);
        for(int v : donToPeople[u]){
            if(don[v][1].count(u))don[v][1].erase(u);
            if(sz(don[v][1]) == 0){
                if(sz(don[v][0]) == 0){
                    pass = false;
                    break;
                }else{
                    one.pb(v);
                }
            }
        }
        if(!pass)break;
        i++;
    }
    if(!pass){
        cout << "Impossible" << el;
        return ;
    }
    vector<string> ans;
    for(int v : glazed){
        ans.pb(wI[v]);
    }
    sort(all(ans));
    cout << sz(ans) << el;
    for(string as : ans){
        cout << as << el;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}