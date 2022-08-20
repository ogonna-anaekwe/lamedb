#include "../headers/get_record.h"

bool get_record(struct record *db_records, long record_key, char cmd)
{
    bool record_exists = 0,
         get_cmd = cmd == 'g',
         del_cmd = cmd == 'd';

    while (db_records)
    {
        record_exists = db_records->key == record_key;
        if (record_exists)
        {
            if (get_cmd)
            {
                printf("%ld,%s", db_records->key, db_records->value);
            }
            break; /* w/o this, there will be duplicates. Remove this and see */
        }

        db_records = db_records->next_record;
    }

    if (!record_exists && (get_cmd || del_cmd))
    {
        printf("No record for key %ld in db.\n", record_key);
    }

    return record_exists; /* Determines how to handle 'puts': update (if record exists) or create new record otherwise */
}