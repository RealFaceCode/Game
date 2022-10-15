#ifndef GAME_CORE_H
#define GAME_CORE_H

void FunctionTest();

#ifdef _DEBUG
    #define FUNC_TEST FunctionTest();
#else
    #define FUNC_TEST
#endif

#endif //GAME_CORE_H
