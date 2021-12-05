class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sMap;
        unordered_map<char, char> tMap;
        for (int i = 0, j = 0; i < s.size(); i++, j++) {
            if (sMap.find(s[i]) == sMap.end()) { // map1保存s[i] 到 t[j]的映射
                sMap[s[i]] = t[j];
            }
            if (tMap.find(t[j]) == tMap.end()) { // map2保存t[j] 到 s[i]的映射
                tMap[t[j]] = s[i];
            }
            // 映射不对应
            if (sMap[s[i]] != t[j] || tMap[t[j]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};