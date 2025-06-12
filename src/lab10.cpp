#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
long double fact(int N)
{
    if(N < 0) 
        return 0; 
    if (N == 0) 
        return 1; 
    else 
        return N * fact(N - 1); 
}


float f1 ( int m)
{
         int i;
    setlocale(0,"");
         float A,B,C,S,x;
       S= 0;
        
for (i=1; i<=m; i++)
{

x=-1+0.2*i;
A= x*x+1;
B = fact(i-1);
C = log10(A/B);
S = S + C;
}
return S;
}

  float f2 (int m)  
 {  
  int i;
 setlocale(0,"");
 float A,B,C,S,x;
    S= 0; 
	i=1;
while (i<=m)
{ 
x=-1+0.2*i;
A= x*x+1;
B = fact(i-1);
C = log10(A/B);
S = S + C;
i++;
}
return S;  
}

float f3 ( int m)
 {  
  int i;
 setlocale(0,"");
 float A,B,C,S,x;
    S= 0; 
	i=1;
do
{ 
x=-1+0.2*i;
A= x*x+1;
B = fact(i-1);
C = log10(A/B);
S = S + C;
i++;
}
while (i<=m);
return S;  
}

int main ()
{

    int m;
         cout <<"Vvedite m:\n";
         cin>> m;
         
         
     cout<<"Summa (cikl for)="<< f1(m)<<"\n";
	       
	  cout<<"Summa (cikl while)="<< f2(m)<<"\n";
	  
	  cout<<"Summa (cikl while ... do)="<< f3(m)<<"\n";
	  
getch();
return 0;
}

