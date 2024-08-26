// Author: Fatih Baskın
// Question Link: https://algoleague.com/problem/aycans-house/detail
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int32_t main()
{
    // Fast input-output
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Read the input
    int n = 0;
    cin >> n;
    vector<int> rooms(n, 0);
    for (int i = 0; i < n; i++)
        cin >> rooms[i];

    // Do the prefix sum (index 0 is dummy)
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + rooms[i - 1];

    // Count the number of subarrays with sum 0 using prefix sum
    // If the prefix sum value is the same after k elements, then the sum of those k elements is 0
    // Ex:           1 2 3 -3 2 1
    // Prefix sum: 0 1 3 6  3 5 6
    // Sum of elementts -3 and 3 is 0
    // Prefix before and after these elements are the same (3)
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
        mp[prefix_sum[i]]++;

    int counter = 0;
    for (auto i : mp)
    {
        int temp = i.first;
        int freq = i.second;

        // If the temp value is 0, then all the elements from the beginning to the current element have sum 0, so we need to add them to the counter
        if (temp == 0)
            counter += freq;

        // Combination of 2 from frequency of the same prefix sum
        counter += (freq * (freq - 1)) / 2;
    }

    cout << counter << endl;

    return 0;
}