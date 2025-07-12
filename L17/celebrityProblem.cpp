#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> knowMe(n, 0);
    vector<int> iKnow(n, 0);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(matrix[i][j] == 1){
                knowMe[j] ++;
                iKnow[i]++;
            }
        }
    }

    for(int i = 0; i<n; i++){
        if(knowMe[i] == n-1 && iKnow[i] == 0) return i;
    }
    return -1;
}
// TC - O(n * m) + O(n) 
// SC - O(2N) 


int celebrity(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    int top = 0;
    int bottom = n-1;

    while(top < bottom){
        if(matrix[top][bottom] == 1) top ++;
        else if(matrix[bottom][top] == 1) bottom --;
        else top ++, bottom --;
    }

    if(top > bottom) return -1;

    for(int i = 0; i<n; i++){
        if(top == i) continue;
        if(matrix[top][i] == 0 && matrix[i][top] == 1) continue;
        else return -1;
    }
    return top;
}

// TC - O(2N)  
// Sc - O(1)

int main(){
    vector<vector<int>> matrix = {
    {0, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 1, 0, 0},
    {1, 1, 0, 0}};
    
    cout << celebrity(matrix);
}