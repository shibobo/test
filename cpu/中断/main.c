#include <reg52.h>
#define uint unsigned int;
#define uchar unsigned char;
sbit led1=P1^0;
uchar num;
void main(){
   //ѡ��ʱ��0��������ʽΪ��ʽ1��TMOD��00000001H
   TMOD=0x01;
   //����TL0��TH0
   //����Ƶ��Ϊ11.0592MHzʱ����ʱ50ms������45872
   TH0=(65536-45872)/256;
   TL0=(65536-45872)%256;
   EA=1;//�����ж�
   ET0=1;//����ʱ��0�ж�
   TR0=1;//������ʱ��0
   while(1){//������е�����ʱ��ȴ��ж�
	   if(num==20){
	      num=0;
         //ȡ����led1��
		   led1=~led1;
	   }   
   }
}
void T0_time() interrupt 1{
   //��װ��ֵ
   TH0=(65536-45872)/256;
   TL0=(65536-45872)%256;
   num++;   
}
