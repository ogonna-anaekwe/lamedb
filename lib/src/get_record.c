#include "../headers/get_record.h"
#include "../headers/put_record.h"

bool get_record(struct record *db_records, char *record_key, char *record_value, char *cmd)
{
    long record_key_num = strtol(record_key, NULL, BASE);
    CHECK_KEY(record_key_num); /* This check is also applied in all queries that indirectly invoke the get query e.g. put */

    bool record_exists = 0,
         get_cmd = strncmp(cmd, "g", strlen(cmd)) == 0;

    while (db_records)
    {
        record_exists = db_records->key == record_key_num;
        if (record_exists && get_cmd)
        {
            printf("%ld,%s", db_records->key, db_records->value);
            break;
        }

        db_records = db_records->next_record;
    }

    if (!record_exists && get_cmd)
    {
        printf("No record for key %ld in db.\nYou can add one thus: ./kv p,%ld,<value>\n", record_key_num, record_key_num);
    }

    return record_exists; /* Determines how to handle 'puts': update (if record exists) or create new record otherwise */
}