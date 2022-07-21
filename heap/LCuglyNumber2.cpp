class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue <long long,vector <long long>,greater <long long>> Q;
        Q.push(1);
        long long tp = 1;
        while(n--){
            tp = Q.top();
            while(!Q.empty()&&Q.top()==tp){
                Q.pop();
            }
            Q.push(tp*2);
            Q.push(tp*3);
            Q.push(tp*5);
        }
        return tp;
    }
};