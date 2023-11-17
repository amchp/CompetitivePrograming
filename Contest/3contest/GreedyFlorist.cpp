#include <iostream>
using namespace std;
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
// A function to implement bubble sort  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  

int main(){
    int n, k;
    cin >> n >> k;
    int flowers[n];
    for(int i = 0; i < n; ++i){
        cin >> flowers[i];
    }
    bubbleSort(flowers, n);

    int cost, flowersB;
    for(int i = 0; i < n; ++i){
        cost += (1+flowersB) * flowers[n- 1 - i];
        if((i + 1) % k == 0){
            flowersB++;
        }
        
    }
    cout << cost << endl;
}