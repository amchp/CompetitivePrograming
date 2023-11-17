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
    int n, killed = 0, cl = 0;
    cin >> n;
    vi l(n);
    for(int i = 0; i < n; ++i)cin >> l[i];
    for(int i = n - 1; i > -1; --i){
        if(cl > 0)cl--;
        if(l[i] > 0 && cl < l[i]){
            if(l[i] - cl < i - cl)killed += l[i] - cl;
            else{
                killed += i - cl;
                break;
            }
            cl = l[i];
        }
    }
    cout << (n - killed) << el;
    
}