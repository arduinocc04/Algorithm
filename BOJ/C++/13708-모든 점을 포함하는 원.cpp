#include<stdio.h>
#include<math.h>

#define ROUNDING(x, dig)	( floor((x) * pow(float(10), dig) + 0.5f) / pow(float(10), dig) )
int n;
struct Point{
    double x,y;
    Point():x(0.0),y(0.0){}
}arr[1001];

int main(){
    scanf("%d",&n);
    int x,y;
    for(int i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        arr[i].x=(double)x; arr[i].y=(double)y;
    }

    auto norm = [](double x,double y){
        return x*x+y*y;
    };
    Point avg;
    for(int i=0;i<n;i++){
        avg.x+=arr[i].x; avg.y+=arr[i].y;
    }
    avg.x*=1.0/n; avg.y*=1.0/n;
    double ans=1e10,px=avg.x,py=avg.y,w=0.1;
    int cnt=10000;
    while(cnt--){
        double max_v=0,tmp_v;
        int max_id; 
        for(int i=0;i<n;i++){
            tmp_v=norm(px-arr[i].x,py-arr[i].y);
            if(tmp_v>max_v){
                max_v=tmp_v;
                max_id=i;
            }
        }
        if(max_v<ans)
            ans=max_v;
        px+=(arr[max_id].x-px)*w;
        py+=(arr[max_id].y-py)*w;
        w*=0.995;
    }
    printf("%.3lf %.3lf\n%.3lf", ROUNDING(px, 3), ROUNDING(py, 3), ROUNDING(sqrt(ans),3));
}
