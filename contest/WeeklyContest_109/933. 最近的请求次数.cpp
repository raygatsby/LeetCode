//
// Created by 许雷 on 2018/11/4.
//

//933
class RecentCounter {
public:
    RecentCounter() {

    }
    int count = 0;
    int input[10000+1] = {0};


    int ping(int t) {
        int res = 0;
        count++;
        input[count] = t;
        for(int i = count;i>=1;--i){
            if(input[i]>=t-3000 && input[i]<=t){
                ++res;
            }else{
                break;
            }
        }
        return res;
    }
};