char value[]={0x10,0x20,0x40,0x80};
	char posi[]={PC4,PC5,PC6,PC7};
void lcd_write(char a){
	char x;
	int i;
	for(i=0;i<=3;i++){
		x=a & value[i];
		if(x!=0)
		{
			PORTC|=1<<posi[i];
		}
		else
		PORTC&=~(1<<posi[i]);
	}
	
	PORTC|=1<<PC0;
	PORTC|=1<<PC2;
	_delay_ms(5);
	PORTC&=~(1<<PC2);
	
	for (i=0;i<=3;i++)
	{
		x=(a<<4) & value[i];
		if (x!=0)
		{
			PORTC|=1<<posi[i];
		}
		
		else
		PORTC&=~(1<<posi[i]);
	}
	
	PORTC|=1<<PC0;
	PORTC|=1<<PC2;
	_delay_ms(5);
	PORTC&=~(1<<PC2);
}

void lcd_comm(char a){
	char x;
	int i;
	for(i=0;i<=3;i++){
		x=a & value[i];
		if(x!=0)
		{
			PORTC|=1<<posi[i];
		}
		else
		PORTC&=~(1<<posi[i]);
	}
	
	PORTC&=~(1<<PC0);
	PORTC|=1<<PC2;
	_delay_ms(5);
	PORTC&=~(1<<PC2);
	
	for (i=0;i<=3;i++)
	{
		x=(a<<4) & value[i];
		if (x!=0)
		{
			PORTC|=1<<posi[i];
		}
		
		else
		PORTC&=~(1<<posi[i]);
	}
	
	PORTC&=~(1<<PC0);
	PORTC|=1<<PC2;
	_delay_ms(5);
	PORTC&=~(1<<PC2);
}

void lcd_init()
{

DDRC=0xFF;
PORTC&=~(1<<1);
	lcd_comm(0x02);
	lcd_comm(0x28);
	lcd_comm(0x06);
	lcd_comm(0x0C);
	lcd_comm(0x80);
	lcd_comm(0x01);
}

//to print string
void lcd_string(char *q)
{
	while(*q!='\0')
	{
		lcd_write(*q);
		q++;
	}
}

void lcd_number(unsigned int x)
{
	unsigned int n=0,i,d=1, temp;
	/*if(x==0)
	lcd_write(48);
	
	
	else*/
	{
		temp=x;
		while(x!=0)
		{
			x/=10;
			n++;
		}
		
		for(i=0;i<n-1;i++)
		{
			d*=10;
		}
		
		for(i=0;i<n;i++)
		{
			lcd_write((temp/d)+48);
			temp%=d;
			d/=10;
			
		}
		
	}
}