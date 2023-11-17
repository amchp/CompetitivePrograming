#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>
#include <tuple>


// Useful constants 
#define INF                         (int)2e9 
#define EPS                         1e-9

#define el '\n'

#define MAXN                         (int)2e5

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, V, K, D, t, h, p, a, zK;
    cin >> n >> m >> V >> K >> D;
    vector<vector<pair<int, int> > > z((int)EPS);
    vi sM((int)EPS, 0);
    for(int i = 0; i < n; ++i){
        cin >> t >> h;
        z[t].push_back(make_pair(i, h));
    }
    for(int i = 0; i < n; ++i){
        cin >> p >> a;
        sM[p] += a;
    }
    vector<vector<int> > zM;
    t = 1;
    vi zKT(n);
    zK = 0;
    vi v;
    while(zK < n){
        for(int i = 0; i < z[t].size(); ++i){
            v.clear();
            v.push_back(0);
            v.push_back(z[t][i].second);
            v.push_back(z[t][i].first);
            zM.push_back(v);
        }
        for(int i = 0; i < zM.size(); ++i){
            zM[i][1] -= sM[zM[i][0]];
            zM[i][0]++;
            if(zM[i][1] <= 0){
                zKT[zM[i][2]] = t;
                zM.erase(zM.begin() + i);
                zK++;
            }
        }
        for(int i = 0; i < K; ++i){
            if(zM.size() == 0)break;
            zM[0][1] -= D;
            if(zM[0][1] <= 0){
                zKT[zM[i][2]] = t;
                zM.erase(zM.begin() + i);
                zK++;
            }
        }
        t++;
    }
    for(int i = 0; i < n; ++i)std::cout << zKT[i] << " ";
    std::cout << el;
}