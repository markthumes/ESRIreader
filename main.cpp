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
	ERSI(const char* shpPath, const char* shxPath, const char* dbfPath){
		m_shpFile.parse(shpPath);
		m_shxFile.parse(shxPath);
		m_dbfFile.parse(dbfPath);
	}
	ERSI(std::string base){
		m_shpFile.parse((base+std::string(".shp")).c_str());
		m_shxFile.parse((base+std::string(".shp")).c_str());
		m_dbfFile.parse((base+std::string(".shp")).c_str());
	}
	void print(FILE* fp = stdout){
		m_shpFile.print(fp);
	}
private:
	SHP m_shpFile;
	SHX m_shxFile;
	DBF m_dbfFile;
};

int main(int argc, char** argv){
	float version = 0.1;
	std::string base;
	for( int i = 0; i < argc; i++ ){
		if( strcmp(argv[i], "-V" ) == 0 ){
			fprintf(stdout, "%f\n", version);
			return 0;
		}
		if( strcmp(argv[i], "--file") == 0 ){
			base = argv[i+1];
		}
	}
	ERSI ersi(base);
	ersi.print(stdout);
	return 0;
};
