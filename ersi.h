#ifndef __ERSI_H__
#define __ERSI_H__

#include <stdio.h>
#include <string>
#include <string.h>
#include <inttypes.h>
#include "hfile.h"
#include "shpfile.h"
#include "shxfile.h"
#include "dbffile.h"

class ERSI{
public:
	ERSI(const char* shpPath, const char* shxPath, const char* dbfPath);
	ERSI(std::string base);
	void print(FILE* fp = stdout);
private:
	SHP m_shpFile;
	SHX m_shxFile;
	DBF m_dbfFile;
};

#endif
