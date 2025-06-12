#include <conio.h>
#include <math.h>
#include <iostream>

using namespace std;
int main ()
{
float x,y,a,S;
 a=1;
 while(a==1)
{ 
 cout <<"Vvedite x" <<"\n" ;
 cin >>x ;  
 cout <<"Vvedite y" <<"\n" ;
 cin >>y ;
 
if ( (x*x)+(y*y)>1 &&  ((x+1)*(x+1))+((y-1)*(y-1))<1 )

{   cout << "oblast' M1"<<"\n";
	cout << "SM1=" << 1+M_PI_2 <<"\n\n";
}

else if (x>1 && y>x-1 && y<2 && x<2)
{
	cout << "oblast' M2"<<"\n";
	cout << "SM2="<<3./2<<"\n\n";
}

else if (y<0 && y>x+1 && x>-2)
{
	cout << "oblast' M3"<<"\n";
	cout << "SM3=" <<1./2<<"\n\n";
}

else if ((x*x)+(y*y)<1 && y<0 && y>x-1)
{
	cout << "oblast' M4"<<"\n";
	cout << "SM4="<<M_PI_4+1./2<<"\n\n";
}

else if (y<x-1 && (x*x)+(y*y)>1 && y>-2)
{
	cout << "oblast' M5"<<"\n";
	cout << "SM5="<<2-M_PI_4<<"\n\n";
}
else 
cout << "ne prinadlezhit M1, M2, M3, M4, M5"<<"\n";
cout  <<"prodolzhit' ?" <<"\n" <<"1 - da 0 - net" <<"\n";
cin>>a;
 }
getch ();
return 0;
}
