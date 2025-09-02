#include <bits/stdc++.h>
using namespace std;
int comparisons=0;

int partition(vector<int> &arr, int low, int high){
    // int n = high - low;
    // int mid=n/2+low;
    // int mo3;
    // if((arr[low]<=arr[mid] && arr[mid]<=arr[high]) || (arr[high]<=arr[mid] && arr[mid]<=arr[low])){
    //     mo3=mid;
    // }
    // else if((arr[mid]<=arr[low] && arr[low]<=arr[high]) || (arr[high]<=arr[low] && arr[low]<=arr[mid])){
    //     mo3=low;
    // }
    // else{
    //     mo3=high;
    // }
    srand(time(0)); // Seed for random number generation
    int mo3=rand() % (high - low + 1) + low; // Randomly select a pivot index
    int pivot = arr[mo3];
    swap(arr[low], arr[mo3]);
    int i=low+1;
    for(int j=low+1; j<=high; j++){
        if(arr[j]<pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i-1]);
    comparisons += (high - low);
    return i - 1;
}

void quicksort(vector<int> &arr, int low, int high){
    if(low < high){
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[i] = x;   
    }
    quicksort(arr, 0, arr.size() - 1);
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Sorted array: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}