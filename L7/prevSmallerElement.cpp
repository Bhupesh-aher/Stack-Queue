#include<bits/stdc++.h>
using namespace std;

vector<int> prevSmallerElement(vector<int>& arr) {
    vector<int> ans;
    for(int i = 0; i<arr.size(); i++){
        bool flag = false;
        for(int j = i - 1; j>=0; j--){
            if(arr[j] < arr[i]) {
                ans.push_back(arr[j]);
                flag = true;
                break;
            }
        }
        if(flag == false) ans.push_back(-1);
    }
    return ans;
}
// TC - O(N^2) SC - O(1)


vector<int> prevSmallerElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for(int i = 0; i<arr.size(); i++){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return ans;
}
// TC - O(2N) SC - O(1)



int main(){
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans(prevSmallerElements(arr));
    for(auto it: ans) cout << it << " ";

}