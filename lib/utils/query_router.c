#include "../headers/query_router.h"

void query_router(struct record *db_records, char *key, char *value, char *cmd)
{
    bool put_cmd = strncmp(cmd, "p", strlen(cmd)) == 0,
         get_cmd = strncmp(cmd, "g", strlen(cmd)) == 0,
         del_cmd = strncmp(cmd, "d", strlen(cmd)) == 0,
         show_cmd = strncmp(cmd, "a", strlen(cmd)) == 0,
         clear_cmd = strncmp(cmd, "c", strlen(cmd)) == 0;

    if (get_cmd)
    {
        get_record(db_records, key, cmd);
    }

    if (put_cmd)
    {
        put_record(db_records, key, value, cmd);
    }

    if (del_cmd)
    {
        delete_record(db_records, key, cmd);
    }

    if (show_cmd)
    {
        show_records(db_records, stdout);
    }

    if (clear_cmd)
    {
        clear_db();
    }
}