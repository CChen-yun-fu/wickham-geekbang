class Solution {
public:
    string reverseWords(string s) {
        vector<string>vec;
        string tmpstr;
        int index = 0;
        int endindex = s.length() - 1;
        while (s[index] == ' ' && index <= s.length()) { // ȥ��ǰ��ո��λ��
            index++;
        }
        while (s[endindex] == ' ' && endindex >= 0) { // ȥ������ո��λ��
            endindex--;
        }

        while (index <= endindex) {
            if (s[index] == ' ') {
                vec.push_back(tmpstr);//���ո�ǰ�ĵ��ʱ���ֵ������
                tmpstr.clear();
                int i = index;

                tmpstr += ' ';
                vec.push_back(tmpstr);
                while (s[i] == ' ') {// ���������Ŀո�ֻ����һ���ո�
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

        vec.push_back(tmpstr); // ���һ���ո����ĵ���
        reverse(vec.begin(), vec.end());// ��ת
        tmpstr.clear();

        for (int i = 0; i < vec.size(); i++) { //����ת��ĵ��� ƴ�ӳ��ַ���
            tmpstr += vec[i];
        }

        return tmpstr;
    }
};