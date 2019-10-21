/*****************************************************************
程序名：花样流水灯（数组类型）程序

编写者：龙皓明 

时间：2015.7.26
										   
使用说明：将单片机的P0口用杜邦线连接流水灯插口J48（P00对D0，P07对D7）

********************************************************************/
#include<reg52.h>
#define uchar  unsigned char
#define uint  unsigned int
#define led  P0		   //定义流水灯口线
sbit buzzer=P3^0;

/********************************************************/
//函数名：  void delay(uint xms)
//功能：    延时时间为1ms
//调用函数：
//输入参数：xms,1ms计数
//输出参数：
//说明：总共延时时间为1ms乘以xms,crystal=12Mhz
/********************************************************/
void delay(uint xms)
{
	uchar i;
	while(xms--)
	{
		for(i=0;i<110;i++);
	}
}


/******************************************************/
//定义流水灯的数组；
//灯闪从左到右然后从右到左；
/******************************************************/
uchar code led_bus1[]={0xfe,0xfd,
	                    0xfe,0xfd,0xfb,
	                    0xfe, 0xfd,0xfb,0xf7,
	                    0xfe,0xfd,0xfb,0xf7,0xef,
	                    0xfe,0xfd,0xfb,0xf7,0xef,0xdf,
	                    0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,
	                    0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f,
	                    0x7f,0xbf,
	                    0x7f,0xbf,0xdf,
	                    0x7f,0xbf,0xdf,0xef,
	                    0x7f,0xbf,0xdf,0xef,0xf7,
	                    0x7f,0xbf,0xdf,0xef,0xf7,0xfb,
	                    0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,
	                    0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe,
					            0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f,
                      0xfe,0xfd,0xfb,0xf7,0xf7,0xfb,0xfd,0xfe,
                      0x7f,0xbf,0xdf,0xef,0xdf,0xbf,0x7f,0x00,};
 

/*************** 主函数 ******************/
main()
{
	uchar i;
	while(1)
	{ 
		  for(i=0;i<93;i++)
		  {
			    led=led_bus1[i];
			    delay(100);
			    buzzer=0;
			    delay(100);		//调用延时函数，延时1S
		      buzzer=1;
			    delay(100);
		  }
	}
}