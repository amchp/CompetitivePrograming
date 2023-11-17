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

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define ford(i, n) for (int i = n - 1; i > -1; --i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define el "\n"

typedef pair<int, int> ii;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int B, L;
    cin >> B >> L;
    vi D(L);
    forn(i, L){
        cin >> D[i];
    }
    int sum = 0;
    forn(i, L){
        if((i + !(L % 2)) % 2){
            // cout << "Sub" << el;
            sum = (sum - D[i] + (B + 1)) % (B + 1);
        }else{
            // cout << "Add" << el;
            sum = (sum + D[i]) % (B + 1);
        }
    }
    if(sum == 0){
        cout << 0 << ' ' << 0 << el;
        return 0;
    }
    int ind = -1;
    int ans = -1;
    forn(i, L){
        if((i + !(L % 2)) % 2){
            if(B + 1 - sum <= D[i]){
                ind = i + 1;
                ans = D[i] - (B + 1 - sum);
                break;
            }
        }
        else{
            if(D[i] >= sum){
                ind = i + 1;
                ans = D[i] - sum;
                break;
            }
        }
        
    }
    cout << ind << ' ' << ans << el;
}