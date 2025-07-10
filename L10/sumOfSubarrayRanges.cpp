#include<bits/stdc++.h>
using namespace std;

long long subArrayRanges(vector<int>& nums) {
    long long ans = 0;
    for(int i = 0; i<nums.size(); i++){
        int smallest = nums[i];
        int largest = nums[i];
        for(int j = i; j<nums.size(); j++){
            smallest = min(smallest, nums[j]);
            largest = max(largest, nums[j]) ;
            ans += largest - smallest;
        }
    }
    return ans;
}
// TC - O(N^2) SC - O(1)



// optimal solution
vector<int> findNSE(vector<int>& arr){
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    for(int i = n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

vector<int> findPSEE(vector<int>& arr){  // previous smaller & equal element 
    int n = arr.size();
    vector<int> pse(n, 0);
    stack<int> st;

    for(int i = 0; i<n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}

long long sumSubarrayMins(vector<int>& arr) {
    vector<int>nse(findNSE(arr));
    vector<int>pse(findPSEE(arr));

    long long total = 0;

    for(int i = 0; i<arr.size(); i++){
        int left = i - pse[i];
        int right = nse[i] - i;
        total += 1LL * left * right * arr[i];
    }
    return total;
}      // TC - O(5N) SC - O(4N)


vector<int> findNGEE(vector<int>& arr){
    int n = arr.size();
    vector<int> ngee(n);
    stack<int> st;

    for(int i = n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] < arr[i]){
            st.pop();
        }
        ngee[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ngee;
}

vector<int> findPGE(vector<int>& arr){  // previous smaller & equal element 
    int n = arr.size();
    vector<int> pge(n, 0);
    stack<int> st;

    for(int i = 0; i<n; i++){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        pge[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pge;
}

long long sumSubarrayMax(vector<int>& arr) {
    vector<int>ngee(findNGEE(arr));
    vector<int>pge(findPGE(arr));

    long long total = 0;

    for(int i = 0; i<arr.size(); i++){
        int left = i - pge[i];
        int right = ngee[i] - i;
        total += 1LL * left * right * arr[i];
    }
    return total;
}       // TC - O(5N) SC - O(4N)


long long subArrayRanges(vector<int>& nums) {
    long long maxSum = sumSubarrayMax(nums);
    long long minSum = sumSubarrayMins(nums);
    return maxSum - minSum;
}
// TC - O(10N) which as good as O(N) and much much better than O(n^2) 
// SC - O(N) 

int main(){
    vector<int> arr = {1, 4, 3, 2};
    cout << subArrayRanges(arr);
}