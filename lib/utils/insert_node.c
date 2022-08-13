#include "../headers/insert_node.h"

struct record *insert_node(struct record *existing_record, char *record_key, char *record_value, bool is_new)
{
    struct record *new_record;
    new_record = (struct record *)malloc(sizeof(struct record));
    CHECK_MALLOC(new_record)
    new_record->value = (char *)malloc(strlen(record_value) + is_new); /* is_new is 1 for new records. This gives room for the new line delimiter. Otherwise, it's 0 and no extra room is needed as the existing record is already new line delimited */
    CHECK_MALLOC(new_record->value);

    new_record->key = strtol(record_key, NULL, BASE);
    strncpy(new_record->value, record_value, strlen(record_value));

    if (is_new)
    {
        strncat(new_record->value, "\n", strlen(new_record->value));
    }

    new_record->next_record = existing_record;

    existing_record = new_record;
    return existing_record;
}