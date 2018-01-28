//
//  main.c
//  AES
//
//  Created by 史寿伟 on 2018/1/28.
//  Copyright © 2018年 史寿伟. All rights reserved.
//

#include "pkcs7.h"
#include "cbc.h"
#include "aes.h"

int main(int argc, char *argv[]) {
    
    // 常量
    const char * KEY_123456 = "1234567890123456";
    const char * text = "abcdefg12345678901234567890f";

    // Key 和 IV
    uint8_t key[16];
    uint8_t iv [16];
    memcpy(key, KEY_123456, 16);
    memcpy(iv, KEY_123456, 16);
    
    // 扩展 key
    uint8_t w[256];
    key_expansion(key, w);
    
    // 明文和明文长度
    uint8_t in[256];
    size_t len_in = strlen(text);
    memcpy(in, text, len_in);

    // pkcs7padding
    len_in = padding(in, len_in);
    
    // 加密
    uint8_t out[256];
    size_t len_out;
    for(len_out=0; len_out<len_in; len_out += 16) {
        aes128_cbc((uint8_t*)in + len_out, out + len_out, w, iv, iv);
    }
    
    // 输出密文
    for(int i=0; i<len_out; i++) {
        printf("%02x ", out[i]);
    }
    printf("\n");
    
    // -----------------------
    
    // 接收解密内容
    uint8_t dec[256];
    size_t len_dec;
    
    // 用于解密的 IV
    uint8_t iv_dec[16];
    memcpy(iv_dec, KEY_123456, 16);
    
    for(len_dec = 0; len_dec<len_out; len_dec += 16) {
        inv_aes128_cbc(out + len_dec, dec + len_dec, w, iv_dec, iv_dec);
    }
    
    // 反向 pkcs7padding
    len_dec = inv_padding(dec, len_dec);
    
    // 输出解密内容
    for(int i=0; i<len_dec; i++) {
        printf("%02x ", dec[i]);
    }
    printf("\n");
    
    dec[len_dec] = 0;
    printf("%s\n", dec);
    
}

