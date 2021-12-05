class Solution {
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]]++;
            }
            else {
                mp[s[i]] = 1;
            }
        }
        int index = -1;
        for (int i = 0; i < s.length(); i++) {
            if (mp[s[i]] == 1) {
                index = i;
                break;
            }
        }
        return index;
    }

private:
    map<char, int>mp;
};