class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        int len = 1e9;
        for (string str : strs) {
            if (str.length() <= len) {
                len = str.size();
            }
        }

        int low = 1;
        int high = len;

        while (low <= high) {
            int middle = (low + high) / 2;
            if (isCommonPrefix(strs, middle)) {
                low = middle + 1;
            }
            else {
                high = middle - 1;
            }
        }
        return strs[0].substr(0, (low + high) / 2);
    }
private:
    bool isCommonPrefix(vector<string>& strs, int length) {
        string tmp = strs[0].substr(0, length);
        for (int i = 0; i < strs.size(); i++) {
            string tmpstr = strs[i].substr(0, length);
            if (tmp != tmpstr) {
                return false;
            }
        }
        return true;
    }
};