#include <stdio.h>
#include <stdlib.h>

typedef struct nodetag {
  char letter;
  struct nodetag *leftlink;
  struct nodetag *rightlink;
} nodetype;

typedef nodetype *string;

