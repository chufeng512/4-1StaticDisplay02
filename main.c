#include <STC89C5xRC.H>
//增加自定义类型，简化代码编写
typedef unsigned char u8;
typedef unsigned int u16;

//需求：静态数码管显示,让第四个数码管显示5
//手册信息：DIG5对应Y4,P15 P14 P13 1 0 0
//封装显示状态

u8 NixieTable[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

//数码管显示
void NixieDisPlay(u8 Location,DisplayNum)
{
	switch(Location)
	{
		case 1:P15 = 0;P14 = 0;P13 = 0;break;
		case 2:P15 = 0;P14 = 0;P13 = 1;break;
		case 3:P15 = 0;P14 = 1;P13 = 0;break;
		case 4:P15 = 0;P14 = 1;P13 = 1;break;
		case 5:P15 = 1;P14 = 0;P13 = 0;break;
		case 6:P15 = 1;P14 = 0;P13 = 1;break;
		case 7:P15 = 1;P14 = 1;P13 = 0;break;
		case 8:P15 = 1;P14 = 1;P13 = 1;break;
	}
	P0 = NixieTable[DisplayNum];
}

void main()
{

	NixieDisPlay(4,8);
	while(1)
	{
	}
}