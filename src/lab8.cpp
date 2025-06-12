#include <string.h>
#include <iostream>
#include <conio.h>
#define NFIO 15
#define NS 7
using namespace std;
struct Date
{
       int Day, Month, Year;
       }
       ;
       struct stud
       {
              char FIO [NFIO];
              char Pol, Obr, Adress, Stip;
              Date DateR;
              int Ocen [5];
              int KB;
              };
              
              
              
              
              void otbor (stud Z[NS], stud Z1[NS])
              {
                  int i, j;
                   stud R;
                  for (i=0; i<NS; i++)
                  Z1[i]=Z[i];
                  for (j=1;j<NS;j++)
                {
                  for (i=NS-1; i>=j; i--)
                  {
			
                  if (Z1[i].DateR.Year < Z1[i-1].DateR.Year)
                 {
                   R = Z1[i-1];
   	             Z1[i-1]= Z1[i];
    	         Z1[i]= R;
              }
    	
    	      else
    	      
                               if (Z1[i].DateR.Year==Z1[i-1].DateR.Year)
                  
                  if (Z1[i].DateR.Month < Z1[i-1].DateR.Month)
                {
                  R= Z1[i-1];
   	             Z1[i-1]= Z1[i];
    	         Z1[i]= R;
              }
       
    	     else
    	     
      if (Z1[i].DateR.Month==Z1[i-1].DateR.Month)
                  
                if (Z1[i].DateR.Day < Z1[i-1].DateR.Day)
              {
                  R= Z1[i-1];
   	             Z1[i-1]= Z1[i];
    	         Z1[i]= R;
                  }
        
        
        }
        }
        }        
                  

int main ()
{
    	int i, j, n;
    stud Group [NS], Group1[NS];
    cout<< "Vvedite spisok v vide:\n";
    cout<<"Ivanov_I.I.___ mkpy 12 10 1999 5 5 5 5 5 200 \n\n";
    for (i=0; i< NS; i++)
    {
    	cin >> Group[i].FIO >> Group[i].Pol >> Group[i].Obr >> Group[i].Adress >> Group[i].Stip >> Group[i].DateR.Day >> Group[i].DateR.Month >> Group[i].DateR.Year;
		
    for (j=0; j<5;j++)
    cin>>Group[i].Ocen[j];
    cin>>Group[i].KB;
}
otbor (Group,Group1);
cout<<"spisok otobr stud:\n";
for(i=0;i<NS;i++)
{
cout <<Group1 [i].FIO<<" "<<Group1[i].Pol<<" "<<Group1[i].Obr<<" "<<Group1[i].Adress<<" "<<Group1[i].Stip
<<" "<<Group1[i].DateR.Day<<" "<<Group1[i].DateR.Month<<" "<<Group1[i].DateR.Year<<" ";
	
for(j=0;j<5;j++)

cout<<Group1[i].Ocen[j]<<" ";
cout<<Group1[i].KB<<"\n";
}
getch();
return 0;
}
