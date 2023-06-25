# Sudoku

O Sudoku é um jogo de lógica em que o objetivo é preencher uma grade 9x9 com números de 1 a 9, de forma que cada linha, coluna e região 3x3 contenha todos os números de 1 a 9 sem repetições.

## Como Jogar

O programa gera um jogo de Sudoku aleatório e exibe a grade na saída. Para compilar e executar o programa, siga as instruções abaixo:

### Pré-requisitos

Antes de compilar e executar o programa, certifique-se de ter os seguintes itens instalados em seu sistema:

- Compilador GCC
- Git (caso queira clonar o repositório)

### Compilação e Execução

1. Abra um terminal e navegue até o diretório raiz do projeto.

2. Clone o repositório (caso ainda não tenha feito isso) com o seguinte comando:

   ```bash
   git clone https://github.com/TarcioDiniz/Sudoku_Terminal.git
   ```

3. Navegue até o diretório do projeto:

   ```bash
   cd Sudoku_Terminal
   ```

4. Execute o seguinte comando para compilar o programa:

   ```bash
   # Linux
   build_linux.sh
   ```
   ```bash
   # macOS
   build_mac.sh 
   ```
   ```bash
   # Windows
   build_windows.bat
   ```
   

   O comando acima irá compilar o programa e gerar o arquivo executável.

5. Após a compilação, execute o programa com o seguinte comando:

   ```bash
   ./gerador_sudoku  # ou gerador_sudoku.exe no Windows
   ```

6. O programa irá gerar um jogo de Sudoku aleatório e exibir a grade na saída. Os espaços vazios são representados por zeros (0).

   Exemplo de saída:

   ```
   5 3 0 | 0 7 0 | 0 0 0
   6 0 0 | 1 9 5 | 0 0 0
   0 9 8 | 0 0 0 | 0 6 0
   ------+-------+------
   8 0 0 | 0 6 0 | 0 0 3
   4 0 0 | 8 0 3 | 0 0 1
   7 0 0 | 0 2 0 | 0 0 6
   ------+-------+------
   0 6 0 | 0 0 0 | 2 8 0
   0 0 0 | 4 1 9 | 0 0 5
   0 0 0 | 0 8 0 | 0 7 9
   ```

7. Agora você pode resolver o Sudoku ou utilizar a grade gerada para jogar.

## Contribuição

Contribuições são bem-vindas! Se você encontrar algum problema ou tiver sugestões de melhoria, sinta-se à vontade para abrir uma issue ou enviar um pull request.

## Licença

Este projeto está licenciado sob a licença [MIT](LICENSE).

Espero que este guia de compilação e o resumo do jogo de Sudoku sejam úteis! Divirta-se jogando e gerando jogos de Sudoku com o

 programa!
