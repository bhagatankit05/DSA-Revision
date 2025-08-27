//this is imp questions for an interview. which use kadane's algorithm. for maximum subarray sum.
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100]; 
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_so_far = arr[0];   
    int current_sum = arr[0]; 

    for (int i = 1; i < n; i++) {
        
        current_sum = max(arr[i], current_sum + arr[i]);

        max_so_far = max(max_so_far, current_sum);
    }

    cout << "Maximum Subarray Sum = " << max_so_far << endl;

    return 0;
}
