#ifndef __delete_record_h__
#define __delete_record_h__

#include "init_db.h"
#include "put_record.h"
#include "insert_node.h"
#include "show_records.h"
#include "delete_record.h"

/**
 * Deletes existing record from db.
 * Overwrites db file with list (leaving out the record to be deleted).
 * @param db_records Records in the db.
 * @param record_key Key identifying a record in the db.
 * @param cmd Query: d(elete).
 */
void delete_record(struct record *db_records, long record_key, char cmd);
#endif //__delete_record_h__