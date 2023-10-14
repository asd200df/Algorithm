// 기지국 설치 (Lev3) 설계



1 2 3 4 5 6
1 1 1 1 1 0


-----

4 8 17 19 21
2 6 8 12 15 16 17



11 [7, 10] 1	2
1 2 3 4 5 6 7 8 9 10 11
0 0 0 0 0 1 1 1 1 1  1

6 - 1
diff 5
pre 8

2
-1

count == 2

diff 9 - 8


2 1 1
1 2 3


5 [1, 2, 3, 4, 5] 0



1 2 3 4 5 6
0 1 1 1 1 1

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
1 1 1 0 0 0 0 0 0 0  0  0  0  1  1  1

pre = 3
diff = 14 - 3 = 11
cover = 5
11 >> 6 >> 1 >> -4
      1 >> 2 >> 3



1 2 3 4 5 6
1 1 1 1 1 0	


1 2 3 4 5 6 7 8 9 10 11
1 1 1 1 1 0 0 0 0 0  0
cover 3
pre == 11 - 5 = 6



1 2 3 4 5 6 7 8 9 10 11
1 1 0 1 1 1 0 0 0 0  0


5
1 2 3 4 5
0 0 0 0 0
1 1 1 1 1 



# 실패 - 테스트 (17/21), 효율성 테스트 (0/4)
// 기지국 설치
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

// solve
int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    // sort
    sort(stations.begin(), stations.end());
    
    // Exception
    bool flag = true;
    if(n == stations.size()){ flag = false; }

    // processor
    int count = 0;
    int pre = 0; // 이전 위치
    int cover = w + w + 1; // cover 가능한 범위
    for(int i = 0; i < stations.size(); i++){
        int st = stations[i] - w;
        int ed = stations[i] + w;
        
        // debug
        // cout << st << " ~ " << ed << "\n";
        
        int diff = st - (pre + 1);
        
        if(diff < 1 && i != 0) { continue; }
        
        pre = ed;
  
        while(diff > 0){
            diff -= cover;
            count++;
        }
    }
    
    // last check
    pre = stations[stations.size() - 1] + w;
    int diff2 = n - pre;
    while(diff2 > 0){
        diff2 -= cover;
        count++;
    }
    
    // update
    // answer = count;
    if(flag){ answer = count; }
    else { answer = 0; }

    // return result !
    return answer;
}