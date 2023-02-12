cmake_minimum_required(VERSION 3.14)

set(This InputTests) # Variável This com conteúdo "InputTests"

# Variável Sources que irá conter os arquivos .cpp com os testes
set(Sources
        InputTests.cpp # arquivo que criaremos posteriormente com os nossos testes unitários
)

# Comando para adicionar executável com o nome "InputTests" a partir dos arquivos .cpp listados em Sources
add_executable(${This} ${Sources})

# Listagem das bibilotecas que serão linkadas na criação do executável
target_link_libraries(${This} PUBLIC
    GTest::gtest_main # Biblioteca padrão do framework GoogleTest
    UnitTesting # Essa é a biblioteca que criamos no primeiro CMakeLists.txt
)

# Adicionamos o teste de nome "InputTests" utilizando o executável que criamos na linha 11
add_test(
        NAME ${This}
        COMMAND ${This}
)
