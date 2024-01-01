#include <iostream>
using namespace std;

// Brute Force
int minSteps(int n) {
    // Base Case
    if(n == 1) {
        return 0;
    }

    // Recursive Call
    int x = minSteps(n - 1);

    int y = INT_MAX;
    if(n % 2 == 0) {
        y = minSteps(n / 2);
    }

    int z = INT_MAX;
    if(n % 3 == 0) {
        z = minSteps(n / 3);
    }

   // Small calculation for final output
    int ans = 1 + min(x, min(y, z));
    return  ans;
}

int minSteps_helper(int n, int *ans) {
    // Base Case
    if(n == 1) {
        return 0;
    }

    // Check if output already exists
    if(ans[n] != -1) {
        return ans[n];
    }

    // Recursive call
    int x = minSteps_helper(n - 1, ans);

    int y = INT_MAX;
    if(n % 2 == 0) {
        y = minSteps_helper(n / 2, ans);
    }
    
    int z = INT_MAX;
    if(n % 3 == 0) {
        z = minSteps_helper(n / 3, ans);
    }

    // Small calculation for final output
    int output = 1 + min(x, min(y, z));
    // Save output for future use
    ans[n] = output;

    return output;
}

// Memoization(Top-down approach)
int minSteps_2(int n) {
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++) {
        ans[i] = -1;
    }

    return minSteps_helper(n, ans);
}

int main() {
    int n;
    cin >> n;
    cout << "Min Steps to 1 = " << minSteps(n) << endl;
    cout << "Min Steps to 1 = " << minSteps_2(n) << endl;
}