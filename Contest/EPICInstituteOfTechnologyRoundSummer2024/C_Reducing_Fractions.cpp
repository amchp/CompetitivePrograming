#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int nax = 1e5 + 200;
const double pi = acos(-1);
const double eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

vector<int> primes;

void sieve() {
    int mx = 1e4 + 1;
    vector<int> sv(mx, false);
    for (int i = 2; i <= mx - 1; ++i) {
        if (sv[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j < mx; j += i) {
            sv[j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(20) << fixed;
    
    sieve();
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    
    map<int, vector<int>> fp;
    
    for (int i = 0; i < n; ++i) {
        int& x = a[i];
        int tmp = x;
        for (int& p : primes) {
            while (tmp % p == 0) {
                fp[p].push_back(i);
                tmp /= p;
            }
        }
    }
    
    for (int i = 0; i < m; ++i) {
        int& x = b[i];
        int tmp = x;
        for (int& p : primes) {
            while (tmp % p == 0) {
                vector<int>& vec = fp[p];
                if (vec.size() > 0) {
                    a[vec.back()] /= p;
                    x /= p;
                    vec.pop_back();
                }
                tmp /= p;
            }
        }
        if (tmp != 1) {
            vector<int>& vec = fp[tmp];
            if (vec.size() > 0) {
                a[vec.back()] /= tmp;
                x /= tmp;
                vec.pop_back();
            }
        }
    }
    
    cout << n << ' ' << m << '\n';
    for (int& v : a) {
        cout << v << ' ';
    }
    cout << '\n';
    for (int& v : b) {
        cout << v << ' ';
    }
    cout << '\n';
}


vector<int> find_factors(int x){}

int gcd(int a, int b){
    int gcd = __gcd(a, b);
}

