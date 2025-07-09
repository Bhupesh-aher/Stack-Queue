#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements2(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size();
    for(int i = 0; i<n; i++){
        bool flag = false;
        for(int j = i + 1; j<i+n; j++){
            int ind = j % n;
            if(arr[ind] > arr[i]){
                flag = true;
                ans.push_back(arr[ind]);
                break;
            }
        }
        if(flag == false) ans.push_back(-1);
    }
    return ans;
}
// TC - O(N^2) SC - O(1)


vector<int> nextGreaterElements2(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for(int i = 2 * n - 1; i>=0;  i--){                 // O(2N)
        while(!st.empty() && st.top() <= arr[i % n]){      // O(2N)
            st.pop();
        }
        if(i < n){
            ans[i] = st.empty() ? -1 : st.top();
        }
        st.push(arr[i % n]);
    }
    return ans;
}

// TC - O(4N) SC - O(2N)

int main(){
    vector<int> arr = {2, 10, 12, 1, 11};
    vector<int> ans(nextGreaterElements2(arr));
    for(auto it: ans) cout << it << " ";

}