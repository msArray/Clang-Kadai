#include <stdio.h>
#include <stdlib.h>
#define __NAME_LENGTH__ 20
#define __MAX_POKEMON__ 100

typedef struct {
  char name[__NAME_LENGTH__];
  int height;
} Character;

Character search(const Character a[], int n, int key){
  int pl = 0;
  int pr = n - 1;
  int pc;

  do{
    pc = (pl + pr) / 2;
    if(a[pc].height == key){
      return a[pc];
    }
    if(a[pc].height < key){
      pl = pc + 1;
    }else pr = pc - 1;
  } while(pl <= pr);

  Character nl = {"error", -1};

  return nl;
}

int main(void) {
  FILE *fp;
  int pokeheight;
  Character pokemons[__MAX_POKEMON__];
  printf("input height: ");
  scanf("%d",&pokeheight);
  fp = fopen("pokemon.txt", "r");
  if(fp == NULL){
    printf("Error opening file\n");
    exit(1);
  };

  int len;

  for(len = 0; fscanf(fp, "%s %d", pokemons[len].name, &pokemons[len].height) == 2; len++);

  Character result = search(pokemons, len, pokeheight);
  if(result.height == -1) printf("not found\n");
  else printf("%s\n", result.name);

  fclose(fp);
}