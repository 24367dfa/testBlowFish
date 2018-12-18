#include "blowfish.h"
#include <string>
#include <iostream>

int main(int argc, const char **argv)
{
  std::string keystr = "deadbeefdeadbeef";
  std::string original = "deadbeefdeadbeef";

  CBlowFish *bfc = new CBlowFish();
  unsigned char *key = (unsigned char *)keystr.c_str();
  int keybytes = static_cast<int>(keystr.size());
  bfc->Initialize(key, keybytes);

  unsigned long bfBufSize = bfc->GetOutputLength(original.size()+9);
  unsigned char *bfBuf = new unsigned char[bfBufSize];
  std::fill(bfBuf, bfBuf + bfBufSize, 0);
  original.copy(reinterpret_cast<char *>(bfBuf), original.size());

  bfc->Encode(bfBuf, bfBuf, bfBufSize-8);

  bfc->Decode(bfBuf, bfBuf, bfBufSize-8);

  std::string decoded = std::string(reinterpret_cast<char *>(bfBuf));

  delete bfc;
  delete[] bfBuf;

  std::cout << decoded << std::endl;

  return 0;
}
