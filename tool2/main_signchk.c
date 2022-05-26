/**************************
main_signchk.c

Written by M.Nakayama

Last modified at 2002.11.12
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

  FILE   *fpi;   /* input sd file                 */
  FILE   *fpo;   /* output file                   */

  long   i;
  long   ilen;
  double sign;
  double tmpd;

  fpi = stdout;
  fpo = stdout;
  while ((opt = getopt(argc, argv, "i:o:H")) != EOF) {
    switch (opt) {
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

  /* read input speech signal */
  fseek(fpi, 0, SEEK_END);
  ilen = ftell(fpi) / (sizeof(double));
  fseek(fpi, 0, SEEK_SET);
  for (i = 0; i < ilen; i++) {
    fread(&tmpd, sizeof(double), 1, fpi);
    sign = tmpd;
  }
  fseek(fpi, 0, SEEK_SET);
  if ( sign < 0 ) {
    for (i = 0; i < ilen; i++) {
      fread(&tmpd, sizeof(double), 1, fpi);
      tmpd = -1.0 * tmpd;
      fwrite(&tmpd, sizeof(double), 1, fpo);
    }
  } else {
    for (i = 0; i < ilen; i++) {
      fread(&tmpd, sizeof(double), 1, fpi);
      fwrite(&tmpd, sizeof(double), 1, fpo);
    }
  }

  fclose(fpi);
  fclose(fpo);
}

void usage(void)
{
  fprintf(stderr, "Usage : signchk [i:o:H]\n");
  fprintf(stderr, "      -i input filename (default is stdin, double)\n");
  fprintf(stderr, "      -o output filename (default is stdout, double)\n");
  fprintf(stderr, "      -H show this message\n");
}
