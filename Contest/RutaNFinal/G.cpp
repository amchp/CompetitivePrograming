#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define el '\n'
#define sz(x) x.size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int n;
set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 33};
vector<vi> ans[17];
bool nums[17];
vi cAns;

void solve(int ind){
    if(ind == n){
        if(primes.count(cAns[0] + cAns.back())){
            ans[n].pb(cAns);
        }
        return;
    }
    for1(i, n){
        if(!nums[i])continue;
        if(primes.count(cAns.back() + i)){
            nums[i] = false;
            cAns.pb(i);
            solve(ind + 1);
            cAns.pop_back();
            nums[i] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    forn(i, 17)ans[i] = vector<vi>();
    int tt = 1;
    while(cin >> n){
        if(tt != 1)cout << el;
        if(ans[n] == vector<vi>()){
            cAns.clear();
            cAns.pb(1);
            fore(i, 2, n){
                nums[i] = true;
            }
            fore(i, n + 1, 16){
                nums[i] = false;
            }
            solve(1);
        }
        cout << "Case " << tt << ":" << el;
            forn(i, ans[n].size()){
                forn(j, n){
                    if(j == n - 1)cout << ans[n][i][j];
                    else cout << ans[n][i][j] << ' ';
                }
            cout << el;
        }
        tt++;
    }
}