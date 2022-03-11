#include "ersi.h"

ERSI::ERSI(const char* shpPath, const char* shxPath, const char* dbfPath){
	m_shpFile.parse(shpPath);
	m_shxFile.parse(shxPath);
	m_dbfFile.parse(dbfPath);
}
ERSI::ERSI(std::string base){
	m_shpFile.parse((base+std::string(".shp")).c_str());
	m_shxFile.parse((base+std::string(".shp")).c_str());
	m_dbfFile.parse((base+std::string(".shp")).c_str());
}
void ERSI::print(FILE* fp){
	m_shpFile.print(fp);
}
