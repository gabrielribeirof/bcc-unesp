Compilar: gcc main.c operations.c -o program

Escurecer:
  ./program --darken <p>
  ./program -d <p>

Clarear:
  ./program --brighten <p>
  ./program -b <p>

Negativo:
  ./program -n

Rotacionar 90 graus:
  ./program --rotate90

Rotacionar 180 graus:
  ./program --rotate180

Rotacionar 270 graus:
  ./program --rotate270

Espelhar horizontalmente:
  ./program -h
  ./program -mirrorh

Espelhar verticalmente:
  ./program -v
  ./program -mirrorv

Binarização:
  ./program -i <k>
  ./program --binarization <k>

Nível médio de cinza:
  ./program -g <l>
  ./program --middleGrayLevel <l>