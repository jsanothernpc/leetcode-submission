class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0;
        int e = s.size()-1;
        while(l<e) swap(s[l++], s[e--]);
    }
};