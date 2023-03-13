set(CMAKE_CXX_STANDARD 14) # Essa linha faz com que o CMake utilize C++14, que é o mínimo necessário para o framework funcionar

# Esse próximo bloco de código resgata o source code do framework diretamente do repositório dele no github.
#!!VOCÊ DEVE SUBSTITUIR O HASH DO COMMIT (LINHA 9) PELA VERSÃO MAIS ATUAL DISPONÍVEL NO GITHUB!!#

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b73f27fd164456fea9aba56163f5511355a03272.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(This UnitTesting) #Nessa linha declaramos uma variável This que contém a string "FtUnitTesting"

project(${This} C CXX) #Nessa linha listamos as linguagens que serão utilizadas, no caso C e C++

enable_testing() # Aqui fazemos com que a testagem seja habilitada dentro do CMake

# Nesse próximo bloco criaremos uma variável Headers que terá como conteúdo as bibliotecas que precisam ser linkadas para que os nossos arquivos .c compilem

set(Headers
    ../includes/cub3d.h
)

# Nesse próximo bloco criaremos uma variável Sources que terá como conteúdo os arquivos .c que contém as funções que queremos testar

set(Sources
    ../src/check_arguments.c
)

# No seguinte comando criaremos uma biblioteca (lembre da Libft!) de nome UnitTesting
# Essa biblioteca será criada com os arquivos .h e .c listados nas variáveis Headers e Sources

add_library(libft STATIC IMPORTED)
set_target_properties(libft PROPERTIES IMPORTED_LOCATION
  ${CMAKE_SOURCE_DIR}/../includes/libft/libft.a
)

add_library(${This} ${Sources} ${Headers})

# Aqui adicionaremos os subdiretórios nos quais iremos inserir os testes especificos de cada funcionalidade
# Dessa forma poderemos chamar todos os nossos testes a partir de um unico arquivo CMakeLists.txt

add_subdirectory(InputTests)
