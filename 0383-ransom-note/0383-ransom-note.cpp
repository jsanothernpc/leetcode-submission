class Solution {
public:
    bool canConstruct(string rN, string m) {
        unordered_map<char , int>mpp;
        for(char ch : m){
            mpp[ch]++;
        }
        for(char ch : rN){
            if(mpp[ch] <= 0) return false;
            mpp[ch]--;
        }
        return true;
    }
};