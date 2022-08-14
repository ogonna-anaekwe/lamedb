#ifndef __query_router_h__
#define __query_router_h__

#include "init_db.h"
#include "delete_record.h"
#include "get_record.h"
#include "put_record.h"
#include "show_records.h"
#include "clear_db.h"

/**
 * Intercepts a query (from the cli) and calls
 * the corresponding func
 * @param db_records Records in the db.
 * @param record_key Key identifying a record in the db.
 * @param record_value Value corresponding to key in the db.
 * @param cmd Query: g(et), p(ut), d(elete), a(ll), s(how).
 */
void query_router(struct record *db_records, char *record_key, char *record_value, char cmd);

#endif //__query_router_h__