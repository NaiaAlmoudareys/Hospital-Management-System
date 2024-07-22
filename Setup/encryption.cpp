#include "encryption.h"
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <iostream>
#include <cstring>

static const unsigned char key[16] = "mysecretpassword";

std::string Encryption::encrypt(const std::string& data) {
    AES_KEY encryptKey;
    AES_set_encrypt_key(key, 128, &encryptKey);
    
    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(iv, AES_BLOCK_SIZE);

    std::string encryptedData;
    encryptedData.resize(data.size() + AES_BLOCK_SIZE);
    
    AES_cfb128_encrypt(reinterpret_cast<const unsigned char*>(data.c_str()),
                       reinterpret_cast<unsigned char*>(&encryptedData[0]),
                       data.size(), &encryptKey, iv, nullptr, AES_ENCRYPT);
    
    return std::string(reinterpret_cast<char*>(iv), AES_BLOCK_SIZE) + encryptedData;
}

std::string Encryption::decrypt(const std::string& data) {
    if (data.size() < AES_BLOCK_SIZE) {
        std::cerr << "Invalid encrypted data" << std::endl;
        return "";
    }

    AES_KEY decryptKey;
    AES_set_decrypt_key(key, 128, &decryptKey);

    unsigned char iv[AES_BLOCK_SIZE];
    memcpy(iv, data.c_str(), AES_BLOCK_SIZE);

    std::string decryptedData;
    decryptedData.resize(data.size() - AES_BLOCK_SIZE);
    
    AES_cfb128_encrypt(reinterpret_cast<const unsigned char*>(data.c_str() + AES_BLOCK_SIZE),
                       reinterpret_cast<unsigned char*>(&decryptedData[0]),
                       decryptedData.size(), &decryptKey, iv, nullptr, AES_DECRYPT);

    return decryptedData;
}
