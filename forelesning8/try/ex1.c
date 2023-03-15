#include <stdio.h>
#include <stdarg.h>

#pragma pack(1)

typedef unsigned char UINT8; //unsigned int 8 -originally char (1 byte)
typedef unsigned short UINT16; //unsigend int 16 - originally short (2 bytes)

typedef struct _COLOR_MAP_SPECIFICATION {
	UINT16 IdxFirstColorMap; 
	UINT16 ColorMapSize; 
	UINT8  BitsPerPixel;
} COLOR_MAP_SPECIFICATION; // instead of struct COLOR_MAP_SPEC

typedef struct _IMAGE_SPECIFICATION {
	UINT16 Xorigin;
	UINT16 Yorigin;
	UINT16 Width;
	UINT16 Height;
	UINT8  BitsPerPixel;
	UINT8  ImageDescription;
} IMAGE_SPECIFICATION;

typedef struct _TGA_HEADER { //FINAL STRUCT WITH ALL INCLUDED
	UINT8 IdLenght;
	UINT8 ColorMapType;
	UINT8 ImageType;
	COLOR_MAP_SPECIFICATION ColorMapSpec; // Struct 1 
	IMAGE_SPECIFICATION ImageSpec; // Struct 2
} TGA_HEADER;

#pragma pack()

typedef unsigned char BYTE;

int main (int iArgC, char *apszArgV[]){

	FILE *fileName; 
	TGA_HEADER sHeader;
	
	//HOW TO USE 
	if (iArgC < 2){
		printf("Targa decoder: Usage ./ex1 <file_name>\n");
		return 1;
	}
	
	//If file is not found
	fileName = fopen(apszArgV[1], "rb"); //read binary
	if (fileName == NULL){
		printf("Cannot Open file %s.\n", apszArgV[1]);
		return 1;
	}
	
	//If error reading the header file
	if (fread (&sHeader, sizeof(sHeader), 1, fileName) != 1){
		fclose(fileName);
		printf("Error Reading Targa header.\n");
		return 1;
	}
	
	printf("Image width: %d (pixels).\nImage height: %d (pixels).\n", sHeader.ImageSpec.Width, sHeader.ImageSpec.Height);
	
	if (sHeader.ImageType == 0){
		printf("0: Image type??\n");
	}
	else if (sHeader.ImageType == 1){
		printf("1: Uncompressed color-mapped image.\n");
	}
	else if (sHeader.ImageType == 2){
		printf("1: Uncompressed true-color image.\n");
	}
	else if (sHeader.ImageType == 3){
		printf("1: Uncompressed black-white image.\n");
	}
	else if (sHeader.ImageType == 9){
		printf("9: RLE compressed color-mapped image.\n");
	}
	else if (sHeader.ImageType == 10){
		printf("10: RLE compressed true-color image.\n");
	}
	else if (sHeader.ImageType == 1){
		printf("11: RLE compressed black-white image.\n");
	}
	else {
		printf("Unknown image type.\n");
	}
	
	fclose(fileName);
	
	return 0;
}
