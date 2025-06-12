#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#define n 5
#define m 3

using namespace std;
void vvod(float E[n])
{
	for(int i=0;i<n;i++)
	{ 
	cin>>E[i];
	}	
	cout<<("\n");
}
 float  Fl(int k, float x)
{
      if (k==0) 
         return x;
      if (k==1) 
         return 1;
    if (k==2)
         return  3*pow(x,2)-1;
          else return 0;
} 

void koeffA(float A[(m)][(m)],float X[n])
{
     int i,l,k;   
          for (k=0; k<m; k++)
	{    
		for( l=0; l<m; l++)
		{
			A[k][l]=0;	
			for( i=0;i<n ;i++)
			{				
				A[k][l]=A[k][l]+Fl(k,X[i])*Fl(l,X[i]);				
			}	
		}
    }	
}

void koeffB(float X[n],float Y[n],float B[(m)])
{
     int k,i;
	for (k=0; k<m; k++)
	{
            B[k]=0;
	        for( i=0; i<n; i++)
            {
	         B[k]=B[k]+Y[i]*Fl(k,X[i]);
            }
      }
}
int schod(float A[m][m])
{
	int Flag,i,j,Key;
	float Ad,Sd;
	Flag=0;
	for (i = 0;i <=(m-1);i++)
	{
		Ad=fabs(A[i][i]);
		Sd=0;
		for (j = 0;j <=(m-1);j++)
			if(j!=i)
			Sd+=fabs(A[i][j]);
		if(Ad>Sd)
		Flag=1;
	}
	if (Flag==1)
	Key=0;
	else
	Key=1;
	return Key;
}


void iterazia(float A[m][m],float B[m],float C[m])
{	int Key;
	float eps,test,sum,p[m];
cout<<"Vvedide eps \n";
	cin>>eps;
	Key=schod(A);
	if(Key==1)
	{
		cout<<("Pr rashoditsa\n");
		abort();
	}
	else
	{
		for(int i=0;i<m;i++)
		{
			C[i]=B[i];
		}
		do
		{
			test=0;
			for(int i=0;i<m;i++)
			{
				sum=0;
				for(int j=0;j<m;j++)
				
					if(j!=i)
						sum+=A[i][j]*C[j];	
				p[i]=(B[i]-sum)/A[i][i];
				test+=fabs(p[i]-C[i]);
				for(int i=0;i<m;i++)
					C[i]=p[i];
					
			}
		}
		while (test>= eps);
	}
}

float approcs (float C[m],float Yl[n],float D[n],float X[n],float Y[n])
{
	float Kr;
	int k, i;
	Kr=0;
     k=0;
	for( i=0; i<n; i++)
	{
		Yl[i]=C[0]*Fl(k,X[i])+C[1]*Fl((k+1),X[i])+C[2]*Fl((k+2),X[i]);
		D[i]=fabs(Y[i]-Yl[i]);
		Kr=Kr+pow(D[i],2);		
	}
	return Kr;
}

void krappr(float Y[m],float Yl[n],float D[n],float *Dmax,int *IM)
{	
	int i;
	*Dmax=D[0];
	*IM=0;
	for(i=1; i<(n-1); i++)
	{
		if(fabs(D[i])>fabs(*Dmax))
		{
			*Dmax=(D[i]);
			*IM=i;	
		}
	}
}
void vyvod(float E[n])
{
	for(int i=0;i<n;i++)
	{ 
	 printf("%.3f ",E[i]);
	}	
	printf("\n");	
}
int main()
{
float X[n],Y[n], A[m][m],B[m],C[m],Yl[n],D[n],Dmax,Kr;
	int IM, i, j, k;	
	cout<<("vvedite X\n");
	vvod(X);
	cout<<("vvedite Y\n");
	vvod(Y);
	koeffA(A,X);	
	koeffB(X,Y,B);
	  cout<<" matrica   A\n";
   
      for (i=0;i<m;i++)
   {
        for ( j=0;j<m;j++)
       cout<<" "<<A[i][j];
    cout<<"\n";
   }  

      for (i=0; i<m; i++)
      {
        B[i]=0;
        for (k=0;k<n;k++)
        B[i]= B[i]+Fl(i,X[k])*Y[k];
        }
     cout<<"massiv  B\n";
      for (i=0;i<m;i++)
        
          cout<<" "<<B[i];
     cout<<"\n";
	iterazia(A,B,C);

	cout<<"Znachenie C: \n";
		for (i=0;i<m;i++)   
        {
	cout<<"   "<<C[i];
	cout<<"\n";   
     }
	
	Kr=approcs(C,Yl,D,X,Y);	
	krappr(Y,Yl,D,&Dmax,&IM);
    cout<<"Znachenie appr f(x):\n";
    	vyvod(Yl);
	cout<<"Znacheniya otkloneniy: \n";
    vyvod(D);
	cout<<"Max pri = "<<Dmax<<"\n"; 
    cout<<"pri X= "<<X[IM]<<"\n";
	cout<<"Znachenie kriteriya= "<<Kr<<"\n";	
	getch ();
	return 0;
}
