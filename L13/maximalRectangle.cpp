#include<bits/stdc++.h>
using namespace std;


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
}    // TC - O(2N) + O(N)

int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> prefixSum(n, vector<int>(m, 0));

    for(int j = 0; j<m; j++){
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += matrix[i][j] - '0';
            if(matrix[i][j] == '0') sum = 0;
            prefixSum[i][j] = sum;
        }
    }
    int maxArea = 0;
    for(int i = 0; i<n; i++){
        maxArea = max(maxArea, largestRectangleArea(prefixSum[i]));
    }
    return maxArea;
}

// TC - O(n * m) + O(n * 2n) 
// SC - O(n * m) + O(n) 

int main(){
    vector<vector<char>> matrix = {
    {'1', '0', '1', '0', '0'},
    {'1', '0', '1', '1', '1'},
    {'1', '1', '1', '1', '1'},
    {'1', '0', '0', '1', '0'}};
    
    cout << maximalRectangle(matrix);
    
}