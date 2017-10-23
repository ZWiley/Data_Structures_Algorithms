//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
/**
    需要两重循环，第一重循环遍历起始点a，第二重循环遍历剩余点b。
 
    a和b如果不重合，就可以确定一条直线。
 
    对于每个点a，构建 斜率->点数 的map。
 
    (1)b与a重合，以a起始的所有直线点数+1 (用dup统一相加)
 
    (2)b与a不重合，a与b确定的直线点数+1
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int size = points.size();
        if(size == 0)
            return 0;
        else if(size == 1)
            return 1;
             
        int ret = 0;
        for(int i = 0;i<size;i++){
             
            int curmax = 1;
            map<double,int>mp;
            int vcnt = 0; //垂直点
            int dup = 0; //重复点
            for(int j = 0;j<size;j++){
                 
                if(j!=i){
                    double x1 = points[i].x - points[j].x;
                    double y1 = points[i].y - points[j].y;
                    if(x1 == 0 && y1 == 0){   //重复
                        dup++;
                    }else if(x1 == 0){      //垂直
                        if(vcnt == 0)
                            vcnt = 2;
                        else
                            vcnt++;
                        curmax = max(vcnt,curmax);
                    }else{
                        double k = y1/x1;          //斜率
                        if(mp[k] == 0)
                            mp[k] = 2;
                        else
                            mp[k]++;
                        curmax = max(mp[k],curmax);
                    }                   
                }
            }
            ret = max(ret,curmax+dup);           
        }
        return ret;
         
    }
};