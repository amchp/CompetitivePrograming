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
#define ford(i, n) for (int i = n-1; i >=0; --i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define sz(a) (int) a.size()
#define mp make_pair
#define el "\n"

typedef pair<int, int> ii;
typedef vector<int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cout << setprecision(20);
    int N;
    cin >> N;
    vector<ii> a(N);
    forn(i, N){
        cin >> a[i].first >> a[i].second;
    }
    bool waiting = false;
    int time = a[0].first + 10;
    int dir = a[0].second;
    for1(i, N - 1){
        if(a[i].first <= time){
            if(dir == a[i].second){
                time = a[i].first + 10;
            }else{
                waiting = true;
            }
        }
        else{
            if(waiting){
                time += 10;
                dir = !dir;
                waiting = false;
            }
            if(a[i].first <= time){
                if(dir == a[i].second){
                    time = a[i].first + 10;
                }else{
                    waiting = true;
                }
            }else{
                time = a[i].first + 10;
                dir = a[i].second;
            }
        }
    }
    if(waiting){
        time += 10;
    }
    cout << time << el;
}