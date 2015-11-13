#include<stdio.h>
#include<conio.h>
int d,m,y,nd,nm,ny,ndays;
int main( )	{

	printf("enter the date,month,year");
	scanf("%d%d%d",&d,&m,&y);
	ndays=m-1;
	if(m==2) {
		if(y%100==0) {
			if(y%400==0) {
				ndays=29;
				}
			else if(y%4==0) {
		ndays=29;
			}
		nd=nd+1;
		nm=m;
		ny=y;
		if(nd>ndays) {
nd=1;
nm++;
}
if(nm>12)
{
nm=1;
ny++;
}
printf("Given date is
%d:%d:%dn",d,m,y);
printf("next days date is
%d:%d:%d",nd,nm,ny);
getch( );
}
