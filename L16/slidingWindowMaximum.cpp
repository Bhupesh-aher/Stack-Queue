#include<bits/stdc++.h>
using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    for(int i = 0; i<=nums.size() - k; i++){
        int maxi = nums[i];
        for(int j = i; j<i+k; j++){
            maxi = max(maxi, nums[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
}

// Tc - O(n - k) * O(k) 
// SC - O(n - k)

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;

    for(int i = 0; i<nums.size(); i++){
        if(!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        } 
        dq.push_back(i);
        if(i >= k - 1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}

// TC - O(2n) 
// SC - O(1) 

int main(){
    vector<int> nums =  {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    
    for(auto it: ans) cout << it << " ";

}