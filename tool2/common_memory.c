/**************************
common_memory.c

Written by Y.DENDA

Last Modefied at 2004.07.07
**************************/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

/*------------------------------*/
char *MallocChar(int n)
{
  char *c;

  if ((c = (char *) malloc(sizeof(char) * n)) == NULL) {
    fprintf(stderr, "Can't allocate memory.\n");
    exit(-1);
  }
  return c;
}

/*------------------------------*/
char **MallocChar2(int n, int m)
{
  char **c;
  int i;

  if ((c = (char **) malloc(sizeof(char *) * n)) == NULL) {
    fprintf(stderr, "Can't allocate memory.\n");
    exit(-1);
  }
  for (i = 0; i < n; i++) {
    if ((c[i] = (char *) malloc(sizeof(char) * m)) == NULL) {
      fprintf(stderr, "Can't allocate memory.\n");
      exit(-1);
    }
  }
  return c;
}

/*------------------------------*/
short *MallocShort(int n)
{
  short *s;

  if ((s = (short *) malloc(sizeof(short) * n)) == NULL) {
    fprintf(stderr, "Can't allocate memory.\n");
    exit(-1);
  }
  return s;
}

/*------------------------------*/
short* CallocShort(int n)
{
  short* s;

  if((s = (short *)calloc(n, sizeof(short))) == NULL){
    ERROR("Can't allocate memory.\n");
    exit(-1);
  }
  
  return s;
}

/*------------------------------*/
short **MallocShort2(int n, int m)
{
  short **s;
  int i;

  if ((s = (short **) malloc(sizeof(short *) * n)) == NULL) {
    fprintf(stderr, "Can't allocate memory.\n");
    exit(-1);
  }
  for (i = 0; i < n; i++) {
    if ((s[i] = (short *) malloc(sizeof(short) * m)) == NULL) {
      fprintf(stderr, "Can't allocate memory.\n");
      exit(-1);
    }
  }
  return s;
}

short** CallocShort2(int n, int m)
{
  short** s;
  int i;
  
  if((s = (short **)calloc(n, sizeof(short *))) == NULL){
    ERROR("Can't allocate memory.\n");
    exit(-1);
  }
  
  for(i = 0; i < n; i++)
    if((s[i] = (short *)malloc(sizeof(short) * m)) == NULL){
      ERROR("Can't allocate memory.\n");
      exit(-1);
    }
  
  return s;
}

/*------------------------------*/
int *MallocInt(int n)
{
  int *in;

  if ((in = (int *) malloc(sizeof(int) * n)) == NULL) {
    fprintf(stderr, "Can't allocate memory.\n");
    exit(-1);
  }
  return in;
}

/*------------------------------*/
int **MallocInt2(int n, int m)
{
  int **in;
  int i;

  if ((in = (int **) malloc(sizeof(int *) * n)) == NULL) {
    fprintf(stderr, "Can't allocate memory.\n");
    exit(-1);
  }
  for (i = 0; i < n; i++) {
    if ((in[i] = (int *) malloc(sizeof(int) * m)) == NULL) {
      fprintf(stderr, "Can't allocate memory.\n");
      exit(-1);
    }
  }
  return in;
}

/*------------------------------*/
float *MallocFloat(int n)
{
  float *f;

  if ((f = (float *) malloc(sizeof(float) * n)) == NULL) {
    fprintf(stderr, "Can't allocate memory.\n");
    exit(-1);
  }
  return f;
}

/*------------------------------*/
float **MallocFloat2(int n, int m)
{
  float **f;
  int   i;

  if ((f = (float **) malloc(sizeof(float *) * n)) == NULL) {
    fprintf(stderr, "Can't allocate memory.\n");
    exit(-1);
  }
  for (i = 0; i < n; i++) {
    if ((f[i] = (float *) malloc(sizeof(float) * m)) == NULL) {
      fprintf(stderr, "Can't allocate memory.\n");
      exit(-1);
    }
  }
  return f;
}

/*------------------------------*/
double *MallocDouble(int n)
{
  double *d;

  if ((d = (double *) malloc(sizeof(double) * n)) == NULL) {
    fprintf(stderr, "Can't allocate memory.\n");
    exit(-1);
  }
  return d;
}

/*------------------------------*/
double* CallocDouble(int n)
{
  double* d;

  if((d = (double *)calloc(n, sizeof(double))) == NULL){
    ERROR("Can't allocate memory.\n");
    exit(-1);
  }
  
  return d;
}

/*------------------------------*/
double **MallocDouble2(int n, int m)
{
  double **d;
  int   i;

  if ((d = (double **) malloc(sizeof(double *) * n)) == NULL) {
    fprintf(stderr, "Can't allocate memory.\n");
    exit(-1);
  }
  for (i = 0; i < n; i++) {
    if ((d[i] = (double *) malloc(sizeof(double) * m)) == NULL) {
      fprintf(stderr, "Can't allocate memory.\n");
      exit(-1);
    }
  }
  return d;
}

/*------------------------------*/
double** CallocDouble2(int n, int m)
{
  double** d;
  int   i;

  if((d = (double **)calloc(n, sizeof(double *))) == NULL){
    ERROR("Can't allocate memory.\n");
    exit(-1);
  }
  
  for(i = 0; i < n; i++)
    if((d[i] = (double *)calloc(m, sizeof(double))) == NULL){
      ERROR("Can't allocate memory.\n");
      exit(-1);
    }
  
  return d;
}

/*------------------------------*/
COMPLEX *MallocComplex(int n)
{
  COMPLEX *cx;

  if ((cx = (COMPLEX *) malloc(sizeof(COMPLEX) * n)) == NULL) {
    fprintf(stderr, "Can't allocate memory.\n");
    exit(-1);
  }
  return cx;
}

/*------------------------------*/
COMPLEX **MallocComplex2(int n, int m)
{
  COMPLEX **cx;
  int     i;

  if ((cx = (COMPLEX **) malloc(sizeof(COMPLEX *) * n)) == NULL) {
    fprintf(stderr, "Can't allocate memory.\n");
    exit(-1);
  }
  for (i = 0; i < n; i++) {
    if ((cx[i] = (COMPLEX *) malloc(sizeof(COMPLEX) * m)) == NULL) {
      fprintf(stderr, "Can't allocate memory.\n");
      exit(-1);
    }
  }
  return cx;
}

/*------------------------------*/
void FreeChar2(char **c, int n)
{
  int i;

  for (i = 0; i < n; i++) {
    free(c[i]);
  }
  free(c);
}

/*------------------------------*/
void FreeShort2(short **s, int n)
{
  int i;

  for (i = 0; i < n; i++) {
    free(s[i]);
  }
  free(s);
}

/*------------------------------*/
void FreeInt2(int **in, int n)
{
  int i;

  for (i = 0; i < n; i++) {
    free(in[i]);
  }
  free(in);
}

/*------------------------------*/
void FreeFloat2(float **f, int n)
{
  int i;

  for (i = 0; i < n; i++) {
    free(f[i]);
  }
  free(f);
}

/*------------------------------*/
void FreeDouble2(double **d, int n)
{
  int i;

  for (i = 0; i < n; i++) {
    free(d[i]);
  }
  free(d);
}

/*------------------------------*/
void FreeComplex2(COMPLEX **cx, int n)
{
  int i;

  for (i = 0; i < n; i++) {
    free(cx[i]);
  }
  free(cx);
}
