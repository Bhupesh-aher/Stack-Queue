#include<bits/stdc++.h>
using namespace std;


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

vector<int> prevSmallerElements(vector<int>& arr) { // PSE
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = 0; i<arr.size(); i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    vector<int> nse = findNSE(heights);
    vector<int> pse = prevSmallerElements(heights);
    for(int i = 0; i<heights.size(); i++){
        maxArea = max(maxArea, heights[i] * (nse[i] - pse[i] - 1));
    }
    return maxArea;
}

// TC - O(5N) SC - O(4N) 



// optimal solution
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;
    stack<int> st;
    for(int i = 0; i<heights.size(); i++){
        while(!st.empty() && heights[st.top()] > heights[i]){
            int element = st.top();
            st.pop();
            int nse = i; 
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[element] * (nse - pse -1));
        }
        st.push(i);
    }

    while(!st.empty()){
        int nse = n;
        int element = st.top();
        st.pop();
        int pse = st.empty() ? -1 : st.top(); 
        maxArea = max(maxArea, heights[element] * (nse - pse -1));
    }
    return maxArea;
}

// TC - O(2N) + O(N) 

int main(){
    vector<int> arr = {2,1,5,6,2,3};
    cout << largestRectangleArea(arr);
    
    
}