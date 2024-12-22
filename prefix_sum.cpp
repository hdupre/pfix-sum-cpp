#include <iostream>
#include <vector>
using namespace std;

void buildPrefixSum(vector<int>& arr, vector<int>& prefix) {
    int n = arr.size();
    prefix.resize(n);
    
    // First element is same as original array
    prefix[0] = arr[0];
    
    // Build prefix sum array
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
}

// Get sum of range [left, right] inclusive
int getRangeSum(vector<int>& prefix, int left, int right) {
    if (left == 0) {
        return prefix[right];
    }
    return prefix[right] - prefix[left-1];
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> prefix;
    
    buildPrefixSum(arr, prefix);
    
    // Print original array
    cout << "Original array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;
    
    // Print prefix sum array
    cout << "Prefix sum array: ";
    for(int x : prefix) cout << x << " ";
    cout << endl;
    
    // Example range queries
    cout << "Sum of range [1,3]: " << getRangeSum(prefix, 1, 3) << endl;
    cout << "Sum of range [0,4]: " << getRangeSum(prefix, 0, 4) << endl;
    cout << "Sum of range [2,4]: " << getRangeSum(prefix, 2, 4) << endl;
    
    return 0;
}