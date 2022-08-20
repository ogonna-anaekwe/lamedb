#include "../headers/query_router.h"

void query_router(char *queryv[])
{
    int query_idx = 1; /* Grab cli args after the executable */
    while (queryv[query_idx])
    {
        struct record *db_records = initialize_db(); /* Initialize db for every query so subsequent queries are working w/ the latest data */

        char *query = queryv[query_idx],
             *query_param,
             *query_split[3]; /* Max args for any valid query is 3: query_cmd, record_key, record_value */

        int query_param_idx = 0;

        while ((query_param = strsep(&query, ",")) != NULL)
        {
            query_split[query_param_idx] = query_param;
            query_param_idx++;
        }

        char cmd = query_split[0][0], /* query_split[0] is a string. Taking the first idx gives the character corresponding to the cmd */
            *value = query_split[2];

        long key = 0;
        if (query_split[1])
        {
            key = strtol(query_split[1], NULL, BASE);
            CHECK_KEY(key);
        }

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
        default:
            printf("'%c' is an invalid command. Valid commands: p, g, d, a, c.\n", cmd);
        }

        query_idx++;
    }
}