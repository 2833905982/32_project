									注         解
线圈电压：XQ   	    GPIO      C0
电容电压：DR			GPIO      C1
电流电压：DL       	GPIO	  C2
功率：PP


//关于PWM的刹车功能，由B12引脚控制，高电平实现停止PWM

//B12，由GPIO口控制实现刹车功能，B12连B0,

//改变原来的PWM输出，由普通定时器实现输出PWM，由B0引脚输出

电流 = DL/2*5/20/0.02