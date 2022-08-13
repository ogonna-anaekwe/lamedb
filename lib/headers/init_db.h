#ifndef __init_db_h__
#define __init_db_h__

#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>

#define FIELDS 2
#define BASE 10
#define DB_NAME "lamedb_kv.txt"

struct record
{
    long key;
    char *value;
    struct record *next_record;
}; /* db schema */

#define CHECK_MALLOC(ptr) assert(ptr != NULL); /* Did malloc succeed? */
#define CHECK_FILE(db) assert(db != NULL);     /* Was the file successfully opened? */
#define CHECK_KEY(key) assert(key > 0);        /* Ensure key exceeds zero */

/**
 * Initializes the db (which is a txt file).
 * Creates an empty file (if the db doesn't exist).
 * The db is read into a linked list (which is then returned).
 * Here, each line in the txt file (and by extension each node in the list) is a unique record.
 * The 'key' field (in the file/list) guarantees uniqueness.
 * @return struct record* - List containing db records.
 */
struct record *initialize_db(void);
#endif //__init_db_h__