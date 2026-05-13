#!/bin/bash
j=$2
i=0
while [ $i -lt $j ]
do
  echo "Execução numero $i"
  ./$1
  echo "---------------------------"
  ((i++))
done
