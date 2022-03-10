#include <stdio.h>
#include <string>
#include <string.h>
#include <inttypes.h>
#include "hfile.h"

class SHP : public HFile {
public:
	void parse(const char* filename){
		open(filename);
		header.fileCode = m_data[0] << 24 |
			   m_data[1] << 16 |
			   m_data[2] <<  8 |
			   m_data[3] <<  0 ;
		header.fileLength = m_data[0] << 24 |
			   m_data[1] << 16 |
			   m_data[2] <<  8 |
			   m_data[3] <<  0 ;
		memcpy(&header.version,   &m_data[28], sizeof(int32_t));
		memcpy(&header.shapeType, &m_data[32], sizeof(int32_t));
		for( int i = 0; i < 4; i++ ){
			memcpy(	&header.boundingBox[i],
				&m_data[36+i*sizeof(double)],
				sizeof(double));
		}
		memcpy( &header.boundingBox[0], &m_data[68], sizeof(double));
		memcpy( &header.boundingBox[1], &m_data[76], sizeof(double));
		memcpy( &header.boundingBox[0], &m_data[84], sizeof(double));
		memcpy( &header.boundingBox[1], &m_data[92], sizeof(double));
	}
	void print( FILE* fp = stdout ){
		fprintf(fp, "File Code  : 0x%08x\n", header.fileCode );
		fprintf(fp, "File Length: %d\n",   header.fileLength );
		fprintf(fp, "Version    : %d\n",   header.version  );
		fprintf(fp, "Shape Type : %d\n",   header.shapeType);
		fprintf(fp, "Minimum bounding rectangle: %f, %f, %f, %f\n", 
			header.boundingBox[0], header.boundingBox[1], 
			header.boundingBox[2], header.boundingBox[3] );
		fprintf(fp, "Z Range: %f -> %f\n", 
			header.boundingBox[4], header.boundingBox[5]);
		fprintf(fp, "M Range: %f -> %f\n", 
			header.boundingBox[6], header.boundingBox[7]);
	}
private:
	struct Header{
		int32_t fileCode;
		int32_t unused[5];
		int32_t fileLength;
		int32_t version;
		int32_t shapeType;
		double  boundingBox[8];
	};
	struct RecordHeader{
	};
	struct RecordContents{
	};
	Header header;
	RecordHeader* recordHeader;
	RecordContents* recordContents;
};
class SHX : public HFile {
public:
	void parse(const char* filename){
		open(filename);
	}
private:
};
class DBF : public HFile {
public:
	void parse(const char* filename){
		open(filename);
	}
private:
};
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
