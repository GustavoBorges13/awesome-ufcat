# Se você não conseguir usar a aceleração por hardware (e.g. VirtualBox 
# 3.1.2 + Core 2 Duo + Minix 3.1.5):
#
#    *    
#    * Desabilite a aceleração 3D na tab de display ou exibir.
#    * Inicie a máquina virtual com este comando: VBoxSDL --startvm <NOME> --norawr0 --norawr3.
#    *
#    Substitua o nome de sua máquina virtual em <NOME> no comando dado.


#   O script abaixo, para Linux, recebe como entrada o nome da máquina virtual.
#   Antes de mais nada, ajuste as permissões do script com o comando: chmod 755 vbox-patch.sh
#   Para executar, basta digitar: ./vbox-patch.sh <NOME>

#!/bin/sh

EXPECTED_ARGS=1
E_BADARGS=65

if [ $# -ne $EXPECTED_ARGS ]
then
  echo "Usage: `basename $0` {arg}"
  exit $E_BADARGS
fi

VBoxSDL --startvm $1 --norawr0 --norawr3
