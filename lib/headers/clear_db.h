#ifndef __clear_db_h__
#define __clear_db_h__

#include "init_db.h"

#define YES_LEN 4 /* 4 (instead of 3) so that the last character is '\0' which will make for a valid string */

/**
 * Drops the txt file representing the db.
 * We overwrite the contents (if any) of the file,
 * replacing said contents with nothing.
 * @return int - Was the db dropped?
 */
bool clear_db(void);

#endif //__clear_db_h__