#include "../headers/put_record.h"

void put_record(struct record *db_records, char *record_key, char *record_value, char cmd)
{
    bool create_new_record = get_record(db_records, record_key, cmd) == 0,
         keys_match = 0;

    FILE *db = fopen(DB_NAME, "w");
    CHECK_FILE(db);

    if (create_new_record)
    {
        struct record *new_record = insert_node(db_records, record_key, record_value, create_new_record);
        show_records(new_record, db);
    }

    if (!create_new_record) /* Updating record that matches key */
    {
        while (db_records)
        {
            keys_match = (db_records->key == strtol(record_key, NULL, BASE));
            keys_match ? fprintf(db, "%ld,%s\n", db_records->key, record_value) : fprintf(db, "%ld,%s", db_records->key, db_records->value);
            db_records = db_records->next_record;
        }
    }

    fclose(db);
}