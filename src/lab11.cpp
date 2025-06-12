#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;


int main ()
{
  int i, n;
float X[n], Y[n], X1[n], Y1[n], Y2[n], X2[n];
cout<< "Vvedite n\n";
cin>> n;
cout<< "Vvedite massiv X\n";
 for (i=0; i<n; i++)
 {
     cin>>X[i];
     X1[i]=X[i];
     X2[i]=X[i];
     
     }
     
 cout<< "Vvedite massiv Y\n";
 for (i=0; i<n; i++)
 {
     cin>>Y[i];
     Y1[i]=Y[i];
     Y2[i]=Y[i];
     }
 
     for (i=0; i<n; i++)
	 {
		  
     if (X[i]<Y[i])
{ 
     X1[i]=Y1[i];
    Y2[i]=X2[i];
     }
 }

          
      cout << "Massiv X \n";
     for (i=0; i<n; i++)
      cout<< X1[i]<< ' ';
    
     cout << "\nMassiv Y \n";
     for (i=0; i<n; i++)
      cout<< Y2[i]<< ' ';
      
      getch();
return 0;
}  
