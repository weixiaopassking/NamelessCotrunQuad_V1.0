#include "Headfile.h"
/*----------------------------------------------------------------------------------------------------------------------/
        *               ������ֻ��������ѧϰʹ�ã���Ȩ����Ȩ���������ƴ��Ŷӣ�
        *               �����ƴ��Ŷӽ��ɿس���Դ���ṩ�������ߣ�
        *               ������ҪΪ�����ƴ��Ŷ��ṩ������
        *               δ���������ɣ����ý�Դ�����ṩ������
        *               ���ý�Դ����ŵ����Ϲ�����������أ�
        *               �������Դ�����Ĳ�����緢��������Ϊ��
        *               �����ƴ��Ŷӽ���֮�Է��ɽ��������
-----------------------------------------------------------------------------------------------------------------------/
        *               ������Ϣ���ܶ���ֹ��ǰ�����������˳���������
        *               ��Դ���ף���ѧ����ϧ��ף������Ϯ�����׳ɹ�������
-----------------------------------------------------------------------------------------------------------------------/
        *		�����ƴ���Դ�ɿ� V1.1	�人�Ƽ���ѧ  By.YuYi
        *		CSDN����: http://blog.csdn.net/u011992534
        *               �ſ�ID��NamelessCotrun����С��
        *               �����ƴ���Դ�ɿ�QQȺ��540707961
        *               https://shop348646912.taobao.com/?spm=2013.1.1000126.2.5ce78a88ht1sO2
        *               �ٶ�����:�����ƴ���Դ�ɿ�
        *               �޸�����:2017/10/30
        *               �汾��V1.1
        *               ��Ȩ���У�����ؾ���
        *               Copyright(C) �人�Ƽ���ѧ�����ƴ��Ŷ� 2017-2019
        *               All rights reserved
----------------------------------------------------------------------------------------------------------------------*/


/*************************************************************************************************************************
//----------------------------------------------------------------------------------------------------------------------//
	*		�������������ɿذ�V1.0	�人�Ƽ���ѧ  By.YuYi
	*		CSDN����: http://blog.csdn.net/u011992534
	*               �ſ�ID��NamelessCotrun����С��
	*               �����ƴ���Դ�ɿ�QQȺ��540707961
        *               https://shop348646912.taobao.com/?spm=2013.1.1000126.2.5ce78a88ht1sO2
	*		MCU: 	STM32F103RCT6  72MHz
	*		�ӿ�ӳ���:
	*		Ĭ��IMU(MPU6050 + IST8310 + SPL06_001):
	*				IMU_SCL						-->	PB6
	*				IMU_SDA						-->	PB7
	*		OLED:
	*				OLED_D0						-->	PC3
	*				OLED_D1						-->	PC2
	*				OLED_RST					-->	PC1
	*				OLED_DC						-->	PC0
	*				OLED_CS						-->	GND
	*		������:
	*				MOTOR1						-->	PB1	-->	TIM3_CH1
	*				MOTOR2						-->	PB0	-->	TIM3_CH2
	*				MOTOR3						-->	PA7	-->	TIM3_CH3
	*				MOTOR4						-->	PA6	-->	TIM3_CH4
	*		RC����:
	*				PPM�ź�					        -->	PA8	-->	TIM1_CH1
	*				SBUS�ź�					-->	PB11-->	USART3_RX
	*		������:
	*				TRIG						-->	PB9  TRIG
	*				ECHO						-->	PA1  IO4
	*		����:
	*				S1						-->	PC8
	*				S2						-->	PC9
	*		LEDָʾ��:
	*				LED2(Green)			                -->	PA5
	*				LED3(Blue)				        -->	PC10
	*				LED4(Yellow)			                -->	PC5
	*				LED5(Red)			                -->	PC4
	*		SPI(Extended,3.3V)    ������ң����  &  ������ģ��  MPU6500+HMC5983+MS5611
	*				SPI2_IRQ				        -->	PB12
	*				SPI2_SCK				        -->	PB13
	*				SPI2_MISO				        -->	PB14
	*				SPI2_MOSI				        -->	PB15
	*				SPI2_CE				          -->	PC6
	*				SPI2_CSN				        -->	PC7
	*		USART1(Wireless,3.3V)   ɽ��๦�ܵ�������  &  Mavlink
	*				USART1_TX				        -->	PA9
	*				USART1_RX				        -->	PA10
	*		USART2(Extended,5V)    ���GPS
	*				USART2_TX				        -->	PA2
	*				USART2_RX				        -->	PA3
	*		USART3(Extended,3.3V)  ���ô���  ANO��λ����ң����SBUS�ź�����
	*				USART3_TX				        -->	PB10
	*				USART3_RX				        -->	PB11
	*		Ԥ��IO��
	*				IO1				              -->	PC13
	*				IO2				              -->	PC14
	*				IO3				              -->	PC15
	*				IO4				              -->	PA1
************************************************************************************************************************/
/***************************While(1)����ֻ���а�������ʾ���궨�ȳ���****************************************************/
/***************************��Ҫ���ģ��������˲�����̬���㡢�ߵ������Ƶȴ�����TIME.c��������**********************************/

/****************************IAR�������أ��ٶ������ӣ�https://pan.baidu.com/s/1bpe0mZ1
/***************************���ò�������ӭ���ͣ���С����ȸ��棺֧�����˺ţ�1094744141@qq.com*********************************/
int main()
{
  HardWave_Init();//�ɿذ��ڲ���Դ����������ʼ��
  delay_ms(500);
  while(1)
  {
    Key_Scan();//����ɨ��
    QuadShow();//��ʾ����ʼ��
    Accel_Calibartion();//���ٶȼƱ궨
    Mag_Calibartion(DataMag,Yaw_Correct);//�����Ʊ궨
  }
}
/***************************���ò�������ӭ���ͣ���С����ȸ��棺֧�����˺ţ�1094744141@qq.com*********************************/