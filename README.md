# hash_table

This is a short (288 loc), simple hash table implementation in C. It has evolved over the year and has been rewritten at least once. It attempts to offer some comforts, but don't expect many niceties.

## EXAMPLE

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #include "hash.h"
    
    struct client {
      const char * name;
      int credit;
    };
    
    void free_fn(void * data) {}

    int main(int argc, char ** argv) {
      /* create a new hash table, (table size)
      struct hash_table * table = hash_table_new(1);
    
      struct client * cli = malloc(sizeof(struct client));
      cli->name = "foo bar"; cli->credit = 5;
      
      /* store a `client` in the table, (table, key, value) */
      hash_table_store(table, cli->name, cli);
    
      cli = malloc(sizeof(struct client));
      cli->name = "far bar"; cli->credit = 6;
      hash_table_store(table, cli->name, cli);
      
      cli = hash_table_delete(table, "foo bar"); /* returns the deleted value */
      printf("deleting: %i, should be 1\n", cli != NULL);
      cli = hash_table_delete(table, "doesn't exist"); /* returns NULL */
      printf("deleting: %i, should be 1\n", cli == NULL);
    
      /* get the value for a key, (table, key) */
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
    
      /* free the table automagically*/
      hash_table_destroy(table, free_fn);
      return 0;
    }
    
## BUILDING

The example application can be built by running `make` or `make test`. A static library, libhash.a, can be built by running `make lib`. Alternatively, the `hash.h` and `hash.o` files may be copied over into your project source directory and built using the toolchain there.

## DOCUMENTATION

### struct hash_table

    struct hash_table {
      int size;
      int population;
    
      float growth_proportion;
      float shrink_proportion;
    
      struct hash_node ** storage;
    };

### hash_table_new(int size)

Creates a new `struct hash_table *` and takes an initial size for the hash table storage. This storage will grow and shrink based on ratio's defined by `.growth_proportion` (default: 0.7), and `.shrink_proportion` (default: 0.25).

### void \* hash_table_store(\* table, char \* word, void \* elem)

Store an element `elem` in `table` under the key `word`. Store may also replace elements if there is an element stored under `word` already. The old element is passed back if it is replaced, otherwise NULL is returned.

### void \* hash_table_get(\* table, char \* word)

Retrieves the element stored at `word`, otherwise `NULL`.

### void \* hash_table_delete(\* table, char \* word)

Attempts to delete an element from the hash table. Returns the element that was deleted, otherwise `NULL`.

### char \*\* hash_table_get_all_keys(\* table)

Returns an array of `char *`'s that point to all of the keys in the table.  

### void hash_table_destroy(\* table, void (\*free_fn)(void*))

Calls `free_fn` on each value stored in the hash table, and then destroys all of the internal nodes and the hash table itself.

## LICENSE

The MIT License (MIT)
Copyright (c) 2013 Artem Titoulenko

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

