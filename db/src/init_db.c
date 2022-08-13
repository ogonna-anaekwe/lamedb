#include "../headers/init_db.h"
#include "../headers/insert_node.h"

struct record *initialize_db(void)
{
    bool db_exists = access(DB_NAME, R_OK | W_OK | F_OK) == 0;
    FILE *db;

    if (!db_exists)
    {
        if (errno == ENOENT)
        {
            fprintf(stderr, "Error code: %d. %s doesn't exist.\nCreating empty db!\n", errno, DB_NAME);
            db = fopen(DB_NAME, "w"); /* Creates empty file (if db doesn't exist) */
            CHECK_FILE(db);
        }
    }

    if (db_exists)
    {
        db = fopen(DB_NAME, "r");
        CHECK_FILE(db);
    }

    size_t line_len = 0,
           key_len,
           value_len,
           record_idx; /* 0 for key; 1 for value */

    char *line_ptr = NULL,
         *delim = ",",
         *record_entry,
         *record_key,
         *record_value,
         *record_entry_split[FIELDS]; /* This will hold key and value from the db */

    struct record *existing_record = NULL;

    while (getline(&line_ptr, &line_len, db) != -1)
    {
        record_idx = 0;
        while ((record_entry = strsep(&line_ptr, delim)) != NULL)
        {
            record_entry_split[record_idx] = record_entry;
            record_idx++;
        }

        key_len = strlen(record_entry_split[0]);
        value_len = strlen(record_entry_split[1]);
        record_key = (char *)malloc(key_len);
        strncpy(record_key, record_entry_split[0], key_len);
        record_value = (char *)malloc(value_len);
        strncpy(record_value, record_entry_split[1], value_len);

        existing_record = insert_node(existing_record, record_key, record_value, 0);
    }
    fclose(db);

    return existing_record;
}
