#include <stdio.h>
#include <math.h>
/*Program from homework 4 question 1 find the area of a triangle*/

struct point2d
{
	double x;
	double y;
};

struct triangle
{
	struct point2d a;
	struct point2d b;
	struct point2d c;
};


double distance(struct triangle t);

/*distance of points C-A*/
double distance1 (struct triangle t)
{
	return sqrt((t.c.x-t.a.x)*(t.c.x-t.a.x)+(t.c.y-t.a.y)*(t.c.y-t.a.y));
}

double distance2 (struct triangle t);

/*distance of points A-B*/
double distance2 (struct triangle t)
{
	return sqrt((t.a.x-t.b.x)*(t.a.x-t.b.x)+(t.a.y-t.b.y)*(t.a.y-t.b.y));
}

double distance3 (struct triangle t);

/*distance of points B-C*/
double distance3 (struct triangle t)
{
	return sqrt((t.b.x-t.c.x)*(t.b.x-t.c.x)+(t.b.y-t.c.y)*(t.b.y-t.c.y));
}

double area(struct triangle t);
/*area of a triangle*/
double area(struct triangle t)
{
	return fabs(0.5*( (t.c.x-t.a.x)*(t.b.y-t.a.y) - (t.c.y-t.a.y)*(t.b.x-t.a.x)));
}

int main(void)
{
	struct triangle t1;
	double s, d1, d2, d3, p1, p2, r;



t1.a=(struct point2d) {2., 2.};
t1.b=(struct point2d) {-2.,1.};
t1.c=(struct point2d) {0.,-3.};

s=area(t1);
printf("Area of Triangle: %14.6f\n", s);

d1=distance1(t1);
printf("Distance C-A: %14.6f\n", d1);

d2=distance2(t1);
printf("Distance A-B: %14.6f\n", d2);

d3=distance3(t1);
printf("Distance B-C:  %14.6f\n", d3);

r=(2*area(t1))/(d1+d2+d3);
printf("The radius of a circle in this triangle is:  %14.6f\n",r);

return 0;
}
