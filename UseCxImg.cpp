//////////////////////////////////////////////////////////////////////////
//// How to use CxImage. By Leo Yang Liu. leoyonn@gmail.com			//////
//////////////////////////////////////////////////////////////////////////

/*
	First, 3 kinds of files are needed:
	<xinclude>
	cximagecrt.dll / cximagecrtd.dll
	cximagecrt.lib / cximgecrtd.lib

	put <xinclude> , cximagecrt.lib / cximgecrtd.lib into the project's root dir.
	put cximagecrt.dll into ./release dir, and put cximagecrtd.dll into ./debug dir.

*/

//	then add the head file to the project:
#include "xinclude/ximage.h"

//	then add the linkable lib into the project:
#ifdef   _DEBUG   
	#pragma   comment(lib, "cximagecrtd.lib")
#else   
	#pragma   comment(lib, "cximagecrt.lib")   
#endif  


#define IMG_SIZE 128
// assume you get an 128 x 128 size array
unsigned char data[IMG_SIZE * IMG_SIZE];

void main()
{
	// Put something into the array(in this case, a big stroke)
	memset(data, 255, sizeof(unsigned char) * IMG_SIZE * IMG_SIZE);
	int i, j;
	for(i = 10; i < 110; i ++)
	{
		for(j = 50; j < 80; j ++)
		{
			data[i * IMG_SIZE + j] = 0;
		}
	}

	// here you can use CxImage:
	CxImage cMyImg;
	cMyImg.CreateFromArray(data, IMG_SIZE, IMG_SIZE, 8, IMG_SIZE, false);
	cMyImg.Save("E:/test_stroke.bmp", CXIMAGE_FORMAT_BMP);
}