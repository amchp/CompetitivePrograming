#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;


int MAXN = 1000000001;

int main(){
    int N, K, min, val, sum, ref;
    long long  cur, v;
    cin >> N;
    cin >> K;
    int factors[K];
    map<long long, long long> g;
    map<long long, long long>  searched;
    queue<int> s;
    bool c = false;
    for(int i = 0; i < K; ++i) cin >> factors[i];

    sort(factors, factors + K);

    min = 1000000000;
    s.push(1);
    while(!s.empty()){
        cur = s.front();
        s.pop();
        for(int i = 0; i < K; ++i){
            v = cur * factors[i];
            if(v > N) continue;
            else if(v == N){
                c = true;
                ref = cur;
                g[v] = cur;
                goto stop;
            }
            else{
                if(searched[v] != 0) continue;
                else{
                    searched[v] = 1;
                    g[v] = cur;
                    s.push(v);
                }
            }
        }
    }
    stop:
    if(!c) cout << -1 << endl;
    else{
        string st = to_string(N);
        val = ref;
        while(val != 1){
            st = to_string(val) + " " + st;
            val = g[val];
        }
        st = "1 " + st;
        cout << st << endl;
    }
}