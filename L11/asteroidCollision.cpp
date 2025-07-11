#include<bits/stdc++.h>
using namespace std;


vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> st;
    for(int i = 0; i<asteroids.size(); i++){
        if(asteroids[i] > 0) st.push_back(asteroids[i]);
        else {
            while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])){
                st.pop_back();
            }
            if(!st.empty() && st.back() == abs(asteroids[i])){
                st.pop_back();
            }
            else if(st.empty() || st.back() < 0) st.push_back(asteroids[i]);
        }
    }
    
    return st;
}

// TC - O(2N) SC - O(N) 


int main(){
    vector<int> arr = {4, 7, 1, 1, 2, -3, -7, 17, 15, -18, -19};
    vector<int> ans = asteroidCollision(arr);
    
    for(auto it: ans) cout << it << " ";
}