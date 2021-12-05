class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>ground;
        for (string& s : strs) {
            string copyStr = s;
            sort(copyStr.begin(), copyStr.end());
            if (ground.find(copyStr) == ground.end())
                ground[copyStr] = {};
            ground[copyStr].push_back(s);
        }
        vector<vector<string>>ans;
        for (const pair<string, vector<string>>& pa : ground) {
            ans.push_back(pa.second);
        }
        return ans;
    }
};