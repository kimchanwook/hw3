#define _XOPEN_SOURCE

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(){

  double Na=6.022*pow(10,23);
  double lambda1, lambda2;
  double Z, A, rho, E, Esc, Ef, alpha, alpha2, sigma, sigma2, phi, aphi, J, dEdS, dEdS2;

  printf("Enter the Value for atomic number\n");
  scanf("%lf",&Z);
  printf("Enter the Value for atomic mass in kg\n");
  scanf("%lf",&A);
  printf("Enter the Value for density of the target in kg/cm^3 \n");
  scanf("%lf",&rho);
  printf("Enter the Value for incoming Beam Energy\n");
  scanf("%lf",&E);

  alpha = 3.4*pow(10,-3) * (pow(Z,0.67))/E;
  sigma = 5.21*pow(10,-21) * (pow(Z,2)/pow(E,2)) * (4*3.14/alpha*(1+alpha)) *  pow((E+511)/(E+1024),2);
  lambda1 = -(A/(Na*rho*sigma)) * log(drand48()+1);

  J = (9.76*Z + 58.5/pow(Z,0.19)) * pow(10,-3);
  dEdS = 78500 * (rho*Z)/(A*E) * log((1.166*E/J)+1);
  Esc = E - dEdS*lambda1;

  alpha2 = 3.4*pow(10,-3) * (pow(Z,0.67))/Esc;
  sigma2 = 5.21*pow(10,-21) * (pow(Z,2)/pow(Esc,2)) * (4*3.14/alpha2*(1+alpha2)) *  pow((Esc+511)/(Esc+1024),2);
  lambda2 = -(A/(Na*rho*sigma2)) * log(drand48()+1);
  dEdS2 = 78500 * (rho*Z)/(A*Esc) * log((1.166*Esc/J)+1);
  Ef = Esc +  dEdS2*lambda2;

  phi = acos(1 - (2*alpha*(drand48()+1)) / (1 + alpha - (drand48()+1)));

  //azimuthal angle
  aphi = 2 * 3.14 * (drand48()+1);

  printf("Value for Scattering positoin along the z-axis = %f \n", lambda1);
  printf("Value for incident beam energy = %f \n", E);
  printf("Value for electron energy at scattering vertex = %f \n", Esc);
  printf("Value for electron energy as it exits the target = %f \n", Ef);
  printf("Value for azimuthal angle = %f \n", aphi);
  printf("Value for scatterng angle from z-axis = %lf \n", phi);

  return 0;
}

