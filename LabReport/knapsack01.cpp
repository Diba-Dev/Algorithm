#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum profit
int knapSack(int W, int wt[], int val[], int size) {
    // Declare the DP table
    int dp[size + 1][W+1];

    // Initialize the DP table (0 profit for 0 items or 0 capacity)
    for (int i = 0; i <= size; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Return the maximum profit for the full capacity
    return dp[size][W];
}

// Driver Code
int main() {
    int size;
    cout << "Enter the number of items : ";
    cin >> size;

    int profit[size], weight[size];

    for (int i = 0; i < size; i++) {
        cout << "(profit - weight) for item " << i + 1 << " :";
        cin >> profit[i] >> weight[i];
    }

    cout << "Enter the capacity: ";
    int capacity;
    cin >> capacity;

    cout << "Maximum Profit: " << knapSack(capacity, weight, profit, size) << endl;

    return 0;
}