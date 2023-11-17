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
    int n, x, y;
    long long ans = 0;
    pair<int, int> p;
    cin >> n;
    map<pair<int, int>, int> position; 
    map<int, int> xp;
    map<int, int> yp;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        p = make_pair(x, y);
        xp[x]++;
        yp[y]++;
        ans -= position[p];
        position[p]++;
    }
    map<int, int>::iterator it;
    for(it = xp.begin(); it != xp.end(); it++){
        ans += (long long)(it->second-1)*(it->second)/2;
    }
    for(it = yp.begin(); it != yp.end(); it++){
        ans += ((long long)(it->second-1))*(it->second)/2;
    }
    cout << ans << endl;
}