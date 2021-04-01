#include <stdio.h>

#include <string>

#include "person.pb.h"

using namespace std;

int main() {
  string str;
  Person p;
  p.set_name("hello");
  p.set_id(0x11003344);
  p.set_email("a@b.com");
  str = p.SerializeAsString();
  printf("str:(%ld): %s\n", str.length(), str.c_str());
  for (int i = 0; i < str.length(); i++) {
    printf("%02X ", (unsigned char)str.c_str()[i]);
  }
  printf("\n");
  return 0;
}
