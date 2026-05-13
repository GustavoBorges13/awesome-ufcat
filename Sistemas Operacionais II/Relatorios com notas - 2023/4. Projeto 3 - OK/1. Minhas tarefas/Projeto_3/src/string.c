#include "string.h"

uint16 strlength(string ch)
{
  uint16 i = 1;
  while(ch[i++]);
  return --i;
}

// Adicionada no Projeto 3 - Esta funcao compara duas strings e retorna true(1) se elas forem iguais e false (8) caso contrario

uint8 strEql(string ch1, string ch2)
{
  uint8 result = 1;
  uint8 size = strlength(ch1);
  
  if (size != strlength(ch2))
    result = 0;
  else
  {
    for(uint8 i = 0; i <= size; i++)
      if (ch1[i] != ch2[i])
        result = 0;
  }
  
  return result;
}
