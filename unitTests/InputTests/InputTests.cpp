#include <gtest/gtest.h> // Nessa linha incluímos o header do framework para utilizarmos as macros

// Nesse próximo bloco incluimos o header que contem as prototipagens das funções que iremos testar
// Caso seja uma função em C você tem que colocar o header dentro do escopo de extern "C"
// Caso seja uma função em C++, basta incluir o header normalmente

extern "C"
{
    #include "../../includes/cub3d.h" // Header que contem o protótipo de check_argc()
}

// Aqui chamamos a macro TEST, para identificar a suite de teste em que estamos (InputTests no caso)
// e o nome da bateria de tests que estamos realizando (SuccessfullArgcTest no caso)
TEST(InputTests, SucessfullArgcTest)
{
    // Nesses próximos testes utilizamos a macro EXPECT_EQ, enviamos parametro == 2 e esperamos que retorne 0
    EXPECT_EQ(check_argc(2), 1);
}

// Aqui chamaremos a macro TEST nas mesma suite, porém com o nome da bateria de testes alterado para FailArgcTest
TEST(InputTests, FailArgcTest)
{
    // Nesses próximos testes utilizamos a macro EXPECT_EQ, enviamos parametros != de 2 e esperamos que retorne 1
    EXPECT_EQ(check_argc(3), 1);
    EXPECT_EQ(check_argc(1), 1);
    EXPECT_EQ(check_argc(-10), 1);
}
