#ifndef __get_record_h__
#define __get_record_h__

#include "init_db.h"

/**
 * Searches the db for the record whose key matches record_key.
 * Here, we're really just searching the list returned from
 * the initialization of the db.
 * @param db_records Records in the db.
 * @param record_key Key identifying a record in the db.
 * @param record_value Value corresponding to key in the db.
 * @param cmd Query: g(et).
 * @return bool - Does the record even exist?
 */
bool get_record(struct record *db_records, char *record_key, char *record_value, char *cmd);
#endif //__get_record_h__