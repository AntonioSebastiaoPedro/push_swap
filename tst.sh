#!/bin/bash

# Cria um array com números de 0 a 99
numeros=($(seq 0 99))

# Função para embaralhar o array
embaralhar() {
  local i tmp tamanho max_rand
  tamanho=${#numeros[@]}
  max_rand=$((32768 / tamanho * tamanho))
  
  for ((i = tamanho - 1; i > 0; i--)); do
    while (( (rand=$RANDOM) >= max_rand )); do :; done
    rand=$((rand % (i + 1)))
    tmp=${numeros[i]}
    numeros[i]=${numeros[rand]}
    numeros[rand]=$tmp
  done
}

# Embaralha o array
embaralhar

# Imprime a sequência embaralhada
echo "${numeros[@]}"
