#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    vector<int> stocks;
    StockSpanner() {
        
    }
    
    int next(int price) {
        stocks.push_back(price);
        int cnt = 1;
        for(int i = stocks.size() - 2; i>=0; i--){
            if(stocks[i] <= price) cnt++;
            else break;
        }
        return cnt;
    }
};

// TC - O(no of days) for every next() 
// Sc - O(total no of next calls)



class StockSpanner {
public:
    stack<pair<int, int>> st;
    int ind = -1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        ind ++;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price, ind}); 
        return ans;
    }
};

// TC - O(2N)  pge
// SC - O(N) 

int main(){
    StockSpanner stock;
    cout << stock.next(7) << endl; // return 1
    cout << stock.next(2) << endl;  // return 1
    cout << stock.next(1) << endl;  // return 1
    cout << stock.next(3) << endl;  // return 3
    cout << stock.next(3) << endl;  // return 4
    cout << stock.next(1) << endl;  // return 1
    cout << stock.next(8) << endl;  // return 7
}