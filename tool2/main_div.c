/**************************
main_div.c

Written by T.Yamada

Last modified at 1996.11.18
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

void usage(void);

void main(int argc, char **argv)
{
  extern char *optarg;
  extern int  optind;
  int         opt;
  char        d_flag = DOWN;
  char        m_flag = DOWN;
  char        o_flag = DOWN;

  FILE   *fpi;     /* input  file           */
  FILE   **fpo;    /* output files          */

  int    m;        /* number of microphones */
  char   obn[255]; /* output basename       */
  char   ofn[255]; /* output filename       */

  int    i;
  short  tmps;
  double tmpd;

  fpi = stdin;
  while ((opt = getopt(argc, argv, "dm:i:o:H")) != EOF) {
    switch (opt) {
    case 'd':
      d_flag = UP;
      break;
    case 'm':
      m = atoi(optarg);
      m_flag = UP;
      break;
    case 'i':
      fpi = FopenRead(optarg);
      break;
    case 'o':
      strcpy(obn, optarg);
      o_flag = UP;
      break;
    case 'H':
      usage();
      exit(-1);
    default:
      usage();
      exit(-1);
    }
  }
  if (m_flag == DOWN || o_flag == DOWN) {
    usage();
    exit(-1);
  }

  /* open output files */
  if ((fpo = (FILE **) malloc(sizeof(FILE *) * m)) == NULL) {
    fprintf(stderr, "Can't allocate memory.\n");
    exit(-1);
  }
  for (i = 0; i < m; i++) {
    sprintf(ofn, "%s.%d", obn, i + 1);
    fpo[i] = FopenWrite(ofn);
  }

  /* output */
  i = 0;
  if (d_flag == DOWN) {
    while (fread(&tmps, sizeof(short), 1, fpi) == 1) {
      fwrite(&tmps, sizeof(short), 1, fpo[i % m]);
      i++;
    }
  } else {
    while (fread(&tmpd, sizeof(double), 1, fpi) == 1) {
      fwrite(&tmpd, sizeof(double), 1, fpo[i % m]);
      i++;
    }
  }

  fclose(fpi);
  for (i = 0; i < m; i++) {
    fclose(fpo[i]);
  }
  free(fpo);
}

void usage(void)
{
  fprintf(stderr, "Usage : div [dm:i:o:H]\n");
  fprintf(stderr, "      -d double (default is short)\n");
  fprintf(stderr, "      -m number of microphones\n");
  fprintf(stderr, "      -i input array signal filename (default is stdin)\n");
  fprintf(stderr, "         Data type must be short or double.\n");
  fprintf(stderr, "      -o output signal basename\n");
  fprintf(stderr, "         Output data type is short or double.\n");
  fprintf(stderr, "      -H show this message\n");
}
