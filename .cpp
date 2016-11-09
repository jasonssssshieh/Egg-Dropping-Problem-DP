//
//  main.cpp
//  Egg-dropping problem DP
//
//  Created by Zijian Xie on 2016/11/8.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class EggDrop{
private:
    int eggs;
    int floors;
public:
    EggDrop(int egg, int floor){
        eggs = egg;
        floors = floor;
    }
    
    int DP(){
        vector<vector<int>> dp(eggs + 1,vector<int>(floors + 1,0));
        // dp[i][j] 代表有i个鸡蛋，剩下有j层楼
        for(int f = 0; f <= floors; ++f){dp[1][f] = f;}
        
        for(int i = 2; i <= eggs; ++i){//鸡蛋数，从2个鸡蛋开始算
            for(int f = 1; f <= floors; ++f){//楼层数
                dp[i][f] = INT_MAX;
                for(int k = 1; k <= f; ++k){//有k种方案，从第1， 2，3，····，f层楼扔下去
                    //有两种情况：碎了和没碎，在这两种情况里面，我们挑选“需要try次数最多的那个”作为我们worst case
                    int current = 1 + max(dp[i-1][k-1],dp[i][f-k]);//worest case
                    dp[i][f] = min(dp[i][f], current);//the minized number
                }
            }
        }
        cout<< "In the worst case, number of throw is: " <<dp[eggs][floors]<<endl;
        return dp[eggs][floors];
    }
};

int main(int argc, const char * argv[]) {
    int egg = 2, floor = 200;
    EggDrop* test = new EggDrop(egg,floor);
    test->DP();
    return 0;
}

/*
f(n,m)===0,(m>=1)n,(n>=1)min1≤i≤n{max{f(i−1,m−1),f(n−i,m)}}+1
Another: http://ppwwyyxx.com/2013/Problem-of-Two-Eggs/
 */
