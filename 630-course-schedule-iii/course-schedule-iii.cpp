class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        sort(courses.begin(),courses.end(), [](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        priority_queue<int>pq;
        int time=0;
        for(auto &c:courses){
            int d=c[0];
            int l=c[1];
            time+=d;
            pq.push(d);
            if(time>l){
                time-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};