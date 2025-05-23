#include<iostream>
using namespace std;
#include<vector>

class Solution {
  public:
  
    int maxProfit(vector<int>& prices,int start,int end) {
        int res = 0;
        
        for(int i=start; i<end; i++) {
            for(int j=i+1; j<=end; j++) {
                if(prices[j] > prices[i]) {
                    int curr = (prices[j] -prices[i]) + 
                        maxProfit(prices,start,i-1) + maxProfit(prices,j+1,end);
                        
                    if(curr > res) {
                        res = curr;
                    }
                }
            }
        }
        return res;
    }
    int maximumProfit(vector<int> &prices) {
        return maxProfit(prices,0,prices.size()-1);
    }
};



class Solution {
  public:
 
    int maximumProfit(vector<int> &prices) {
        int locmin = prices[0];
        int locmax = prices[0];
        int totalProfit = 0;
        int n = prices.size();
        
        int i=0;
        while(i < n-1) {
            
            while(i < n-1 && prices[i] >= prices[i+1]) { i++;}
            locmin = prices[i];
            
            while(i < n-1 && prices[i] <= prices[i+1]) { i++; }
            locmax = prices[i];
            
            totalProfit += (locmax - locmin);
        }
        
        return totalProfit;
    }
};



class Solution {
  public:
 
    int maximumProfit(vector<int> &prices) {
        int totalProfit = 0;
        int n = prices.size();
        
        int i=0;
        while(i < n-1) {
            if(prices[i] < prices[i+1]) {
                
                totalProfit += prices[i+1] - prices[i];
            }
            
            i++;
        }
        
        return totalProfit;
    }
};



/**  when only the one tansection is allowed  (one buy and on e sell) */

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int profit = 0;
        
        for(int i=0; i<prices.size(); i++) {
            for(int j=i+1; j<prices.size(); j++) {
                if(prices[j] > prices[i]) {
                    int c = prices[j] - prices[i];
                    if(profit < c) {
                        profit = c;
                    }
                }
            }
        }
        return profit;
    }
};


class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int profit = 0,minimum = prices[0];
        
        for(int i=1; i<prices.size(); i++) {
            
            if(minimum > prices[i]) {
                minimum = prices[i];
            }
            
            if(profit < prices[i]-minimum) {
                profit = prices[i]-minimum;
            }
        }
        return profit;
    }
};
