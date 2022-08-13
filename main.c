#include "./db/headers/init_db.h"
#include "./db/headers/get_record.h"
#include "./db/headers/put_record.h"
#include "./db/headers/show_records.h"
#include "./db/headers/clear_db.h"

#define FIELDS 2
#define BASE 10

int main(int argc, char *argv[])
{
    struct record *existing_record = initialize_db();
    char *query = argv[1],
         *query_param,
         *query_split[3];

    int query_param_idx = 0;
    while ((query_param = strsep(&query, ",")) != NULL)
    {
        query_split[query_param_idx] = query_param;
        query_param_idx++;
    }

    char *cmd = query_split[0],
         *key = query_split[1],
         *value = query_split[2];

    bool put_cmd = strncmp(cmd, "p", strlen(cmd)) == 0,
         get_cmd = strncmp(cmd, "g", strlen(cmd)) == 0,
         show_cmd = strncmp(cmd, "a", strlen(cmd)) == 0,
         clear_cmd = strncmp(cmd, "c", strlen(cmd)) == 0;

    if (get_cmd)
    {
        get_record(existing_record, key, value, cmd);
    }

    if (put_cmd)
    {
        put_record(existing_record, key, value, cmd);
    }

    if (show_cmd)
    {
        show_records(existing_record, cmd);
    }

    if (clear_cmd)
    {
        clear_db();
    }

    return 0;
}