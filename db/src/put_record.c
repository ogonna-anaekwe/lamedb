#include "../headers/get_record.h"
#include "../headers/put_record.h"
#include "../headers/insert_node.h"

void put_record(struct record *existing_record, char *record_key, char *record_value, char *cmd)
{
    bool create_new_record = get_record(existing_record, record_key, record_value, cmd) == 0,
         keys_match = 0;
    FILE *db = fopen(DB_NAME, "w");
    CHECK_FILE(db);

    if (create_new_record)
    {
        struct record *new_record = insert_node(existing_record, record_key, record_value, create_new_record);

        while (new_record)
        {
            fprintf(db, "%ld,%s", new_record->key, new_record->value);
            new_record = new_record->next_record;
        }
    }

    if (!create_new_record) /* Updating record that matches key */
    {
        while (existing_record)
        {
            keys_match = (existing_record->key == strtol(record_key, NULL, BASE));
            keys_match ? fprintf(db, "%ld,%s\n", existing_record->key, record_value) : fprintf(db, "%ld,%s", existing_record->key, existing_record->value);
            existing_record = existing_record->next_record;
        }
    }
    fclose(db);
}