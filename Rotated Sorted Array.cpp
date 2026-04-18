#include <iostream>
#include <string>

using namespace std;

int search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        // Left half is sorted
        if (arr[left] <= arr[mid]) {
            if (arr[left] <= target && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (arr[mid] < target && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main(){
    int arr[] = {4,5,6,7,0,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result;
    result = search(arr, size, 4);
    cout << result <<endl;
    return 0;
}