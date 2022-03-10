#include "hfile.h"

HFile::HFile(const char* filename){
	m_filename = filename;
	m_fp = NULL;
	m_data = NULL;
	m_size = 0;
}
void HFile::setFileName(const char* filename){
	m_filename = filename;
}
int HFile::open(const char* filename){
	if( filename != NULL ) m_filename = filename;
	if( (m_fp = fopen(m_filename, "r+")) == NULL ){
		fprintf(stderr, "Failed to open %s\n",
				m_filename);
		return 1;
	}
	if( fseek( m_fp, 0, SEEK_END ) != 0 ){
		fprintf(stderr, "Failed to seek\n");
		return 2;
	}
	m_size = ftell( m_fp );
	if( fseek( m_fp, 0, SEEK_SET ) != 0 ){
		fprintf(stderr, "Failed to seek\n");
		return 2;
	}
	m_data = new uint8_t[m_size];
	fread( m_data, m_size, 1, m_fp );
	return 0;
}
uint8_t& HFile::operator[](int i){
	return m_data[i];
}
HFile::~HFile(){
	fclose(m_fp);
	delete [] m_data;
	m_data = NULL;
}
void HFile::info(FILE* fp){
	fprintf(fp, "File Name: %s\n", m_filename);
	fprintf(fp, "File Size: %ld\n", m_size);
}
