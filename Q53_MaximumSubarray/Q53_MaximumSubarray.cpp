#include <iostream>
#include <vector>

using namespace std;

int maxSubArrayBruteForce(vector<int>& nums) {
    int maxSum = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        int currentSum = 0;

        for (int j = i; j < nums.size(); j++) {
            currentSum += nums[j];
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
}

int maxSubArray(vector<int>& nums) {
    int localMax = 0;
    int globalMax = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        localMax = max(nums[i], nums[i] + localMax);
        if (localMax > globalMax) {
            globalMax = localMax;
        }
    }

    return globalMax;
}

int main()
{
    vector<int> nums = { 1, -2, 3, 4, -5, 5, -3 };

    cout << maxSubArrayBruteForce(nums) << endl;

    cout << maxSubArray(nums);

    return 0;
}