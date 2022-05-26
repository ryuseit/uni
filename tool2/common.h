/**************************
common.h

Written by Y.DENDA

Last modified at 2004.07.07
**************************/

#ifndef _COMMON_H
#define _COMMON_H

#define UP   1
#define DOWN 0

typedef int BOOL;
#define TRUE  1
#define FALSE 0

#ifndef SEEK_SET
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#endif

#ifndef PI
#define PI  3.14159265358979
#define TPI 6.28318530717959
#define SPEED (34000.0)
#endif

#ifndef M_PI
#define M_PI (3.14159265358979)
#endif

#define DEG2RAD(x) ((x) / 180.0 * M_PI)

#define pow2(x) ((x) * (x))

#define POW2(x) ((x) * (x))

#define ERROR(s) fprintf(stderr, "%s", s)

typedef struct {
  float re;
  float im;
} COMPLEX;

typedef struct {
  double re;
  double im;
} COMPLEXD;

/*************
common_fft.c
*************/
void initfft(int);
void freefft(void);
void fftsub(COMPLEXD *, int, int, int);

/*************
common_fopen.c
*************/
FILE *FopenRead(char *);
FILE *FopenWrite(char *);
FILE* FopenReadB(char*);
FILE* FopenWriteB(char*);
int   FgetLength(FILE*, size_t);

/************
common_math.c
************/
COMPLEX CAdd(COMPLEX, COMPLEX);
COMPLEX CSub(COMPLEX, COMPLEX);
COMPLEX CMul(COMPLEX, COMPLEX);
COMPLEX CDiv(COMPLEX, COMPLEX);
COMPLEX CConj(COMPLEX);
float   CPow(COMPLEX);
float   CAbs(COMPLEX);

/**************
common_memory.c
**************/
char    *MallocChar(int);
char    **MallocChar2(int, int);
short   *MallocShort(int);
short*  CallocShort(int);
short   **MallocShort2(int, int);
short** CallocShort2(int, int);
int     *MallocInt(int);
int     **MallocInt2(int, int);
float   *MallocFloat(int);
float   **MallocFloat2(int, int);
double  *MallocDouble(int);
double* CallocDouble(int);
double** MallocDouble2(int, int);
double** CallocDouble2(int, int);
COMPLEX *MallocComplex(int);
COMPLEX **MallocComplex2(int, int);
void    FreeChar2(char **, int);
void    FreeShort2(short **, int);
void    FreeInt2(int **, int);
void    FreeFloat2(float **, int);
void    FreeDouble2(double **, int);
void    FreeComplex2(COMPLEX **, int);

/* cal_fai */
void cal_fai(int, COMPLEXD *, COMPLEXD *, COMPLEXD *);
#endif



