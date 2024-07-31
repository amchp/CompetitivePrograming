#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>


using namespace std;

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define sz(a) (int) a.size()
#define el '\n'
#define pb push_back
#define all(a) a.begin(),a.end()
#define RAYA cerr << "===============\n";
#define d(x) cerr<< #x << "  "<<x<<el;

typedef long long ll;
typedef vector<ll> vi;
const ll inf = 1e18;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n,m;
    cin>>n>>m;
    vector<vi> frec(m+1);//valores
    vi ind(m+1);
    ll amount = 0;
    forn(i,n)
    {
        int idx, qty;
        cin>>idx>>qty;
        idx--;
        if(idx == 0)amount++;
        else{
            frec[idx].pb(qty);
        }
    }

    vector<set<int>> niveles(n+1);
    forn(i,m){
        sort(all(frec[i]),greater<int>());
        niveles[sz(frec[i])].insert(i);
        ind[i] = frec[i].size()-1;

    }
    ll greater = 0, cost = 0;
    ll ans = inf;
    for (int i = n; i >= amount; i--)
    {
        // d(i);
        ll curr = 0;
        auto prev = niveles[i].end();
        for(auto v  = niveles[i].begin();v != niveles[i].end();v++){
            int val = *v;
            if(ind[val]>=0)
                cost += 1LL*frec[val][ind[val]];
            if(i>=1){
                niveles[i-1].insert(val);
                ind[val]--;
            }
            greater++;
            if(prev != niveles[i].end()){
                niveles[i].erase(prev);
            }
            prev = v;

        }
        if(prev != niveles[i].end()){
            niveles[i].erase(prev);
        }
        // d(greater);
        int cnt = 0;
        ll votos =1LL* greater + amount;
        // d(votos);
        // d(cost);
        curr+=1LL*cost;
        ll necesito = 1LL*i - votos;
        // if(necesito < 0){
        //     ans = min(curr,ans);
        //     break;
        // }
        // d(necesito);
        ll mn = inf, idx = -1;
        vi possi;
        forn(i,m){
            if(sz(frec[i]) && ind[i]>=0){
                for (int j = 0; j <= ind[i]; j++)
                {
                    possi.pb(frec[i][j]);
                }
                }
        }
        sort(all(possi));
        forn(i,possi.size()){
            if(necesito>=1){
                curr+=1LL*possi[i];
                necesito--;
            }else break;
        }
        // d(curr);
        ans = min(ans,curr);
    }
    cout<<ans<<el;
    // d(ans);
}