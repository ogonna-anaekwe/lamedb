#ifndef __query_router_h__
#define __query_router_h__

#include "init_db.h"
#include "delete_record.h"
#include "get_record.h"
#include "put_record.h"
#include "show_records.h"
#include "clear_db.h"

/**
 * Loops through array, executing queries sequentially.
 * @param queryv array of queries. This is just argv.
 */
void query_router(char *queryv[]);

#endif //__query_router_h__