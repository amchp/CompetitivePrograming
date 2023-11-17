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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, d, v, t;
    cin >> n;
    priority_queue<int> q;
    for(int i = 0; i < n; ++i){
        cin >> d;
        q.push(d);
    }
    d = q.top();
    q.pop();
    t = 0;
    while(!q.empty()){
        v = q.top();
        q.pop();
        if(v < d){
            t += v;
            d -= v;
        }else if(d < v){
            t += d;
            d = v - d;
        }else{
            if(q.empty()){
                t += d;
                break;
            }
            v = q.top();
            q.pop();
            t += d;
            d = v;
        }
    }
    cout << t << el;
}