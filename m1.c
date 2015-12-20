#include <stdio.h>
#include <math.h>
#include "pi.c"
#include "timer.c"
#include "adjust.c"
void timer_start (void);
double timer_stop (void);
double pi_leibniz (int n);
double pi_bpp (int n);


int main (void)
{
int i=1;
double abserr=0;
double abserr1=0;
//runs the leibniz function to calculate pi until within the accepted error
do
{
	double pi=pi_leibniz(i);
	abserr = fabs (pi-M_PI);
	printf("Leibniz  :%8d  %20.15f  % 20.15f \n", i, pi, abserr);
	i*=2;
}
while (abserr > .000001);
int k=1;
//runs the Bailey-Borwein-Plouffe (bpp) function to calculate pi until within the accepted error
do
{
	double pi=pi_bpp(k);
	abserr1= fabs (pi-M_PI);
	printf("bpp :%8d  %20.15f %20.15f \n",k,pi,abserr);
	k*=2;
}
while (abserr1 > .000001);

double time,tleibniz,tmax=2.,tmin=1.;
int count=1000,l;
//find the time it takes to run the final iteration of the leibniz code
do
{
	timer_start ();
	for (l=0;l<count;l++)
	{
		pi_leibniz(i/2);
	}
	time =timer_stop ();
	tleibniz=time / count;
	printf ("lebniz time:  %10.2f usec   %10.6f sec  %10d\n",tleibniz*1.e6,time,count);
	count = adjust_rep_count (count,time,tmin,tmax);
}
while ((time > tmax) || (time < tmin));
//finds the time it takes to run the final iteration of the Bailey-Borwein-Plouffe code 
double time_bpp,tbpp,tmax_bpp=2.,tmin_bpp=1.;
int count_bpp=1000,p;
do
{
        timer_start ();
        for (p=0;p<count_bpp;p++)
        {
                pi_bpp(k/2);
        }
        time_bpp =timer_stop ();
        tbpp=time_bpp / count_bpp;
        printf ("bpp time:  %10.2f usec   %10.6f sec  %10d\n",tbpp*1.e6,time_bpp,count_bpp);
        count_bpp = adjust_rep_count (count_bpp,time_bpp,tmin_bpp,tmax_bpp);
}
while ((time_bpp > tmax_bpp) || (time_bpp < tmin_bpp));
//prints the leibniz code divided by the Bailey-Borwein-Plouffe code
	printf("%10.6f\n",tleibniz/tbpp);
return 0;
}
