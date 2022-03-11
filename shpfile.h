#ifndef __SHPFILE_H__
#define __SHPFILE_H__

#include <stdio.h>
#include <string>
#include <string.h>
#include <inttypes.h>
#include "hfile.h"


class SHP : public HFile {
public: 
	//------------------------------------------------------//
	//                 Shape Type Definitions               //
	enum ShapeType{
		NullShape  =  0, Point      =  1, PolyLine   =  3,
		Polygon    =  5, MultiPoint =  8, PointZ     = 11,
		PolyLineZ  = 13, PolygonZ   = 15, MultiPointZ= 18,
		PointM     = 21, PolyLineM  = 23, PolygonM   = 25,
		MultiPointM= 28, MultiPatch = 31
	};
	struct NullShape{
		int32_t shapeType;
	};
	struct Point{
		int32_t shapeType;
		double x, y;
	};
	struct MultiPoint{
		int32_t shapeType;
		double box[4];
		int32_t numPoints;
		struct Point* points;
	};
	struct PolyLine{
		int32_t shapeType;
		double box[4];
		int32_t numParts;
		int32_t numPoints;
		int32_t* parts;
		struct Point* points;
	};
	struct Polygon{
		int32_t shapeType;
		double box[4];
		int32_t numParts;
		int32_t numPoints;
		int32_t* parts;
		struct Point* points;
	};
public:
	//------------------------------------------------------//
	//                     File Functions                   //
	void parse(const char* filename);
	void print( FILE* fp = stdout );
private:
	//------------------------------------------------------//
	//                     File Structure                   //
	struct Header{
		int32_t fileCode;
		int32_t unused[5];
		int32_t fileLength;
		int32_t version;
		int32_t shapeType;
		double  boundingBox[8];
	};
	struct RecordHeader{
		int32_t recordNumber;  //BigEndian in file
		int32_t contentLength; //in 16-bit words
	};
	struct RecordContents{
		uint32_t shapeType;
	};
private:
	//------------------------------------------------------//
	//                   Member Variables                   //
	Header header;
	RecordHeader* recordHeader;
	RecordContents* recordContents;
};

#endif
