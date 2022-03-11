#include "shpfile.h"


void SHP::parse(const char* filename){
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
	for( int i = 0; i < header.fileLength; i++ ){
	}
}
void SHP::print( FILE* fp ){
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
