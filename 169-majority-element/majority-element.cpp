class Solution {
public:

    void merge(vector<int>& nums, int st, int mid, int end) {
        vector<int> temp;
        int i = st;
        int j = mid + 1;

        while(i <= mid && j <= end) {
            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            }
            else {
                temp.push_back(nums[j++]);
            }
        }

        while(i <= mid) {
            temp.push_back(nums[i++]);
        }

        while(j <= end) {
            temp.push_back(nums[j++]);
        }

        for(int idx = 0; idx < temp.size(); idx++) {
            nums[st + idx] = temp[idx];
        }
    }

    void mergeSort(vector<int>& nums, int st, int end) {
        if(st >= end) return;

        int mid = st + (end - st) / 2;

        mergeSort(nums, st, mid);
        mergeSort(nums, mid + 1, end);

        merge(nums, st, mid, end);
    }

    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        mergeSort(nums, 0, n - 1);

        int freq = 1;
        int ans = nums[0];

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]) {
                freq++;
            }
            else {
                freq = 1;
                ans = nums[i];
            }

            if(freq > n/2) {
                return ans;
            }
        }

        return ans;
    }
};