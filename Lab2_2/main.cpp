#include <iostream>
#include <chrono>
using namespace std;

//QuickSort is Big O(N^2) in the worst case but under certain conditions Big O(N) - linear time
//Changes original array
//Changing from Lomuto Partitioning to Median of Medians should ensure Big O(N) worst case

int lomutoPartition(int arr[], int low, int high){
    int pivot = arr[high];
    int index = low - 1;
    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot){
            index++;
            swap(arr[index], arr[j]);
        }
    }
    swap(arr[index+1], arr[high]);
    return index+1;
}

int kthSmallest(int arr[], int n, int k){

    int low = 0, high = n-1;
    while(low <= high){
        int pivot = lomutoPartition(arr, low, high);
        if (pivot == k-1)
            return pivot;
        else if (pivot > k-1)
            high = pivot-1;
        else
            low = pivot+1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 4, 5, 8, 11, 6, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 4;
    auto start = chrono::high_resolution_clock::now();
    cout << k << "th smallest element is: " << arr[kthSmallest(arr, n, k)];
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = stop - start;
    cout << "\nTime to find the " << k << "th smallest element using naive approach: " << duration.count() << "s\n";
    return 0;
}