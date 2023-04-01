/*
 * Copyright (C) 2017-2019 Alibaba Group Holding Limited
 */


/******************************************************************************
 * @file     main.c
 * @brief    hello world
 * @version  V1.0
 * @date     17. Jan 2018
 ******************************************************************************/

#include <stdio.h>

extern void mdelay(uint32_t ms);
int main(void)
{
	while(1)
	{
		printf("Hello World!\n");
		mdelay(500);
	}
    

    return 0;
}
