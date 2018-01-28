//
//  cbc.h
//  AES
//
//  Created by 史寿伟 on 2018/1/28.
//  Copyright © 2018年 史寿伟. All rights reserved.
//

#ifndef cbc_h
#define cbc_h

#include <stdio.h>
#include <string.h>

void aes128_cbc(uint8_t *in, uint8_t *out, uint8_t *w, uint8_t * iv, uint8_t * next_iv);
void inv_aes128_cbc(uint8_t *in, uint8_t *out, uint8_t *w, uint8_t * iv, uint8_t * next_iv);

#endif /* cbc_h */
