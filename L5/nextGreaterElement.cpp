#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr){
    vector<int> ans;
    for(int i = 0; i< arr.size(); i++){
        bool flag = false;
        for(int j = i+1; j<arr.size(); j++){
            if(arr[j] > arr[i]) {
                ans.push_back(arr[j]);
                flag = true;
                break;
            }
        }
        if(flag == false) ans.push_back(-1);
    }
    return ans;
}
// TC - O(N ^ 2) 
// SC - O(1)

vector<int> nextGreaterElements(vector<int> &arr){
    vector<int> ans;
    stack<int> st;

    for(int i = arr.size() - 1; i>=0; i--){

        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(arr[i]);
    }
    return ans;
}

// TC - O(2N) inner while loop is nor running everytime carefully notice
// that's why TC O(2N)
// SC - O(N) 


int main(){
    vector<int> arr = {6, 0, 8, 1, 3};
    vector<int> ans(nextGreaterElements(arr));
    for(auto it: ans) cout << it << " ";

}