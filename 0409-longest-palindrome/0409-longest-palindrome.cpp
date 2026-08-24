class Solution {
public:
    int longestPalindrome(string s) {
        int freq[128] = {0};
        for(char ch : s){
            freq[ch]++;
        }
        int ans = 0;
        int hasOdd = false;
        for(int i=0;i<128;i++){
            if(freq[i] % 2 == 0) ans+= freq[i];
            else{
                ans+=freq[i]-1;
                hasOdd = true;
            }   
        }
        
        if(hasOdd) ans++;
        return ans;
    }
};