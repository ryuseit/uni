/**************************
main_ircat.c

Written by M.Nakayama

Last modified at 2005.06.04
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "common.h"

void usage(void);

int main(int argc, char **argv)
{
  extern char *optarg;
  extern int  optind;
  int         opt;
  int         f_flag = DOWN;

  FILE   *fpi; /* input file              */
  FILE   *fpo; /* output file             */
  long   ilen; /* length of input  signal */
  long   k;
  double fs;
  double tmpd;

  fpi = stdin;
  fpo = stdout;
  while ((opt = getopt(argc, argv, "f:i:o:H")) != EOF) {
    switch (opt) {
    case 'f':
      fs = atof(optarg);
      f_flag = UP;
      break;
    case 'i':
      fpi = FopenRead(optarg);
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
  if (f_flag == DOWN) {
    usage();
    exit(-1);
  }

  /* read input signal */
  fseek(fpi, 0, SEEK_END);
  ilen = ftell(fpi) / sizeof(double);
  fseek(fpi, 0, SEEK_SET);

  for(k = 0; k < ilen; k++) {
    fread(&tmpd, sizeof(double), 1, fpi);
    fprintf(fpo, "%le %le\n", (double)(k - 100)/fs, tmpd);
  }

  fclose(fpi);
  fclose(fpo);
}

void usage(void)
{
  fprintf(stderr, "Usage : ircat [f:i:o:H]\n");
  fprintf(stderr, "      -f sampling frequency(atof)\n");
  fprintf(stderr, "      -i input filename(default is stdin)\n");
  fprintf(stderr, "         Output data type is double.\n");
  fprintf(stderr, "      -o output filename (default is stdout)\n");
  fprintf(stderr, "         Output data type is ASCII.\n");
  fprintf(stderr, "      -H show this message\n");
}
