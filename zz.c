#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* string;

int main(int argc, char*argv[])
{
  if (argc== 1){
    printf("zz string\nreturns a list of typed commands containing string\n");
    return 2;
  }
  int results=0;
  int i,rr;
  char resultsText[100][300];
  char readin[300];
  FILE *history;
  char *value;
  char test[200]="";
  const char *name = "HOME";
  char *tt = "/.bash_history";
  value = getenv(name);
  strcat(test, value);
  strcat(test, tt);
  history = fopen(test,"r");
  while(fgets(readin,300,history))
  {
    if (strcasestr(readin,argv[1]) != 0)
    {
      if (results >=2)
      {
        rr = 0;
        for(i=0;i<results;i++)
        {

          if(strcmp(readin,resultsText[i]) == 0)
          {
            i = results;
            rr++;
          }
        }
        if(rr == 0)
        {
          strcpy(resultsText[results],readin);
          results++;
        }
      }else{
        strcpy(resultsText[results],readin);
        results++;
      }
      if (results >= 100)
        break;
    }
  }
  fclose(history);
  for(i=0;i<results;i++)
  {
     printf("%s",resultsText[i]);
  }
}
