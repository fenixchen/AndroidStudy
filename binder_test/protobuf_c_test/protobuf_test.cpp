#include <stdio.h>
#include <assert.h>
#include <string>

#include "person.pb-c.h"

using namespace std;


#define BUF_SIZE 1024

static int32_t s_scores[] = {100, 95, 40, 30};


#define COMPANY_COUNT 3
int main() {  
  unsigned char buffer[BUF_SIZE];
  
  Company *companys[COMPANY_COUNT];

  Company company0 = COMPANY__INIT;
  Company company1 = COMPANY__INIT;
  Company company2 = COMPANY__INIT;
  companys[0] = &company0;
  companys[1] = &company1;
  companys[2] = &company2;  

  companys[0]->name = (char*)"Company1";
  companys[0]->salary = 10000;
  companys[0]->address = (char*)"Address1";

  companys[1]->name = (char*)"Company2";
  companys[1]->salary = 20000;
  companys[1]->address = (char*)"Address2";

  companys[2]->name = (char*)"Company3";
  companys[2]->salary = 30000;
  companys[2]->address = (char*)"Address3";    

  Person p = PERSON__INIT;  

  p.name = (char*)"Hello";
  p.id = 123;
  p.gender = GENDER__FAMALE;
  p.email = (char*)"a@b.com";
  p.scores = s_scores;
  p.n_scores = sizeof(s_scores) / sizeof(s_scores[0]);
  
  p.contact_case = PERSON__CONTACT_ADDRESS;
  p.address = (char*)"XXX Streat";

  p.n_companys = COMPANY_COUNT;
  p.companys = companys;

  unsigned int len = person__get_packed_size(&p);
  assert(len < BUF_SIZE);

  person__pack(&p, buffer);
  
  printf("packed size:%d\n ", len);

  for (int i = 0; i < len; i++) {
    printf("%02X ", buffer[i]);
  }
  printf("\n");
  
  Person *p2 = person__unpack(NULL, len, buffer);
  printf("name:%s\n", p2->name);
  printf("gender:%s\n", p2->gender == GENDER__FAMALE ? "FAMALE" : "MALE");
  for (int i  = 0; i < p2->n_scores; i ++){
    printf("score[%d]: %d\n", i, p2->scores[i]);
  }
  printf("contact_case:%d\n", p2->contact_case);
  printf("address:%s\n", p2->address);

  for (int i = 0; i < p2->n_companys; i ++){
    printf("Company[%d], name:%s, address:%s, salary:%d\n", i,
      p2->companys[i]->name,
      p2->companys[i]->address,
      p2->companys[i]->salary);
  }

  person__free_unpacked(p2, NULL);
  return 0;
}
