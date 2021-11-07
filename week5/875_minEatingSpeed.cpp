class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxTime = 0;
        for (int& pile : piles) {
            maxTime = max(pile, maxTime);
        }
        int left = 1; int right = maxTime;
        while (left < right) {
            int mid = (left + right) / 2;
            if (caculateSumTiem(piles, mid) > h) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
    int caculateSumTiem(vector<int>& piles, int speed) {
        int sum = 0;
        for (int& num : piles) {
            sum += (num + speed - 1) / speed;;
        }
        return sum;
    }
};