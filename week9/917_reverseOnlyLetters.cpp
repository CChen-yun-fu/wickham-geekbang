class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (isChar(s[left]) && isChar(s[right])) {
                swap(s[left], s[right]);
            }
            if (isChar(s[left]) && !isChar(s[right])) {
                --right;
            }
            else if (!isChar(s[left]) && isChar(s[right])) {
                ++left;
            }
            else {
                left++;
                right--;
            }
        }
        return s;
    }
private:
    bool isChar(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            return true;
        }
        return false;
    }
};