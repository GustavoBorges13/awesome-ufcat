#!/bin/sh
sudo sh -c 'echo "deb [arch=amd64] http://download.virtualbox.org/virtualbox/debian bookworm contrib" > /etc/apt/sources.list.d/virtualbox.list'
wget -q https://www.virtualbox.org/download/oracle_vbox_2016.asc -O- | sudo apt-key add -
sudo apt-get update
sudo apt-get install xorriso
sudo apt-get install grub-common
sudo apt-get install grub2-common
sudo apt-get install grub-pc
sudo apt-get install gcc
sudo apt-get install nasm
sudo apt-get install virtualbox-7.0
sudo apt-get install qemu-system
sudo apt-get install gedit #opcional
