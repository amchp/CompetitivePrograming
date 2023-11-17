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
    cin >> n;
    int pairs[2001][2];
    for(int i = 0; i < n; ++i){
        cin >> pairs[i][0] >> pairs[i][1];
    }
    for(int i = 0; i < n-2; ++i){
        for(int j = i+1; j < n-1; ++j){
            for(int k = j+1; k < n; ++k){
                if(((pairs[i][0]-pairs[j][0])*(pairs[j][1]-pairs[k][1]))-((pairs[j][0]-pairs[k][0])*(pairs[i][1]-pairs[j][1])) != 0)ans++;
            }
        }
    }
    
    cout << ans << endl;
}