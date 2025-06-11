#include <stdio.h>
 #include <math.h>                   
#include <conio.h>
int main () 
{
 float a, b, c, x, max, min;
printf ("Vvedite a,b,c:\n");
scanf ("%f%f%f",&a,&b,&c);
min = b;
if (c<min);
        min=c;
if (a>min)
        max=a;
else
        max=min;
x=max; 
printf ("\nx=%f",x);
getch (); 
return 0;
}
