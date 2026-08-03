class Solution {
public:
    int solve(vector<int>& nums,int l,int r,bool turn){
        if(l > r) return 0;

        if(!turn){
            return min(solve(nums,l + 1,r,!turn),solve(nums,l,r -1,!turn));
        }

        return max(nums[l] + solve(nums,l + 1,r,!turn) , nums[r] + solve(nums,l,r -1,!turn));
    }
    bool predictTheWinner(vector<int>& nums) {
        int s = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int p1 = solve(nums,0,n-1,true);
        int p2 = s - p1;
        return p1 >= p2;
    }
};

    //  int i = 1;
    //     int j = nums.size() -1;
    //     int move = 1;
    //     int p1 = nums[0];
    //     int p2 = 0;
    //     while(i < j){
    //         int val = 0;
    //         if(nums[i] < nums[j]){
    //             val = nums[j];
    //             j--;
    //         }
    //         else{
    //             val = nums[i];
    //             i++;
    //         }

    //         if(move % 2 == 0){
    //             p1 += val;
    //         }
    //         else{
    //             p2 += val;
    //         }
             
    //         move++;
    //     }

    //     return p1 > p2;