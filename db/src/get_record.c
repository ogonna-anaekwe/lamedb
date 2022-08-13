#include "../headers/get_record.h"
#include "../headers/put_record.h"

bool get_record(struct record *existing_record, char *record_key, char *record_value, char *cmd)
{

    long record_key_num = strtol(record_key, NULL, BASE);
    bool record_exists = 0,
         get_cmd = strncmp(cmd, "g", strlen(cmd)) == 0;

    while (existing_record)
    {
        record_exists = existing_record->key == record_key_num;
        if (record_exists)
        {
            if (get_cmd)
            {
                printf("%ld,%s", existing_record->key, existing_record->value);
            }
            break;
        }

        existing_record = existing_record->next_record;
    }

    if (!record_exists)
    {
        if (get_cmd)
        {
            printf("No record for key %ld in db.\nYou can add one thus: ./kv p,%ld,<value>\n", record_key_num, record_key_num);
        }
    }

    return record_exists; /* Determines how to handle 'puts': update (if record exists) or create new record otherwise */
}