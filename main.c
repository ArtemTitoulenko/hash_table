#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

struct client {
  const char * name;
  int credit;
};

void free_client(void * a) {
  struct client * cli = (struct client *)a;
  int i = 0;
  free(cli);
}

int main(int argc, char ** argv) {
  struct hash_table * table = hash_table_new(1, free_client);

  struct client * cli = malloc(sizeof(struct client));
  cli->name = "foo bar"; cli->credit = 5;
  hash_table_store(table, cli->name, cli);

  cli = malloc(sizeof(struct client));
  cli->name = "far bar"; cli->credit = 6;
  hash_table_store(table, cli->name, cli);

  printf("deleting: %i, should be 0\n", hash_table_delete(table, "foo bar"));
  printf("deleting: %i, should be 1\n", hash_table_delete(table, "doesn't exist"));

  struct client * cl2 = hash_table_get(table, "far bar");
  printf("%s has %i money\n", cl2->name, cl2->credit);

  hash_table_free(table);
  return 0;
}
