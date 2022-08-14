#include "../headers/query_router.h"

void query_router(struct record *db_records, char *key, char *value, char cmd)
{
    switch (cmd)
    {
    case 'p':
        put_record(db_records, key, value, cmd);
        break;
    case 'g':
        get_record(db_records, key, cmd);
        break;
    case 'd':
        delete_record(db_records, key, cmd);
        break;
    case 'a':
        show_records(db_records, stdout);
        break;
    case 'c':
        clear_db();
        break;
    }
}