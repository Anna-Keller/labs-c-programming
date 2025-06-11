#include <stdio.h>
#include <conio.h>
#include <math.h>
#define n 5
#define m 4
int main ()
{
float A[n][m], B[m], A1[m], A2[m], B1[m], AIM[m], maxA;
int i,j,IM,R;
printf ("vvedite A(5x4): \n");
for (i=0; i<n; i++)
{
for (j=0; j<m; j++)
{
scanf ("%f", &A[i][j]);
}
}
for (i=0; i<m; i++)
B[i]=sin(i) + cos(i);
for(i=0; i<m; i++)
B1[i]=B[i];
printf ("\n massiv B: \n");
for(i=0; i<m; i++)
printf ("%f ", B[i]);
printf ("\n\n");
maxA = A[0][0];
IM=0;
for (i=0; i<n; i++)
for (j=0; j<m; j++)
if (A[i][j]>maxA)
{
maxA=A[i][j];
IM=i;
}
printf ("IM=%i \n\n",IM+1); 
printf ("massiv A1: \n");
for (j=0; j<m; j++)
{
A1[j]=A[IM][j];
printf("%f ", A1[j]);
A2[j]= A1[j];
}
printf ("\n\n massiv A2: \n");
for (i=0; i<m/2; i++)
{
R=A2[2*i];
A2[2*i] = A2[2*i+1];
A2[2*i+1] = R;
}
for (i=0; i<m ;i++)
{
printf("%f ", A2[i]);
}
printf ("\n\n massiv B1: \n");
for (i=0; i<m/2; i++)
{
R=B1[2*i];
B1[2*i] = B1[2*i+1];
B1[2*i+1] = R;
}
for (i=0; i<m ;i++)
{
printf("%f ", B1[i]);
}
getch();
return 0;
}

