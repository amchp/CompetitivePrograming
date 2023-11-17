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
    int n, l = -1, r, ans = -1;
    cin >> n;
    string s;
    cin >> s;
    vi x(n);
    for(int i = 0; i < n; ++i)cin >> x[i];
    for(int i = 0; i < n; ++i){
        if(s.at(i) == 'R')l = x[i];
        else if(l != -1 && s.at(i) == 'L'){
            r = x[i];
            if(ans == -1)ans = (r - l) / 2;
            else ans = min(ans, (r - l) / 2);
        }
    }
    cout << ans << el;
}