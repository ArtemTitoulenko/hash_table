#ifndef _HASH_H
#define _HASH_H

#include <stdlib.h>
#include <string.h>

struct hash_node {
  char * word;
  void * data;
  struct hash_node * next;
};

struct hash_table {
  int size;
  int population;
  void (* free_node)(void*);
  struct hash_node ** storage;
};


struct hash_node * hash_node_new(char * word, void * elem);
void hash_nodes_free(struct hash_node * node, void (*free_data)(void *));
void hash_node_free(struct hash_node * node, void (*free_data)(void*));

struct hash_table* hash_table_new(int size, void (* free_node)(void *));
void hash_table_free(struct hash_table * table);
int hash_table_store(struct hash_table * table, char * word, void * node);
int hash_table_delete(struct hash_table * table, char * word);
void hash_table_resize(struct hash_table * table);
struct hash_node * hash_table_get_hash_node(struct hash_table * table, char * word);
void * hash_table_get(struct hash_table * table, char * word);
char ** hash_table_get_all_keys(struct hash_table * table);

int lua_hash(char *str);

#endif

