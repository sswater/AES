//
//  pkcs7.c
//  AES
//
//  Created by 史寿伟 on 2018/1/28.
//  Copyright © 2018年 史寿伟. All rights reserved.
//

#include "pkcs7.h"

size_t padding(uint8_t * in, size_t len)
{
    int p = 16 - (len % 16);
    for(size_t i=0; i<p; i++) {
        in[len++] = p;
    }
    return len;
}

size_t inv_padding(uint8_t * in, size_t len)
{
    int p = in[len - 1];
    return len - p;
}
