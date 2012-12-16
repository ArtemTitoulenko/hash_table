#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

struct client {
  const char * name;
  int credit;
};

int main(int argc, char ** argv) {
	int i;
  struct hash_table * table = hash_table_new(1);

  struct client * cli = malloc(sizeof(struct client));
  cli->name = "foo bar"; cli->credit = 5;
  hash_table_store(table, cli->name, cli);

  cli = malloc(sizeof(struct client));
  cli->name = "far bar"; cli->credit = 6;
  hash_table_store(table, cli->name, cli);

  cli = hash_table_delete(table, "foo bar"); /* returns the deleted value */
  printf("deleting: %i, should be 1\n", cli != NULL);
  cli = hash_table_delete(table, "doesn't exist"); /* returns NULL */
  printf("deleting: %i, should be 1\n", cli == NULL);

  struct client * cl2 = hash_table_get(table, "far bar");
  printf("%s has %i money\n", cl2->name, cl2->credit);

	/* get all of the keys and list them */
	char ** keys = hash_table_get_all_keys(table);
	for (i = 0; i < table->population; i++) {
		printf("key: %s\n", keys[i]);
	}
	
	free(keys);
	free(cli);
	free(cl2);

  hash_table_destroy(table);
  return 0;
}
