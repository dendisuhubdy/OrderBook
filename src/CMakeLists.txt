set(TEST_SRCS
    orderbook.cpp
    engine.cpp
    test.cpp)
set(SCORE_SRCS
    orderbook.cpp
    engine.cpp
    score.cpp)

add_executable(test
            ${TEST_SRCS})
add_executable(score
            ${SCORE_SRCS})
