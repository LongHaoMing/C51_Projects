/*****************************************************************
��������������ˮ�ƣ��������ͣ�����

��д�ߣ������ 

ʱ�䣺2015.7.26
										   
ʹ��˵��������Ƭ����P0���öŰ���������ˮ�Ʋ��J48��P00��D0��P07��D7��

********************************************************************/
#include<reg52.h>
#define uchar  unsigned char
#define uint  unsigned int
#define led  P0		   //������ˮ�ƿ���
sbit buzzer=P3^0;

/********************************************************/
//��������  void delay(uint xms)
//���ܣ�    ��ʱʱ��Ϊ1ms
//���ú�����
//���������xms,1ms����
//���������
//˵�����ܹ���ʱʱ��Ϊ1ms����xms,crystal=12Mhz
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
//������ˮ�Ƶ����飻
//����������Ȼ����ҵ���
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
 

/*************** ������ ******************/
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
			    delay(100);		//������ʱ��������ʱ1S
		      buzzer=1;
			    delay(100);
		  }
	}
}