#include <iostream>
#include "MuxTs.h"
using namespace std;

int main()
{
	MuxTs m;
	cout<<m.CreateFile("test.ts");
	m.AddNewProgram(0x1000, 0x01);
	m.AddNewStream(0x101, MUXTS_CODEC_AAC);
	unsigned char *p = new unsigned char[1000];
	memset(p, 0, 1000);
	p[0] = 0xff;
	p[1] = 0xf1;
	m.WriteFrame(p, 164, 3600, MUXTS_CODEC_AAC);
	m.CloseFile();
	return 0;
}

