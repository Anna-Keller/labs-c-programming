#include <stdio.h>
#include <conio.h>
#include <math.h>
#define n 5
#define m 4

int func (float Z[n][m])
{
int IM, i, j;
float maxZ;
maxZ = Z[0][0];
IM = 0;
for (i=0; i<n; i++)
 for (j=0; j<m; j++)
      if (Z[i][j]>maxZ)
{
	maxZ=Z[i][j];
	IM=i;
}
return IM;
}

void pro (float E[m],float E1[m])
{
     int i;
    float R;
for (i=0; i<m; i++)
{
E1[i]=E[i];
}
for (i=0; i<m/2; i++)
{
R = E1[2*i];
E1[2*i] = E1[2*i+1];
E1[2*i+1]=R;
}
}


int main ()
{
	float A[n][m], B[m], A1[m], A2[m], B1[m], maxA, R;
	int i,j,IM;
	printf ("vvedite A(5x4): \n");
	for (i=0; i<n; i++)
{
    for (j=0; j<m; j++)
    {
    	scanf ("%f", &A[i][j]);
	}
}
  for (i=0; i<m; i++)
  {
B[i]=sin(i) + cos(i);
B1[i]=B[i];
}
printf ("massiv B: \n");
   for(i=0; i<m; i++)
printf ("%f ", B[i]);
printf ("\n");

IM=func(A);
printf ("IM=%i \n",IM+1); 

printf ("massiv A1: \n");
    for (j=0; j<m; j++)
    {
A1[j]=A[IM][j];
printf("%f ", A1[j]);
A2[j]= A1[j];
}

printf ("\n massiv A2: \n");
pro(A1,A2);
for (i=0; i<m ;i++)
printf("%f ", A2[i]);

printf ("\n massiv B2: \n");
pro(B,B1);
for (i=0; i<m ;i++)
printf("%f ", B1[i]);

 getch();
 return 0;
 }



