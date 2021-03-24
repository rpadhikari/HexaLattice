#include<stdio.h>
#include<math.h>

double sqrt(double);

int main() {
  FILE *fout, *fin1, *fin2;
  double a1[2];
  double a2[2];
//  double a2[0]=-0.5;
//  double a2[1]=0.86602540378443864676;

  int n1=20;
  int n2=20;
  double T1, T2;
  fin1=fopen("a1.dat","r");
  fin2=fopen("a2.dat","r");
  for(int i=0; i<=1; i++) {
    fscanf(fin1,"%lf\n", &a1[i]);
    fscanf(fin2,"%lf\n", &a2[i]);
  }
  fclose(fin1);
  fclose(fin2);
  printf("%lf %lf\n",a1[0], a1[1]);
  printf("%20.15lf %20.15lf\n",a2[0], a2[1]);

  fout=fopen("data.dat","w");
  for(int i=-n1; i<=n2; i++){ 
    for(int j=-n2; j<=n2; j++) {
      T1=i*a1[0]+j*a2[0];
      T2=i*a1[1]+j*a2[1];
      fprintf(fout,"%20.15lf %20.15lf\n",T1, T2);
    }
  }
  fclose(fout);
  return 0;

}
