#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    double u,v,w,W,U,V,e1,e2,e3,area;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&W,&V,&u,&U,&v,&w);
        e1=v*v+w*w-U*U;
        e2=w*w+u*u-V*V;
        e3=u*u+v*v-W*W;
        area=4*u*u*v*v*w*w-u*u*e1*e1-v*v*e2*e2-w*w*e3*e3+e1*e2*e3;
        area=sqrt(area);
        area/=12;
        printf("%.4lf\n",area);
    }
    return 0;
}
