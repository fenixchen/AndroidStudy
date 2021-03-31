#include <stdio.h>
#include <utils/RefBase.h>

using namespace android;

void test_light_ref_base();
void test_sp();
void test_wp();
void test_cycle_ref();

int main() {
  test_light_ref_base();
  test_sp();
  test_wp();
  test_cycle_ref();
  return 0;
}
