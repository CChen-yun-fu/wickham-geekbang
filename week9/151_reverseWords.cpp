class Solution {
public:
    string reverseWords(string s) {
        vector<string>vec;
        string tmpstr;
        int index = 0;
        int endindex = s.length() - 1;
        while (s[index] == ' ' && index <= s.length()) { // 去除前面空格的位置
            index++;
        }
        while (s[endindex] == ' ' && endindex >= 0) { // 去除后面空格的位置
            endindex--;
        }

        while (index <= endindex) {
            if (s[index] == ' ') {
                vec.push_back(tmpstr);//将空格前的单词保存值数组里
                tmpstr.clear();
                int i = index;

                tmpstr += ' ';
                vec.push_back(tmpstr);
                while (s[i] == ' ') {// 跳过连续的空格，只保存一个空格
                    i++;
                }
                index = i;
                tmpstr.clear();

            }
            else {
                tmpstr += s[index];
                index++;
            }
        }

        vec.push_back(tmpstr); // 最后一个空格后面的单词
        reverse(vec.begin(), vec.end());// 反转
        tmpstr.clear();

        for (int i = 0; i < vec.size(); i++) { //将反转后的单词 拼接成字符串
            tmpstr += vec[i];
        }

        return tmpstr;
    }
};