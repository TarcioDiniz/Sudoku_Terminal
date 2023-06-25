cmake_minimum_required(VERSION 3.25)
project(Sudoku C)

set(CMAKE_C_STANDARD 11)

# Adicione os arquivos de cabeçalho e fonte em uma biblioteca
add_library(sudoku_lib
        src/criador.c
        src/solucionador.c
        src/historico.c
        src/game_dao.c)

# Defina os caminhos de inclusão para os arquivos de cabeçalho
target_include_directories(sudoku_lib PUBLIC include)

# Crie o executável e vincule a biblioteca
add_executable(gerador_sudoku main.c)
target_link_libraries(gerador_sudoku sudoku_lib)
