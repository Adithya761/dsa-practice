class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<vector<int>> A;
        for(int i = 0;i < n;i++){
            A.push_back({aliceValues[i] + bobValues[i],aliceValues[i],bobValues[i]});
        }
        sort(begin(A),end(A),[](const auto &x ,const auto &y){
            return x[0] > y[0];
        });
        // for(auto &x : A){
        //     cout << x.first << " " << x.second<< endl;
        // }
       // sort(begin(A),end(A));
        int alice = 0;
        int bob = 0;

        for(int i = 0;i < A.size();i++){
            if(i % 2){
                bob += A[i][2];
            }
            else{
                alice += A[i][1];
            }
        }
        if(alice == bob) return 0;
        return alice > bob ? 1 : -1;
    }
};