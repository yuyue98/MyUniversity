#ifndef THEBASE64_H_
#define THEBASE64_H_

#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class Base64Encrypt
{
	public:
	    Base64Encrypt();
	    Base64Encrypt(const void *input, size_t length);
	
	    void Update(const void *input, size_t length);
	    const unsigned char *CipherText();
	    std::string GetString();
	    void Reset();
	    size_t GetSize();
	
	private:
	    Base64Encrypt(const Base64Encrypt &) = delete;
	    Base64Encrypt & operator = (const Base64Encrypt &) = delete;
	
	    void Encode();
	    void Final();
	
	private:
	    std::vector<unsigned char> _buf;
	    unsigned char _group[3];
	    int _groupLength;
	
	    static const unsigned char Base64EncodeMap[64];
};

class Base64Decrypt
{
	public:
	    Base64Decrypt();
	    Base64Decrypt(const void *input, size_t length);
	
	    void Update(const void *input, size_t length);
	
	    const unsigned char *PlainText();
	    void Reset();
	    size_t GetSize();
	
	private:
	    Base64Decrypt(const Base64Decrypt &) = delete;
	    Base64Decrypt & operator = (const Base64Decrypt &) = delete;
	
	    void Decode();
	
	private:
	    std::vector<unsigned char> _buf;
	    unsigned char _group[4];
	    int _groupLength;
	
	    static const unsigned char Base64DecodeMap[256];
};

#endif
