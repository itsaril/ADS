#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    int minLength = n;
    for (int left = 0; left < n; left++) {
        int low = left, high = n-1;
        int minLen = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = prefixSum[mid] - prefixSum[left] + arr[left];

            if (sum >= k) {
                minLen = mid - left + 1;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        minLength = min(minLength, minLen);
    }

    cout << minLength << endl;

    return 0;
}
