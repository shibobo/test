#include <reg52.h>
//#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char;
//a������P1�ڸ�ֵ
uchar a;
//������ʱ����
void delayms(void);
//ʵ����ʱ����
void delayms(void){
    uint i,j;
    for(i=100;i>0;i--)
	   for(j=100;j>0;j--);
}
//������
void main(void){
    a=0xfe;
	while(1){
	  P1=a;
	  delayms();
	  //ѭ������һλ
	  a=_crol_(a,1);
	  //a=a<<1;
	}
}
