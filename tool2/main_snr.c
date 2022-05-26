/**************************
main_snr.c

Written by M.Nakayama

Last modified at 2002.06.17
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "common.h"

void usage(void);

int main(int argc, char **argv)
{
  extern char *optarg;
  extern int  optind;
  int         opt;
  int         l_flag  = DOWN;
  int         i1_flag = DOWN;
  int         i2_flag = DOWN;

  FILE   *fpi1;  /* input sd file                 */
  FILE   *fpi2;  /* input sd file                 */
  FILE   *fpo;   /* output file                   */
  double tmpd;

  int    i;
  int    l;
  int    i1len;
  int    i2len;
  double save;
  double nave;
  double ssd;
  double nsd;

  fpo = stdout;
  while ((opt = getopt(argc, argv, "l:1:2:o:H")) != EOF) {
    switch (opt) {
    case 'l':
      l = atoi(optarg);
      l_flag = UP;
      break;
    case '1':
      fpi1 = FopenRead(optarg);
      i1_flag = UP;
      break;
    case '2':
      fpi2 = FopenRead(optarg);
      i2_flag = UP;
      break;
    case 'o':
      fpo = FopenWrite(optarg);
      break;
    case 'H':
      usage();
      exit(-1);
    default:
      usage();
      exit(-1);
    }
  }
  if (l_flag == DOWN  || i1_flag  == DOWN || i2_flag == DOWN) {
    usage();
    exit(-1);
  }

  /* read input speech signal */
  fseek(fpi1, 0, SEEK_END);
  i1len = ftell(fpi1) / (sizeof(double));
  fseek(fpi1, 0, SEEK_SET);
  if (i1len < l) {
    fprintf(stderr, "i1len < l, %d < %d\n",i1len,l);
    usage();
    exit(-1);
  }
  save = 0.0;  ssd  = 0.0;
  for (i = 0; i < l; i++) {
    fread(&tmpd, sizeof(double), 1, fpi1);
    save += tmpd;
    ssd  += tmpd * tmpd;
  }
  save /= l;
  ssd  /= l;
  ssd   = sqrt(ssd - save * save);


  /* read input noise signal */
  fseek(fpi2, 0, SEEK_END);
  i2len = ftell(fpi2) / (sizeof(double));
  fseek(fpi2, 0, SEEK_SET);
  if (i2len < l) {
    fprintf(stderr, "i2len < l, %d < %d\n",i2len,l);
    usage();
    exit(-1);
  }
  nave = 0.0;  nsd  = 0.0;
  for (i = 0; i < l; i++) {
    fread(&tmpd, sizeof(double), 1, fpi2);
    nave += tmpd;
    nsd  += tmpd * tmpd;
  }
  nave /= l;
  nsd  /= l;
  nsd   = sqrt(nsd - nave * nave);

/*  偏差の比 = obsd/ocsd をプロット */
  fprintf(fpo,"%lf\n",20*log10(ssd/nsd));
  fprintf(stderr,"ssd=%lf, nsd=%lf, SNR=%lf\n",ssd,nsd,20*log10(ssd/nsd));

  fclose(fpi1);
  fclose(fpi2);
  fclose(fpo);
}

void usage(void)
{
  fprintf(stderr, "Usage : snr [l:1:2:o:H]\n");
  fprintf(stderr, "      -l data length (atoi)\n");
  fprintf(stderr, "      -1 input speech filename (double)\n");
  fprintf(stderr, "      -2 input noise filename (double)\n");
  fprintf(stderr, "      -o output snr filename (default is stdout)\n");
  fprintf(stderr, "      -H show this message\n");
}
