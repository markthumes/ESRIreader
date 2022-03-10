#ifndef __HFILE_H__
#define __HFILE_H__

#include <stdio.h>
#include <string>
#include <string.h>
#include <inttypes.h>

class HFile{
public:
	HFile(const char* filename = NULL);
	void setFileName(const char* filename);
	int open(const char* filename = NULL);
	uint8_t& operator[](int i);
	~HFile();
	void info(FILE* fp = stdout);
protected:
	uint8_t* 	m_data;
private:
	FILE* 		m_fp;
	const char* 	m_filename;
	long		m_size;
};

#endif
