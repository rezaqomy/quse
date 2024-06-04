#include "random.h"
random::random()
{

}

int random::getRandom(int num)
{
    std::mt19937 mt{static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count())};
    std::uniform_int_distribution<int> die6(0, num);
    return die6(mt);
}
