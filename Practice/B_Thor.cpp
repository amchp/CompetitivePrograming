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
    int n, q, input, am, e = 0;
    cin >> n >> q;
    int unread = 0;
    int apps[300000][2];
    int events[300000];
    memset(apps, 0, sizeof(int)*n*2);
    memset(events, 0, sizeof(int)*n*2);
    while(q--){
        cin >> input >> am;
        if(input == 1){
            apps[am][0]++;
            unread++;
            events[e] = am;
        }else if(input == 2){
            unread -= apps[am][0];
            apps[am][1] = apps[am][0];
            apps[am][0] = 0;
        }else{
            
        }
        cout << unread << el;
    }
}