#include<iostream>
#include<algorithm>

using namespace std;
double a,b,c,d;
double mid;
double left; 
double compute(double x){
    return a*x*x*x + b*x*x + c*x + d;
}
void search(double l,double r){
    double left,right;
    mid = l + (r - l) / 2;
    if(r - l <= 0.001){
        printf("%.2lf ",l);
        return ;
    }
    if(compute(mid) == 0) printf("%.2lf ",mid);
    if(compute(r) == 0)printf("%.2lf ",r);
    left = compute(l) * compute(mid);
    right = compute(mid) * compute(r);
    if(left < 0)search(l,mid);
    if(right < 0)search(mid,r);
}

int main(){
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    for(double i=-101;i<=101;i++){
        if(compute(i) * compute(i + 1.0) <= 0)
            search(i,i + 1.0);
    }
    return 0;
}
