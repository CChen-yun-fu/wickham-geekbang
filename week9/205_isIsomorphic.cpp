class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sMap;
        unordered_map<char, char> tMap;
        for (int i = 0, j = 0; i < s.size(); i++, j++) {
            if (sMap.find(s[i]) == sMap.end()) { // map1����s[i] �� t[j]��ӳ��
                sMap[s[i]] = t[j];
            }
            if (tMap.find(t[j]) == tMap.end()) { // map2����t[j] �� s[i]��ӳ��
                tMap[t[j]] = s[i];
            }
            // ӳ�䲻��Ӧ
            if (sMap[s[i]] != t[j] || tMap[t[j]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};