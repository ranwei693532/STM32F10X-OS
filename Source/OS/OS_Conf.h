/*******************************************************************************
        (c) COPYRIGHT 2010-2018 by Efficient Systems, Inc.    
                          All rights reserved.
    
       This software is confidential and proprietary to Efficient 
     Systems, Inc.  No part of this software may be reproduced,    
     stored, transmitted, disclosed or used in any form or by any means
     other than as expressly provided by the written license agreement    
     between Efficient Systems and its licensee.
 FileName    : OS_Conf.h
 Author      : ranwei
 Version     : 
 Date        : 2016/1/21 16:25:42:809
 Description : 
 Others      : 
*******************************************************************************/
#ifndef __OS_CONF_H__
#define __OS_CONF_H__



/* Uncomment the next line to choose avalable period */
//#define OS_PERIOD  1000 /* 1ms */
//#define OS_PERIOD  1000000 /* 1us */
//#define OS_PERIOD 2000 /* 500us */
//#define OS_PERIOD 5000 /* 200us */
#define OS_PERIOD 10000 /* 100us */


typedef enum{
    EN_TASK_Periodic,
    EN_TASK_OneShot,
}EN_TASK_Mode_Type;

typedef void (* Task_Periodic_Func_Type)(void *arg);
typedef void (* Task_Init_Func_Type)(void);

typedef struct _Task{
    Task_Periodic_Func_Type periodicFunc;
    Task_Init_Func_Type initFunc;
    EN_TASK_Mode_Type mode;
    unsigned short period;
    unsigned short periodBackup;
    void *arg;
}Task;

#define OS_PERIOD_UNIT_1MS *OS_PERIOD/1000

#endif /* __OS_CONF_H__ */

BEGIN_OS

OS_TASK(EN_Task_ID_TEST1, test1_task, test1_Init, EN_TASK_Periodic, 500 OS_PERIOD_UNIT_1MS, 500 OS_PERIOD_UNIT_1MS, "hello test1")   
OS_TASK(EN_Task_ID_TEST2, test2_task, test2_Init, EN_TASK_Periodic, 500 OS_PERIOD_UNIT_1MS, 500 OS_PERIOD_UNIT_1MS, "ranwei")  

END_OS


/**************** (C) COPYRIGHT 2010-2018 Efficient *****END OF FILE***********/
