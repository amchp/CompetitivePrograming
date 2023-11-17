#include <iostream>

using namespace std;

int main(){
    int t, n, c, m, chocolates, tickets, spent;
    cin >> t;
    while(t--){
        cin >> n >> c >> m;
        chocolates = 0;
        chocolates +=  n / c;
        tickets = chocolates;
        while(tickets / m  > 0){
            spent = tickets / m;
            chocolates += spent;
            tickets -= m*spent;
            tickets += spent;
        }
        cout << chocolates << endl;
    }
}