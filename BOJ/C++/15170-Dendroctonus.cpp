#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
#define y1 khjk
#define y2 kjkj
struct point
{
	double x,y;
	point(){}
	point(double _x,double _y):x(_x),y(_y)
	{}
	point operator -(const point &b) const
	{
		return point(x-b.x,y-b.y);
	}
	double operator *(const point &b) const
	{
		return x*b.x+y*b.y;
	}
	double operator ^(const point &b) const
	{
		return x*b.y-y*b.x;
	}
};
struct line
{
	point s,e;
	double a,b,c;
	line()
	{
 
	}
	line (point _s,point _e):s(_s),e(_e)
	{
		a=e.y-s.y;
		b=s.x-e.x;
		c=e.x*s.y-s.x*e.y;
	}
};
double xmult(point p0,point p1,point p2)
{
	return (p1-p0)^(p2-p0);
}
const double eps = 1e-1;
double sgn(double x)
{
	if(fabs(x) < eps)return 0;
	if(x < 0)return -1;
	else return 1;
}
bool inter(line l1,line l2)
{
	return
		max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
		max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
		max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
		max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
		sgn((l2.s-l1.s)^(l1.e-l1.s))*sgn((l2.e-l1.s)^(l1.e-l1.s)) <= 0 &&
		sgn((l1.s-l2.s)^(l2.e-l2.s))*sgn((l1.e-l2.s)^(l2.e-l2.s)) <= 0;
}
bool samepoint(point p1,point p2)
{
	if (fabs(p1.x-p2.x)>eps) return false;
	if (fabs(p1.y-p2.y)>eps) return false;
	return true;
}
double cross(point sp,point ep,point op)
{
	return (sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x);
}
double area(point p1,point p2,point p3)
{
	return fabs(cross(p1,p2,p3))/2;
}
point intersection(line u,line v)
{
	point p;
	p.x=(cross(v.e,u.e,u.s)*v.s.x-cross(v.s,u.e,u.s)*v.e.x)/(cross(v.e,u.e,u.s)-cross(v.s,u.e,u.s));
	p.y=(cross(v.e,u.e,u.s)*v.s.y-cross(v.s,u.e,u.s)*v.e.y)/(cross(v.e,u.e,u.s)-cross(v.s,u.e,u.s));
	return p;
}
point interpoint(line l1, line l2)
{
	point tmp;
	if(fabs(l1.b)<eps)
	{
		tmp.x=-l1.c/l1.a;
		tmp.y=(-l2.c-l2.a*tmp.x)/l2.b;
	}
	else
	{
		tmp.x=(l1.c*l2.b-l1.b*l2.c)/(l1.b*l2.a-l2.b*l1.a);
		tmp.y=(-l1.c-l1.a*tmp.x)/l1.b;
	}
	return tmp;
}
double findx(double y,line l)
{
	return (-l.c-l.b*y)/l.a;
}
double findy(double x,line l)
{
	if (fabs(l.b)<eps)
		return -1e250;
	return (-l.c-l.a*x)/l.b;
}
point tcircle(point pt1, point pt2, point pt3, double &radius)
{
	double x1 = pt1.x, x2 = pt2.x, x3 = pt3.x;
	double y1 = pt1.y, y2 = pt2.y, y3 = pt3.y;
	double a = x1 - x2;
	double b = y1 - y2;
	double c = x1 - x3;
	double d = y1 - y3;
	double e = ((x1 * x1 - x2 * x2) + (y1 * y1 - y2 * y2)) / 2.0;
	double f = ((x1 * x1 - x3 * x3) + (y1 * y1 - y3 * y3)) / 2.0;
	double det = b * c - a * d;
	if( fabs(det) <eps)
	{
		radius = -1;
		return point(0,0);
	}
 
	double x0 = -(d * e - b * f) / det;
	double y0 = -(a * f - c * e) / det;
	radius = hypot(x1 - x0, y1 - y0);
	return point(x0, y0);
}
int n,cnt1=0,cnt2=0;
point p1[1100],p2[1100];
double dis(point p1,point p2)
{
	return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}
void calc(point P,point Q)
{
	double r=dis(P,Q)/2;
	point p;
	p.x=(P.x+Q.x)/2;
	p.y=(P.y+Q.y)/2;
	bool can=true;
	int l;
	for (l=1;l<=cnt1;l++)
		if ((p1[l].x-p.x)*(p1[l].x-p.x)+(p1[l].y-p.y)*(p1[l].y-p.y)-r*r>eps)
		{
			can=false;
			break;
		}
	if (!can) return;
	for (l=1;l<=cnt2;l++)
		if (r*r-(p2[l].x-p.x)*(p2[l].x-p.x)-(p2[l].y-p.y)*(p2[l].y-p.y)>eps)
		{
			can=false;
			break;
		}
	if (can)
	{
		puts("No");
		exit(0);
	}
 
}
bool onSegment(point Pi , point Pj , point Q)
{
	if((Q.x - Pi.x) * (Pj.y - Pi.y) == (Pj.x - Pi.x) * (Q.y - Pi.y)
			&& min(Pi.x , Pj.x) <= Q.x && Q.x <= max(Pi.x , Pj.x)
			&& min(Pi.y , Pj.y) <= Q.y && Q.y <= max(Pi.y , Pj.y))
		return true;
	else
		return false;
}
int main()
{
	scanf("%d",&n);
	int i,j,k,l;
	for (i=1;i<=n;i++)
	{
		point p;
		scanf("%lf%lf",&p.x,&p.y);
		char c[3];
		scanf("%s",c);
		if (c[0]=='I')
			p1[++cnt1]=p;
		else p2[++cnt2]=p;
	}
	if (cnt1<=1)
	{
		puts("No");
		return 0;
	}
	else if (cnt1==2)
	{
		calc(p1[1],p1[2]);
		bool can=true;
		for (i=1;i<=cnt2;i++)
			if (onSegment(p1[1],p1[2],p2[i]))
			{
				can=false;
				break;
			}
		if (can)
			puts("No");
		else puts("Yes");
		return 0;
	}
	int cnt3=cnt1;
 
	cnt3++;
	p1[cnt3].x=10000;
	p1[cnt3].y=10000;
	cnt3++;
	p1[cnt3].x=-10000;
	p1[cnt3].y=10000;
	cnt3++;
	p1[cnt3].x=10000;
	p1[cnt3].y=-10000;
	cnt3++;
	p1[cnt3].x=-10000;
	p1[cnt3].y=-10000;
	cnt3++;
	p1[cnt3].x=0;
	p1[cnt3].y=-10000;
	cnt3++;
	p1[cnt3].x=0;
	p1[cnt3].y=10000;
	cnt3++;
	p1[cnt3].x=10000;
	p1[cnt3].y=0;
	cnt3++;
	p1[cnt3].x=-10000;
	p1[cnt3].y=-0;
 
	for (i=1;i<=cnt3-2;i++)
		for (j=i+1;j<=cnt3-1;j++)
			for (k=j+1;k<=cnt3;k++)
			{
				double r;
				point p=tcircle(p1[i],p1[j],p1[k],r);
				if (r==-1)
				{
					calc(p1[i],p1[j]);
					calc(p1[i],p1[k]);
					calc(p1[j],p1[k]);
					continue;
				}
				if (r!=-1)
				{
					bool can=true;
					for (l=1;l<=cnt1;l++)
						if ((p1[l].x-p.x)*(p1[l].x-p.x)+(p1[l].y-p.y)*(p1[l].y-p.y)-r*r>eps)
						{
							can=false;
							break;
						}
					if (!can) continue;
					for (l=1;l<=cnt2;l++)
						if (r*r-(p2[l].x-p.x)*(p2[l].x-p.x)-(p2[l].y-p.y)*(p2[l].y-p.y)>eps)
						{
							can=false;
							break;
						}
					if (can)
					{
						puts("No");
						return 0;
					}
				}
 
			}
	puts("Yes");
	return 0;
}