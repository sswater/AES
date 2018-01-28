//
//  aes.h
//  AES
//
//  Created by 史寿伟 on 2018/1/28.
//  Copyright © 2018年 史寿伟. All rights reserved.
//

#ifndef aes_h
#define aes_h

#include <stdio.h>
#include <stdlib.h>

void key_expansion(uint8_t *key, uint8_t *w);
void cipher(uint8_t *in, uint8_t *out, uint8_t *w);
void inv_cipher(uint8_t *in, uint8_t *out, uint8_t *w);

#endif /* aes_h */
