class Solution {
public:
    int n;
    int dp[50002];
    int solve(int i,vector<int>& nums){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int sum = 0;
        int best = INT_MIN;
        for(int k = 0;k < 3 && i + k < n;k++){
            sum += nums[i + k];
            best = max(best , sum - solve(i + k + 1,nums));
        }
        return dp[i] = best;
    }
    string stoneGameIII(vector<int>& s) {
        memset(dp, -1 ,sizeof(dp));
        // int tot = accumulate(begin(s),end(s),0);
        n = s.size();
        int maxS = solve(0,s);
        // int p2 = tot - p1;
       // cout << p1;
        if(maxS == 0) return "Tie";
        if(maxS > 0) return "Alice";
        return "Bob";
    }
};

// int take_1 = 0;
//         int take_2 = 0;
//         int take_3 = 0;
//         if(i + 1 <= n){
//             take_1 = nums[i] - solve(i + 1,n,nums);
//         }
//         if(i + 2 <= n){
//             take_2 = nums[i] + nums[i + 1] - solve(i + 2,n,nums);
//         }
//         if(i + 3 <= n){
//             take_3 = nums[i] + nums[i + 1]+ nums[i + 2] - solve(i + 3,n,nums);
//         }

//         return max(take_1 , max(take_2,take_3));