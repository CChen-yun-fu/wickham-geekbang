class Solution {
public:
    //子域名访问计数
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string>ans;
        unordered_map<string, int>mp;
        for (string& s : cpdomains) {
            int index = s.find(' '); //先找到第一个空格位置
            int num = stoi(s.substr(0, index)); // 转换第一个空格前面的数字
            string ipname = s.substr(index + 1); // 第一个空格后面的字符串

            while (index > 0) {
                mp[ipname] += num; // 字符串映射到map
                index = ipname.find('.');// 继续分割第一个空格后面字符串的字符，然后映射到map;
                ipname = ipname.substr(index + 1);
            }
        }
        for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
            ans.push_back(to_string(iter->second) + " " + iter->first);
        }
        return ans;
    }
};