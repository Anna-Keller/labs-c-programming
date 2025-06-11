#include <stdio.h>
#include <math.h>
#include <conio.h>
int main () 
{
 float a, b, c, x, max, min, p0, p, h, ak, pr;
 int i, k, m, n;
printf ("Vvedite a,b,c,p0,h,m,n:\n");
scanf ("%f%f%f%f%f%i%i",&a,&b,&c,&p0,&h,&m,&n);
min = b;
if (c<min);
        min=c;
if (a>min)
        max=a;
else
        max=min;
x=max; 
printf ("x=%f\n",x);
for (i=1; i<=m;i++)
{
	pr=1;
	p=p0+(i-1)*h;
	ak=x;
	if(ak>0)
	     pr=ak;
    printf("a1: %f \n",ak);
    for (k=2; k<=n; k++)
    {
    	ak=-ak*x*tan(p)/(k+1);
		printf ("a%i=%f\n",k,ak);
		if (ak>0)
		      pr=ak*pr;
	}
	printf ("Proizvedenie %f, p= %f\n \n",pr,p);
}
getch (); 
return 0;
}
