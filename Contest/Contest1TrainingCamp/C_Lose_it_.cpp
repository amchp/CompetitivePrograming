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
    int n;
    cin >> n;
    vi v(n);
    vi a(6, 0);
    vi ind;
    ind.push_back(4);
    ind.push_back(8);
    ind.push_back(15);
    ind.push_back(16);
    ind.push_back(23);
    ind.push_back(42);
    for(int i = 0; i < n; ++i)cin >> v[i];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 6; ++j){
            if(v[i] == ind[j] && (j == 0 || a[j - 1] > 0)){
                if(j != 0)a[j - 1]--;
                a[j]++;
            }
        }
    }
    cout << n - a[5] * 6 << el;
}