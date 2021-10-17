class Solution {
public:
    //����Ķ�
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.count(nums[i])) {
                mp[nums[i]][0]++; //Ԫ�صĴ���
                mp[nums[i]][2] = i; //Ԫ�����������Զλ��
            }
            else {
                mp[nums[i]] = { 1,i,i };//�������map �У�����룬��1��i��i������ ����һ�Σ������������ֵ�λ�ö���i
            }
        }
        int maxnums = 0; //Ԫ�س������Ĵ���
        int minlen = 0;
        for (auto& [_, vec] : mp) {
            if (maxnums < vec[0]) {
                maxnums = vec[0];
                minlen = vec[2] - vec[1] + 1;// ���³��ִ�������Ԫ�صĿ�ȣ������ֵ�λ��-���γ��ֵ�λ�ã�
            }
            else  if (maxnums == vec[0]) {
                if (minlen > vec[2] - vec[1] + 1)
                    minlen = vec[2] - vec[1] + 1;//���¶�
            }
        }
        return minlen;
    }
};