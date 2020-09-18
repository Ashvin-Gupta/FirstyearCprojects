#include <stdio.h> 
#include <stdlib.h> 
#include<math.h> 
double damping_factor(double R, double L, double C); 
double heavy_damping(double q0, double i0, double T, double g, double Wn); 
double critical_damping(double T, double Wn, double g, double q0, double i0); 
double light_damping(double Wn, double g, double q0, double i0, double T); 
  
  
  
int main() 
{ 
    double R,L,C,T,q0,i0,Wn, g; 
    printf("What is the value of R: \n"); 
    scanf("%lf", &R); 
    printf("What is the value of L: \n"); 
    scanf("%lf", &L); 
    printf("What is the value of C: \n"); 
    scanf("%lf", &C); 
    printf("How long has the circuit been switched on for? \n"); 
    scanf("%lf", &T); 
    printf("What is the initial charge on the capacitor: \n"); 
    scanf("%lf", &q0); 
    printf("What is the initial current flowing: \n"); 
    scanf("%lf", &i0); 
  
    Wn = 1/sqrt(L*C); 
    g = damping_factor(R,L,C); 
  
    if (g<1){ 
        printf("The charge q on the capacitor is = %lf\n", light_damping(Wn, g, q0,i0,T)); 
    } 
    else if (g=0){ 
        printf("The charge q on the capacitor is = %lf\n", critical_damping(T,Wn,g,q0,i0)); 
    } 
    else if (g>1){ 
        printf("The charge q on the capacitor is = %lf\n", heavy_damping(q0,i0,T,g,Wn)); 
    } 
    else{ 
        return(0); 
    } 
} 
  
double damping_factor(double R, double L, double C) 
{ 
    double gamma; 
    gamma = (R*sqrt(C)/(2.0*sqrt(L))); 
    return(gamma); 
} 
  
  
double heavy_damping(double q0, double i0, double T, double g, double Wn) 
{ 
    double mue_1 = -1*Wn*g + Wn*sqrt(g*g-1); 
    double mue_2 = -1*Wn*g - Wn*sqrt(g*g-1); 
    double A_1 = (i0-q0*mue_2)/(mue_1 - mue_2) ; 
    double A_2 = (q0 - A_1); 
    double q = A_1*exp(mue_1*T) + A_2*exp(mue_2*T); 
    return(q); 
} 
  
double critical_damping(double T, double Wn, double g, double q0, double i0) 
{ 
    double alpha = -1*Wn*g*T; 
    double A_3 = q0; 
    double A_4 = i0; 
    double q = A_3*exp(alpha) + A_4*T*exp(alpha); 
    return(q); 
} 
  
double light_damping(double Wn, double g, double q0, double i0, double T) 
{ 
    double Wd = Wn*sqrt(1-g*g); 
    double theta = atan(-1*Wn*g*q0 - i0/(q0*Wd)); 
    double A_5 = q0/cos(theta); 
    double q = A_5*exp(-1*Wn*g*T)*cos(Wd*T + theta); 
    return(q); 
} 