/**************************
common_fopen.c

Written by Y.DENDA

Last Modefied at 2004.07.07
**************************/

#include <stdio.h>

/*------------------------------*/
FILE *FopenRead(char *filename)
{
  FILE *fp;
  
  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Can't open %s.\n", filename);
    exit(-1);
  }
  return fp;
}

/*------------------------------*/
FILE* FopenReadB(char* filename)
{
  FILE* fp;
  
  if((fp = fopen(filename, "rb")) == NULL){
    fprintf(stderr, "Can't open %s.\n", filename);
    exit(1);
  }
  
  return fp;
}

/*------------------------------*/
FILE *FopenWrite(char *filename)
{
  FILE *fp;
  
  if ((fp = fopen(filename, "w")) == NULL) {
    fprintf(stderr, "Can't open %s.\n", filename);
    exit(-1);
  }
  return fp;
}

/*------------------------------*/
FILE* FopenWriteB(char* filename)
{
  FILE* fp;
  
  if((fp = fopen(filename, "wb")) == NULL){
    fprintf(stderr, "Can't open %s.\n", filename);
    exit(1);
  }
  
  return fp;
}

/*------------------------------*/
int FgetLength(FILE* fp, size_t size)
{
	int len;

	fseek(fp, 0, SEEK_END);
  len = ftell(fp) / size;
  fseek(fp, 0, SEEK_SET);

	return len;
}
