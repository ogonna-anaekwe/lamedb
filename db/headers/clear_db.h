#ifndef __clear_db_h__
#define __clear_db_h__

#include "init_db.h"

/**
 * Drops the db.
 * In this case, we overwrite the contents (if any) of the file with nothing.
 */
int clear_db(void);

#endif //__clear_db_h__