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

    size_t record_len = 0,
           record_key_len,
           record_value_len,
           record_idx; /* 0 for key; 1 for value */

    char *record_ptr = NULL,
         *delim = ",", /* db fields are comma-separated */
        *record_entry, /* record: i.e. key-value comma-separated pair */
        *record_key,
         *record_value,
         *record_entry_split[FIELDS]; /* This will hold key and value from the db */

    struct record *db_records = NULL; /* The db file will be read into this list */

    while (getline(&record_ptr, &record_len, db) != -1)
    {
        record_idx = 0;
        while ((record_entry = strsep(&record_ptr, delim)) != NULL)
        {
            record_entry_split[record_idx] = record_entry;
            record_idx++;
        }

        record_key_len = strlen(record_entry_split[0]);
        record_key = (char *)malloc(record_key_len);
        CHECK_MALLOC(record_key);
        strncpy(record_key, record_entry_split[0], record_key_len); /* Copy over key (from db) */

        record_value_len = strlen(record_entry_split[1]);
        record_value = (char *)malloc(record_value_len);
        CHECK_MALLOC(record_value);
        strncpy(record_value, record_entry_split[1], record_value_len); /* Copy over value (from db) */

        db_records = insert_node(db_records, record_key, record_value, 0);
    }
    fclose(db);

    return db_records;
}
