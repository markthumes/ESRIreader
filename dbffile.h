#ifndef __DBFFILE_H__
#define __DBFFILE_H__

#include <stdio.h>
#include <string>
#include <string.h>
#include <inttypes.h>
#include "hfile.h"

class DBF : public HFile {
public:
	void parse(const char* filename);
};

#endif
