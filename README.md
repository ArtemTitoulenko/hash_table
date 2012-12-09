# hash_table

This is a short (255 loc), simple hash table implementation in C. It has evolved over the year and has been rewritten at least once. It attempts to offer some comforts, but don't expect many niceties.

## EXAMPLE

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
      /* create a new hash table, (table size, free_func)
      struct hash_table * table = hash_table_new(1, free_client);
    
      struct client * cli = malloc(sizeof(struct client));
      cli->name = "foo bar"; cli->credit = 5;
      
      /* store a `client` in the table, (table, key, value) */
      hash_table_store(table, cli->name, cli);
    
      cli = malloc(sizeof(struct client));
      cli->name = "far bar"; cli->credit = 6;
      hash_table_store(table, cli->name, cli);
      
      /* delete an element at a key, (table, key) */
      printf("deleting: %i, should be 0\n", hash_table_delete(table, "foo bar"));
      printf("deleting: %i, should be 1\n", hash_table_delete(table, "doesn't exist"));
    
      /* get the value for a key, (table, key) */
      struct client * cl2 = hash_table_get(table, "far bar");
      printf("%s has %i money\n", cl2->name, cl2->credit);
    
      /* free the table, and all of it's values automagically*/
      hash_table_free(table);
      return 0;
    }
    
## BUILDING

The example application can be built by running `make` or `make test`. A static library, libhash.a, can be built by running `make lib`. Alternatively, the `hash.h` and `hash.o` files may be copied over into your project source directory and built using the toolchain there.

## DOCUMENTATION

### hash_table_new(int size, void (\*free_func)(void \*))

Creates a new `struct hash_table *` and takes an initial size for the hash table storage and a function that takes one `void *` that will perform the necessary cleanup for your struct. `free_func` cannot be `NULL`.

### int hash_table_store(\* table, char \* word, void \* elem)

Store an element `elem` in `table` under the key `word`. Theoretically, `elem` can be any kind of object, however the `free_func`, mentioned before, may segfault. Store may also replace elements if there is an element stored under `word` already. The old element is free'd with the `free_func` passed into `hash_table_new`. Returns 0 if successful, 1 otherwise.

### void \* hash_table_get(\* table, char \* word)

Retrieves the element stored at `word`, `NULL` otherwise.

### int hash_table_delete(\* table, char \* word)

Attempts to delete an element from the hash table. Returns 0 on success, 1 otherwise.

## LICENSE

The MIT License (MIT)
Copyright (c) 2012 Artem Titoulenko

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

