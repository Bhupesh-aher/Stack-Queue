#include<bits/stdc++.h>
using namespace std;


int sumSubarrayMins(vector<int>& arr) {
    long long sum = 0;
    int mod = (int)(1e9+7);

    for(int i = 0; i<arr.size(); i++){
        int mini = arr[i];
        for(int j = i; j<arr.size(); j++){
            mini = min(mini, arr[j]);
            sum = (sum + mini) % mod;
        }
    }
    return (int)sum;
}
// TC - O(N^2) SC - O(1) 


// Optimal solution
vector<int> findNSE(vector<int>& arr){
    int n = arr.size();
    vector<int> nse(n, 0);
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

int sumSubarrayMins(vector<int>& arr) {
    vector<int>nse(findNSE(arr));
    vector<int>pse(findPSEE(arr));

    int total = 0;
    int mod = (int)(1e9+7);

    for(int i = 0; i<arr.size(); i++){
        int left = i - pse[i];
        int right = nse[i] - i;
        total = (total + (right * left * (1LL)*arr[i]) % mod) % mod;
    }
    return total;
}

// TC - O(5N) SC - O(4N)

int main(){
    vector<int> arr = {3, 1, 2, 4};
    cout << sumSubarrayMins(arr);
}