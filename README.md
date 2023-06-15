# Projeto Programação Orientada a Objeto

Nesse projeto foi desenvolvido um jogo UNO em C++ na interface do Qt Creator, com objetivo de trabalhar conceitos práticos da programação orientada a objetos. O primeiro passo do desenvolvimento do projeto foi o planejamento com base nos conceitos de UML a partir de um diagrama de classes seguindo as regras do UNO e também levando em consideração como foi pensado inicialmente a implementação do jogo. Lembrando que isso é apenas o planejamento inicial do projeto e que alterações foram feitas

# Diagrama de Classes



# Regras do Jogo

o jogo foi baseado nas regras tradicionais do jogo UNO com algumas alterações para facilitar a implementação

- O jogo é jogado com um baralho especial de cartas Uno.
    - cartas de 0 a 9 nas cores Vermelho, Amarelo, Azul e Verde.<br>
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/0_vermelho.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/1_vermelho.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/2_vermelho.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/3_vermelho.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/4_vermelho.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/5_vermelho.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/6_vermelho.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/7_vermelho.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/8_vermelho.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/9_vermelho.png) <br>
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/0_amarelo.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/1_amarelo.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/2_amarelo.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/3_amarelo.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/4_amarelo.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/5_amarelo.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/6_amarelo.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/7_amarelo.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/8_amarelo.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/9_amarelo.png) <br>
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/0_azul.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/1_azul.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/2_azul.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/3_azul.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/4_azul.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/5_azul.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/6_azul.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/7_azul.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/8_azul.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/9_azul.png) <br>
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/0_verde.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/1_verde.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/2_verde.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/3_verde.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/4_verde.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/5_verde.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/6_verde.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/7_verde.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/8_verde.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/9_verde.png)
    - cartas especiais REVERSO, BLOQUEIO E MAIS_2 também nas cores Vermelho, Amarelo, Azul e Verde.<br>
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/reverse_vermelho.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/bloqueio_vermelho.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/mais2_vermelho.png) <br>
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/reverse_amarelo.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/bloqueio_amarelo.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/mais2_amarelo.png) <br>
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/reverse_azul.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/bloqueio_azul.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/mais2_azul.png) <br>
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/reverse_verde.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/bloqueio_verde.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/mais2_verde.png) <br>
    - castas especiais WILD MAIS_4 sem cor definida<br>
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/mais4.png)
    ![alt text](https://github.com/pedrohharenza/Projeto_Prog_Orientada_Obj/blob/main/Projeto_Orientada/img/wild_card.png) <br>
    
- O objetivo do jogo é se livrar de todas as suas cartas antes dos outros jogadores.
- O jogo começa com cada jogador recebendo 7 cartas. O restante das cartas forma o "deck" no centro da mesa, com a carta de topo virada para cima e colocada na mesa.
- O jogador 1 começa o jogo.
- Na sua vez, você deve jogar uma carta que corresponda à cor ou ao número da carta no topo do monte. Por exemplo, se a carta no topo for um "7 vermelho", você pode jogar qualquer carta vermelha ou qualquer carta com o número 7.
- Se você não tiver uma carta jogável, você deve comprar uma carta do monte. Se essa carta for jogável, você pode jogá-la imediatamente, caso contrário, você deve comprar até que tenha uma carta jogável.
- Existem cartas especiais com ações especiais:
  - Cartas de "REVERSO" mudam a direção do jogo.
  - Cartas de "BLOQUEAR" fazem com que o próximo jogador seja "pulado".
  - Cartas de "MAIS 2" obrigam o próximo jogador a comprar duas cartas.
  - Cartas de "WILD" podem ser jogadas em qualquer momento e vale como qualquer cor, o próximo jogador pode jogar uma carta de qualquer cor (diferente do uno tradicional que o próprio jogador escolhe a cor da carta WILD).
  - Cartas de "MAIS 4" obrigam o próximo jogador a comprar quatro cartas e equivalem a qualquer cor assim como a carta "WILD".
- Quando um jogador estiver prestes a ter apenas uma carta na mão, ele deve apertar no botão "Uno" para alertar os outros jogadores. Se um jogador esquecer de dizer "Uno", ele deve comprar quatro cartas como penalidade.
- O jogo continua até que um jogador se livre de todas as suas cartas. Esse jogador é declarado o vencedor da rodada e recebe pontos de acordo com as cartas que os outros jogadores ainda têm em suas mãos.
- Caso o deck acabe, o jogador com o menor número de cartas é declarado vencedor.
