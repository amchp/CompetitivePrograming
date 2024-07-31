#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int days[n];
    for(int i = 0; i < n; ++i){
        cin >> days[i];
    }
    int last = 0;
    int offDays = 0;
    for(int i = 0; i < n; ++i){
        if(days[i] == 0){offDays++; last = 0;}
        else if(days[i] == 1 && last != 1) last = 1;
        else if (days[i] == 1 && last == 1) {offDays++; last = 0;}
        else if(days[i] == 2 && last != 2)last = 2;
        else if (days[i] == 2 && last == 2){offDays++; last = 0;}
        else if(days[i] == 3){
            if(last == 2) last = 1;
            else if(last == 1) last = 2;
            else if(i < n - 1){
                    if(days[i+1] == 1) last = 2;
                    if(days[i+1] == 2) last = 1;
                    if(days[i+1] == 3) last = 0;
            }
        }
    }
    cout << offDays << endl;
}