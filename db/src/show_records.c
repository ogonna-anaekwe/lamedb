#include "../headers/show_records.h"

void show_records(struct record *existing_record, char *cmd)
{
    while (existing_record)
    {
        printf("%ld,%s", existing_record->key, existing_record->value);
        existing_record = existing_record->next_record;
    }
}