#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1

FILE * open_file(const char * name) {
  FILE * pFile = NULL;
  pFile = fopen(name,"r");
  if (!pFile){
    printf("Failed to open file\n");
    return NULL;
  }
  return pFile;
}

// TODO: error handling
int get_number(FILE * pFile, int * number) {
    char s[24];
    char * ptr=s;
    fscanf(pFile, "%s", s);
    *number = strtol(s, &ptr, 10);
    if (ptr==s) {
        // error, it was not a number
        return FAILURE;
    }
    return SUCCESS;
}

// TODO: error handling
int get_char(FILE * pFile, char * cmd) {
    char s[24];
    fscanf(pFile, "%s", s);
    *cmd = s[0];
    return SUCCESS;
}

void read_args(FILE * pFile,int argc, int * args) {
    for (int i=0;i<argc;++i) {
        get_number(pFile, args+i);
    }
}

void read_commands(FILE * pFile, int amount) {
  char cmd = 0;
  int args[2];
  printf("Commands: %d\n", amount);
  for (int i=0; i<amount; ++i) {
      get_char(pFile, &cmd);
      switch (cmd) {
         case 'p':
            printf("p: no args\n");
            break;
          case 'a':
               read_args(pFile, 1, args);
               printf("a: %d\n", args[0]);
               break;
          case 'i':
               read_args(pFile, 2, args);
               printf("i: %d %d\n", args[0], args[1]);
              break;
      }
  }
}

int main (int argc, char ** argv)
{
  FILE * pFile = open_file(argv[1]);
  if (!pFile) return -1;

  int amount = 0;
  if (get_number(pFile, &amount) != SUCCESS) {
      printf("First value not a number\n");
      fclose(pFile);
  }

  read_commands(pFile, amount);

  fclose (pFile);
  return 0;
}

