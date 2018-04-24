#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

void gaussiana(double *u, double x_in, double dx, int N);
void evolucion(double *u_new, double *u_old, int n, double delta_x, double delta_t, double c);
void copia(double *u, double *u_old, int n);
void imprime(double *u, double x_in, double dx, int N, double t);

void gaussiana(double *u, double x_in, double dx, int N){
  double x;
  for(int i=0;i<N;i++){
    x = x_in +i*dx;
    u[i] = 1.0*exp(-pow((x-1.0)/0.1,2)*0.5);
  }
}

void evolucion(double *u, double *u_old, int n, double dx, double dt, double D){
  for(int i=1;i<n-1;i++){
    u[i]=(((D*dt)/pow(dx,2))*(u_old[i+1] + u_old[i-1] - 2*u_old[i])) + u_old[i];      
  }
}

void copia(double *u, double *u_old, int n){
  for(int i=0;i<n;i++){
    u[i] = u_old[i];
  }

}

void imprime(double *u, double x_in, double dx, int N, double t){
  double x;  
  for(int i =0;i<N;i++){
    x = x_in + i*dx;
    cout<<t<<" "<<x<<" "<<u[i]<<endl;
  }
  
}

int main(){
  double x_in = 0.0, x_max = 2.0; 
  double dx =0.01, dt=0.01;
  double t = 0.0, T = 0.5;
  int Nx = (x_max - x_in)/dx +1 ;
  double D = 1.0;
  double* u_old,* u;

  u = new double[Nx];
  u_old = new double[Nx];

  gaussiana(u_old,x_in,dx,Nx);
  imprime(u_old,x_in,dx,Nx,t);
  for(int j =0; t>T;j++){
    evolucion(u,u_old,Nx,dx,dt,D);
    copia(u,u_old,Nx);
    t += dt;
    
  }
  imprime(u_old,x_in,dx,Nx,t);
  

  return 0;
}











