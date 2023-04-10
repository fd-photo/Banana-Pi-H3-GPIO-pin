#include<stdio.h>  
#include<stdlib.h>
#include<unistd.h>  
#include<sys/mman.h>  
#include<sys/types.h>  
#include<sys/stat.h>  
#include<fcntl.h> 
#include "gpio.h"  

int main(int argc, const char *argv[])
{
	if (argc < 2)
	{
		printf("error.\n");
		exit(1);
	}
	
	long steps     = atoi(argv[1]);    // argv to int
	int  direction = atoi(argv[2]);    //
	
        GPIO_Init();

	GPIO_ConfigPin(PA, 20, OUT);       // 40 banana pi
	GPIO_ConfigPin(PA, 21, OUT);       // 38 
        GPIO_ConfigPin(PA, 17, OUT);       // 37

	GPIO_SetPin(PA, 17, 0);            // enable motor
	GPIO_SetPin(PA, 21, direction);    // direction
	for (int i=0; i<steps; i++)
	{
		GPIO_SetPin(PA,20, 1);
		usleep(5);
		GPIO_SetPin(PA,20, 0);
		usleep(5);
	}
	GPIO_SetPin(PA, 17, 1); //disable motor
	return 0;	
	//GPIO_Free();
}

