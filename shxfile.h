#ifndef __SHXFILE_H__
#define __SHXFILE_H__

#include <stdio.h>
#include <string>
#include <string.h>
#include <inttypes.h>
#include "hfile.h"

class SHX : public HFile {
public:
	void parse(const char* filename);
};

#endif
