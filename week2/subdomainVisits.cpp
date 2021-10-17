class Solution {
public:
    //���������ʼ���
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string>ans;
        unordered_map<string, int>mp;
        for (string& s : cpdomains) {
            int index = s.find(' '); //���ҵ���һ���ո�λ��
            int num = stoi(s.substr(0, index)); // ת����һ���ո�ǰ�������
            string ipname = s.substr(index + 1); // ��һ���ո������ַ���

            while (index > 0) {
                mp[ipname] += num; // �ַ���ӳ�䵽map
                index = ipname.find('.');// �����ָ��һ���ո�����ַ������ַ���Ȼ��ӳ�䵽map;
                ipname = ipname.substr(index + 1);
            }
        }
        for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
            ans.push_back(to_string(iter->second) + " " + iter->first);
        }
        return ans;
    }
};