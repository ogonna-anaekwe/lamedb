#include "./lib/headers/init_db.h"
#include "./lib/headers/query_router.h"

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

    query_router(db_records, key, value, cmd);

    return 0;
}