#include <stdio.h>
#include <unistd.h>
#include <mylib.h>

int main() {
   int call = mycall();
   if (call == 0){
   	printf("Chamada de sistema executada com sucesso!\n");
   } else {
   	printf("Erro ao executar a chamada de sistema.\n");
   }
   return 0;
}

