#include "../headers/delete_record.h"

void delete_record(struct record *db_records, long record_key, char cmd)
{
    bool record_exists = get_record(db_records, record_key, cmd) == 1,
         keys_match = 0;

    if (record_exists)
    {
        FILE *db = fopen(DB_NAME, "w");
        CHECK_FILE(db);
        while (db_records)
        {
            keys_match = (db_records->key == record_key);
            if (!keys_match) /* Write back records to file (leaving out the record to be deleted) */
            {
                fprintf(db, "%ld,%s", db_records->key, db_records->value);
            }
            db_records = db_records->next_record;
        }
        fclose(db);
    }
}