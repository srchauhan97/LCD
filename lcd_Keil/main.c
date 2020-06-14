#include<reg51.h>

void lcd_init(void);
void lcd_command(unsigned char a);
void lcd_data(unsigned char b);
void delay(unsigned int c);
void send_string(unsigned char *ch);

unsigned int a[10];

sbit rs=P2^0;
sbit rw=P2^1;
sbit e=P2^2;

int main()
{
	//setting ports as output
	P1=0x00;
	P2=0x00;
	lcd_init();
	delay(1);
	send_string("HI evryone");
	lcd_command(0xC0);//next line
	send_string("sushant");
	while(1);
	
}
void lcd_init()
{
	lcd_command(0x01);//clear display
	lcd_command(0x06);//shift display to right
	lcd_command(0x0C);//disp on cursor off
	lcd_command(0x38);//5*7matrix
	lcd_command(0x80);//take control to beginning
}
void lcd_command(unsigned char a)
{
	P1=a;
	rs=0;
	rw=0;
	e=1;
	delay(1);
	e=0;
}

void lcd_data(unsigned char b)
{
	P1=b;
	rs=1;
	rw=0;
	e=1;
	delay(1);
	e=0;
}
void send_string(unsigned char *ch)
{
	while(*ch != '\0')
	{
		lcd_data(*ch);
		ch++;
	}
}
void delay(unsigned int c)
{
	unsigned int b;
	for(b=0;b<1000*c;b++);
}