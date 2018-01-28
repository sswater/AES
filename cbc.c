//
//  cbc.c
//  AES
//
//  Created by 史寿伟 on 2018/1/28.
//  Copyright © 2018年 史寿伟. All rights reserved.
//

#include "cbc.h"
#include "aes.h"

void aes128_cbc(uint8_t *in, uint8_t *out, uint8_t *w, uint8_t * iv, uint8_t * next_iv)
{
    uint8_t tmp[16];
    for(int i=0; i<16; i++) tmp[i] = in[i] ^ iv[i];
    cipher(tmp, out, w);
    if(next_iv != 0) memcpy(next_iv, out, 16);
}

void inv_aes128_cbc(uint8_t *in, uint8_t *out, uint8_t *w, uint8_t * iv, uint8_t * next_iv)
{
    inv_cipher(in, out, w);
    for(int i=0; i<16; i++) out[i] ^= iv[i];
    if(next_iv != 0) memcpy(next_iv, in, 16);
}
