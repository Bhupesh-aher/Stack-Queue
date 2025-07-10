#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallestElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for(int i = n-1; i>=0; i--){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return ans;
}
// TC - O(2N) SC - O(N)



int main(){
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans(nextSmallestElement(arr));
    for(auto it: ans) cout << it << " ";

}

