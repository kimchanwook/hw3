#define _XOPEN_SOURCE

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(){

  double x,y;
  double ncir1=0, ncir2=0, ncir3=0; //counter for points lying in circle
  double n1=100, n2=10000, n3=10000000;
  double r1, r2, r3;
  double pi1, pi2, pi3;
  double pe1,pe2,pe3;

  for(int i=0; i<=n1; i++){
    x=drand48();
    y=drand48();
      if(sqrt((x*x)+(y*y))<=1)ncir1++;}

  for(int i=0; i<=n2; i++){
    x=drand48();
    y=drand48();
      if(sqrt((x*x)+(y*y))<=1 )ncir2++;}

  for(int i=0; i<=n3; i++){
    x=drand48();
    y=drand48();
      if(sqrt((x*x)+(y*y))<=1 )ncir3++;}

  r1 = (ncir1)/(n1);
  r2 = (ncir2)/(n2);
  r3 = (ncir3)/(n3);

//  r1=double(ncir1)/double(n1);
//  r2=double(ncir2)/double(n2);
//  r3=double(ncir3)/double(n3);

  pi1=4*r1;
  pi2=4*r2;
  pi3=4*r3;

  printf("\n");

  printf("ncir1=%f, ncir2=%f, ncir3=%f\n",ncir1,ncir2,ncir3);
  printf("R1=%f, R2=%f, R3=%f\n\n",r1,r2,r3);

  printf("pi value for n=%f = %f\n",n1,pi1);
  printf("pi value for n=%f = %f\n",n2,pi2);
  printf("pi value for n=%f = %f\n\n",n3,pi3);

  pe1=((3.14159265359-pi1)/3.14159265359)*100;
  pe2=-((3.14159265359-pi2)/3.14159265359*100);
  pe3=((3.14159265359-pi3)/3.14159265359)*100;

  printf("Percent error for N=%f = %% %f\n",n1,pe1);
  printf("Percent error for N=%f = %% %f\n",n2,pe2);
  printf("Percent error for N=%f = %% %f\n\n",n3,pe3);

  return 0;
}

