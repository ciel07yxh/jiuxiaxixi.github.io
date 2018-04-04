/****************************************Copyright (c)****************************************************
**
**                          一切为理想而作，打造嵌入式WEB节省资源的最优化应用
**
**
**--------------File Info---------------------------------------------------------------------------------
** File Name:           stringExt.c
** Last modified Date:  2008.11.22
** Last Version:        v1.0
** Description:         标准C语言中一些字符串处理函数的扩充的
** 
**--------------------------------------------------------------------------------------------------------
** Created By:          任海波
** Created date:        2008.11.22
** Version:             v1.0
** Descriptions:        The original version 初始版本
**
**--------------------------------------------------------------------------------------------------------
** Modified by:         
** Modified date:       
** Version:             
** Description:         
**
*********************************************************************************************************/

#include    "stringExt.h"

/*********************************************************************************************************
** Function name:       strcatExt
** Descriptions:        标准C中函数strcat()的扩充
** input parameters:    pDest:   指定接受区的指针
**                      ulDestLen：指定接收区的长度(以字节为单位)
**                      pbSrc：  指定追加源字符串的指针
**                      ulSrcLen：追加源字符串的长度(以字节为单位)
** output parameters:   pbDest：追加目的字符串的指针
** Returned value:      追加后的字符串地址
** Created by:          任海波
** Created Date:        2008.11.22
**--------------------------------------------------------------------------------------------------------
** Modified by:         
** Modified date:       
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
unsigned char *strcatExt(unsigned char *pDest, unsigned long ulDestLen, 
                       const unsigned char *pSrc, unsigned long ulSrcLen)
{
    unsigned char    *__pbStartAddr;
    unsigned char    *__pbEndAddr;
    unsigned long    i;

    //* 首先找到被追加的开始地址，如果结束地址已经到了接收缓冲区的尾部则不再追加
    __pbStartAddr = pDest + strlenExt(pDest);
    __pbEndAddr = pDest + ulDestLen;
    i = 0;
    while((__pbStartAddr + i) < __pbEndAddr && i < ulSrcLen)
    {
        *(__pbStartAddr + i) = *(pSrc + i);
        i++;
    }
    
    return pDest;
}


/*********************************************************************************************************
** Function name:       strlenExt
** Descriptions:        标准C中函数strlen()的扩充
** input parameters:    pSrc：指向一个字符串的指针
** output parameters:   无
** Returned value:      字符串的长度，为一个unsigned long型的数据
** Created by:          任海波
** Created Date:        2008.11.22
**--------------------------------------------------------------------------------------------------------
** Modified by:         
** Modified date:       
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
unsigned long strlenExt(const unsigned char *pucSrc)
{
    unsigned long     i = 0;
    
    while(*(pucSrc+i) != '\0')
        i++;
        
    return i;
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/


