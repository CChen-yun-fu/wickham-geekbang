class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        for (int i = 0; i < jewels.length(); i++) {
            dp.insert(jewels[i]);
        }
        int ans = 0;
        for (int j = 0; j < stones.length(); j++) {

            if (dp.find(stones[j]) != dp.end()) {
                ans++;
            }
        }
        return ans;
    }
    set<char>dp;
};