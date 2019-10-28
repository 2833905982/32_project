#include<reg52.h>

sbit input = P0^0;
sbit output = P0^1;

main()
{
	while(1)
		if (input == 1)
			output = 1;
		else
			output = 0;
}