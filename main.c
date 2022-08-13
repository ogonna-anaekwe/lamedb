#include "./lib/headers/init_db.h"
#include "./lib/headers/get_record.h"
#include "./lib/headers/put_record.h"
#include "./lib/headers/show_records.h"
#include "./lib/headers/clear_db.h"

int main(int argc, char *argv[])
{
    struct record *db_records = initialize_db();
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
        get_record(db_records, key, value, cmd);
    }

    if (put_cmd)
    {
        put_record(db_records, key, value, cmd);
    }

    if (show_cmd)
    {
        show_records(db_records, stdout);
    }

    if (clear_cmd)
    {
        clear_db();
    }

    return 0;
}