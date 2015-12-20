#include <stdio.h>
double pi_leibniz (int n);
double pi_bpp (int n);
double pi_leibniz (int n)
{
double num=1;
double sum=0;
//calculates the leibniz series
for (int i=0;i<=n;i++){
        sum+=num/(2*i+1);
        num*=-1;
        }
double pi=4*sum;
return pi;

}
double pi_bpp (int n)
{
double lead=1.;
double sum=0.;
//calculates the Bailey-Borwein-Plouffe series
for (int i=0;i<=n;i++)
{
        sum+=lead*((4./(8.*i+1.))-(2./(8.*i+4.))-(1./(8.*i+5.))-(1./(8.*i+6.)));
        lead*=1./16.;
}
return sum;

}

