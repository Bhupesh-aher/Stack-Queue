#include<bits/stdc++.h>
using namespace std;


void prefix(vector<int> &prefix, vector<int>& height){ // O(N)
    prefix[0] = height[0];
    for(int i = 1; i<height.size(); i++){
        prefix[i] = max(prefix[i-1], height[i]);
    }
}
void suffix(vector<int> &suffix, vector<int>& height){  // O(N)
    int n = height.size();
    suffix[n-1] = height[n-1];
    for(int i = n-2; i>=0; i--){
        suffix[i] = max(suffix[i+1], height[i]);
    }
}
int trap(vector<int>& height) {
    int n = height.size();
    vector<int> prefixMax(n, 0);
    vector<int> suffixMax(n, 0);
    prefix(prefixMax, height);
    suffix(suffixMax, height);

    int total = 0; 
    for(int i = 0; i<n; i++){                          // O(N)
        int leftMax = prefixMax[i];
        int rightMax = suffixMax[i];
        if(height[i] < leftMax && height[i] < rightMax){
            total += min(leftMax, rightMax) - height[i];
        }
    }
    return total;
}

// TC - O(3N) SC - O(2N) 


int trap(vector<int>& height) {
    int n = height.size();
    int leftMax = 0, rightMax = 0;
    int total = 0;
    int l = 0, r = n -1;

    while(l < r){                   // O(N)
        if(height[l] <= height[r]){
            if(leftMax > height[l]){
                total += leftMax - height[l];
            }
            else leftMax = height[l];
            l++;
        }
        else {
            if(rightMax > height[r]){
                total += rightMax - height[r];
            }
            else rightMax = height[r];
            r--;
        }
    }
    return total;
}

// TC - O(N) SC - O(1)

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height);
}