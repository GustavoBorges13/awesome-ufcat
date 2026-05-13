@echo off
set /p usuario="Digite o nome de usuario (GuestEx > vboxuser):"
set /p ip="Digite o endereço IP (GuestEx > 192.168.0.110):"
set /p origem="Digite o caminho do arquivo de origem (GuestEx > /home/vboxuser/Projeto_3/):"
set /p destino="Digite o caminho de destino (HostEx > E:/):"

scp -r %usuario%@%ip%:%origem% %destino%

pause
