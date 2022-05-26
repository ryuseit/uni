/**************************
main_dcut.c

Written by M.Nakayama

Last modified at 2002.06.17
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "common.h"

#define ERR 1.0e-10

void usage(void);

void main(int argc, char **argv)
{
  extern char *optarg;
  extern int  optind;
  int         opt;
  int         i_flag  = DOWN;
  int         m_flag  = DOWN;
  int         s_flag  = DOWN;
  int         e_flag  = DOWN;

  FILE   *fpi;  /* input file              */
  FILE   *fpo;  /* output file             */
  int    stlen; /* start of signal length  */
  int    edlen; /* end of signal length    */
  int    inlen; /* length of input signals */
  int    m;     /* number of microphone    */
  int    i,j;
  double  tmpd;

  fpo  = stdout;

  while ((opt = getopt(argc, argv, "m:s:e:i:o:H")) != EOF) {
    switch (opt) {
    case 'm':
      m     = atoi(optarg);
      m_flag = UP;
      break;
    case 's':
      stlen = atoi(optarg);
      s_flag = UP;
      break;
    case 'e':
      edlen = atoi(optarg);
      e_flag = UP;
      break;
    case 'i':
      fpi = FopenRead(optarg);
      i_flag = UP;
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

  if (i_flag == DOWN || s_flag == DOWN || e_flag == DOWN) {
    usage();
    exit(-1);
  }
  if (m_flag == DOWN) {
    m = 1;
  }

  fseek(fpi, 0, SEEK_END);
  inlen = ftell(fpi) / (m * sizeof(double));
  fseek(fpi, 0, SEEK_SET);
  if (inlen < stlen || inlen < edlen) {
    usage();
    exit(-1);
  }
  for (i = 0; i < stlen; i++) {
    for(j = 0; j < m; j++) {
      fread(&tmpd, sizeof(double), 1, fpi);
    }
  }
  for (i = stlen; i < edlen; i++) {
    for(j = 0; j < m; j++) {
      fread(&tmpd, sizeof(double), 1, fpi);
      fwrite(&tmpd, sizeof(double), 1, fpo);
    }
  }
  fclose(fpi);
  fclose(fpo);
}

void usage(void)
{
  fprintf(stderr, "Usage : dcut [m:s:e:i:o:H]\n");
  fprintf(stderr, "      -m number of microphone (default is 1,atoi)\n");
  fprintf(stderr, "      -s start of signal length (atoi)\n");
  fprintf(stderr, "      -e end of signal length (atoi)\n");
  fprintf(stderr, "      -i input speech filename (double)\n");
  fprintf(stderr, "      -o output filename (default is stdout)\n");
  fprintf(stderr, "      -H show this message\n");
}
