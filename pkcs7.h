//
//  pkcs7.h
//  AES
//
//  Created by 史寿伟 on 2018/1/28.
//  Copyright © 2018年 史寿伟. All rights reserved.
//

#ifndef pkcs7_h
#define pkcs7_h

#include <stdio.h>
size_t padding(uint8_t * in, size_t len);
size_t inv_padding(uint8_t * in, size_t len);

#endif /* pkcs7_h */
