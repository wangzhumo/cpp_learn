#include "../includes//advance/stl_functor.h"

int main() {
    int arrays[] = {3,5,6,1};
    sortLikeCpp(arrays);
    sortTemplate(arrays);

    int arrays2[] = {3,5,6,1};
    sortFunctorTemplate(arrays2);
    return  0;
}
