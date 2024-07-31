#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = l; i < (int)r; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define el '\n'
#define d(x) cout << #x << ' ' << x << el;
#define sz(x) (int)x.size()

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int n;
int a[(int)1e5];

vector<pair<double, int>> sol(int l, int r, bool dale){
    if(l == r){
        return {{1.0, a[l]}};
    }
    int m = l + (r - l) / 2;
    if(dale){
        vector<pair<double, int>> vD = sol(l, m, true);
        vector<pair<double, int>> oD = sol(m+1, r, false);
        double ans = 0;
        forn(i, sz(oD)){
            ans += vD[0].first*oD[i].first*((double)vD[0].second / (double)(vD[0].second + oD[i].second));
        }
        return {{ans, vD[0].second}};
    }else{
        vector<pair<double, int>> lD = sol(l, m, false);
        vector<pair<double, int>> rD = sol(m+1, r, false);
        vector<pair<double, int>> aD;
        double ans;
        forn(i, sz(lD)){
            ans = 0;
            // cout << lD[i].second << el;
            if(lD[i].second == 0)continue;
            forn(j, sz(rD)){
                ans += lD[i].first*rD[j].first*((double)lD[i].second / (double)(lD[i].second + rD[j].second));
            }
            aD.pb({ans, lD[i].second});
        }
        forn(j, sz(rD)){
            ans = 0;
            // cout << rD[j].second << el;
            if(rD[j].second == 0)continue;
            forn(i, sz(lD)){
                ans += lD[i].first*rD[j].first*((double)rD[j].second / (double)(lD[i].second + rD[j].second));
            }
            aD.pb({ans, rD[j].second});
        }
        // forn(i, sz(aD)){
        //     cout << aD[i].first << ' '  << aD[i].first << el;
        // }
        // cout << el;
        return aD;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << setprecision(20);
    cin >> n;
    vi tA(n);
    forn(i, n){
        cin >> tA[i];
    }
    sort(tA.begin() + 1, tA.end());
    int nL = (int)log2(n);
    nL = 1<<(nL+1);
    vi ttA;
    forn(i,n){
        ttA.pb(tA[i]);
        if(i < nL-n){
            ttA.pb(0);
        }
    }
    forn(i, nL){
        a[i] = ttA[i];
    }
    // cout << el;
    cout << sol(0, nL - 1, true)[0].first << el;
}