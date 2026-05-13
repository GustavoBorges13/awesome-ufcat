#include <lib.h>
#define mycall _mycall
#include <unistd.h>

int mycall() {
  message m;
  return (_syscall(PM_PROC_NR, MYCALL, &m));
}
