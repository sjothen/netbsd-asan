#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sched.h>

struct Cache {
  int x;
  Cache(int x)
    : x(x) {
  }
};

void *AsyncInit(void *p) {
  return new Cache((int)(long)p);
}

Cache *CreateCache() {
  pthread_t t;
  pthread_create(&t, 0, AsyncInit, (void*)rand());
  void *res;
  pthread_join(t, &res);
  return (Cache*)res;
}

void *Thread1(void *x) {
  static Cache *c = CreateCache();
  if (c->x >= RAND_MAX)
    exit(1);
  return 0;
}

int main() {
  pthread_t t[2];
  pthread_create(&t[0], 0, Thread1, 0);
  pthread_create(&t[1], 0, Thread1, 0);
  pthread_join(t[0], 0);
  pthread_join(t[1], 0);
}

// CHECK-NOT: WARNING: ThreadSanitizer: data race
