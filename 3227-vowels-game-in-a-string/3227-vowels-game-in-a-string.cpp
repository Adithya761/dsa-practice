class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        int n = s.size();
        //vector<int> arr(n,0);
        int vow = 0;
        for(int i = 0;i < s.size() ;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                vow++;
            }
        }
        if(vow == 0) return false;

        return true;

    }
};