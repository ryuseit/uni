#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>

#define f 96000
#define time 0.1

int main(int argc, char **argv){

  FILE *p_IN,*p_OUT;
  struct stat buf;
  int i,j;
  int size_L,size_R;
  double sum_L,sum_R;
  double SL,SR;
  
  //両耳の信号入力(L信号)
  p_IN = fopen(argv[1],"rb");
  if(p_IN == NULL){
      printf("Input error L\n");
      return 0;
    }
  stat(argv[1],&buf);
  size_L = buf.st_size / sizeof(double);
  double *InL = (double *)malloc(sizeof(double) * size_L);
  fread(InL,sizeof(double),size_L,p_IN);
  fclose(p_IN);

  int cal_size = size_L;

  //両耳の信号入力(R信号)
  p_IN = fopen(argv[2],"rb");
  if(p_IN == NULL){
      printf("Input error R\n");
      return 0;
    }
  stat(argv[2],&buf);
  size_R = buf.st_size / sizeof(double);
  double *InR = (double *)malloc(sizeof(double) * size_R);
  fread(InR,sizeof(double),size_R,p_IN);
  fclose(p_IN);

  p_OUT = fopen(argv[3],"wb");
    if(p_OUT == NULL){
      printf("Output Error\n");
      return 0;
    }

  double ave_L=0.0;
  double ave_R=0.0;

  for( i=0 ; i<f*time+200 ; i++){
    ave_L += pow(InL[i], 2);
    ave_R += pow(InR[i], 2);
  }

  double ILD;

  ILD = 10*log10(ave_L/ave_R);
  printf("ave_L = %lf, ave_R = %lf\n",ave_L,ave_R);
  printf("%lf\n",ILD);
  fprintf(p_OUT,"%lf\n",ILD);

  fclose(p_OUT);
  free(InL);
  free(InR);
  
}//main
