# Jogo_batalha_Naval
Projeto: Batalha Naval em C  

Este projeto é um jogo simplificado de Batalha Naval desenvolvido em linguagem C, criado como sequência de exercícios que evoluem do nível iniciante ao avançado. Cada exercício adiciona complexidade, desde posicionamento básico de navios até implementação de habilidades especiais com áreas de efeito.

O código foi desenvolvido com foco em arrays, loops aninhados, condicionais e boa organização de código.

Nível Novato: Posicionando Navios no Tabuleiro

Objetivo:
Dar os primeiros passos na construção do jogo, utilizando vetores e matrizes para representar um tabuleiro 10x10 e posicionar navios horizontal e verticalmente.

Funcionalidades:

Criação de uma matriz 10x10 representando o tabuleiro, inicializada com 0 (água).

Posicionamento de dois navios de tamanho fixo (3 posições cada):

Um navio horizontal

Um navio vertical

Garantia de que os navios fiquem dentro dos limites do tabuleiro.

Exibição do tabuleiro no console com 0 para água e 3 para navios.

Aprendizado:

Uso de arrays bidimensionais

Loops aninhados

Manipulação de coordenadas para posicionamento de elementos

Nível Intermediário: Tabuleiro Completo e Navios Diagonais

Objetivo:
Aumentar a complexidade adicionando navios diagonais ao tabuleiro.

Funcionalidades:

Criação do tabuleiro 10x10, inicializado com água (0).

Posicionamento de quatro navios de tamanho 3:

Dois horizontais ou verticais (como no nível anterior)

Dois diagonais:

Diagonal ↘ (linha +, coluna +)

Diagonal ↙ (linha +, coluna -)

Validação simplificada de limites para evitar que os navios saiam do tabuleiro.

Garantia de que os navios não se sobreponham.

Exibição do tabuleiro completo, permitindo visualizar facilmente a posição de todos os navios.

Aprendizado:

Lógica para navios diagonais

Maior controle sobre índices de matrizes

Continuação do uso de loops aninhados

Nível Avançado: Habilidades Especiais e Áreas de Efeito

Objetivo:
Adicionar estratégia ao jogo implementando habilidades especiais com áreas de efeito, visualizadas diretamente no tabuleiro.

Funcionalidades:

Criação de matrizes de habilidade 5x5 para representar diferentes efeitos:

CONE: área em forma de cone apontando para baixo

CRUZ: área em forma de cruz, centrada no ponto de origem

OCTAEDRO: área em forma de losango (vista frontal)

Definição de pontos de origem para cada habilidade no tabuleiro.

Sobreposição das matrizes de habilidade no tabuleiro, marcando as áreas afetadas com valor 5.

Preservação da visualização de navios (3) quando uma área de efeito se sobrepõe a eles.

Impressão final do tabuleiro, mostrando:

0 → água

3 → navio

5 → área afetada por habilidade

Aprendizado:

Criação dinâmica de matrizes de habilidades usando loops e condicionais

Sobreposição de matrizes (área de efeito) sobre outra matriz (tabuleiro)

Controle de limites do tabuleiro durante a sobreposição

Estratégia e visualização de áreas de efeito

Observações Gerais

Todos os exercícios foram desenvolvidos sem entrada de usuário, com coordenadas e tamanhos fixos definidos diretamente no código.

O projeto foca na organização de código, legibilidade e comentários explicativos para cada etapa.

Pode ser expandido futuramente para incluir ataques, acertos e pontuação, transformando-o em um jogo completo de Batalha Naval.