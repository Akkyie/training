#include <assert.h>
#include "akkyie-list.h"

#define TEST_SIZE 1024

int main(int argc, char const* argv[]) {
    List *queue = list_create();
    List *stack = list_create();
    int i, popped;
    bool result;

    for(i = 0; i < TEST_SIZE; ++i) {
        list_push(queue, i);
        list_push(stack, i);
    }

    for(i = 0; i < TEST_SIZE; ++i) {
        result = list_shift(queue, &popped);
        assert(result);
        assert(popped == i);
        result = list_pop(stack, &popped);
        assert(result);
        assert(popped == TEST_SIZE - 1 - i);
    }

    assert(!list_shift(queue, &popped));
    assert(!list_pop(stack, &popped));

    list_delete(queue);
    list_delete(stack);

    return EXIT_SUCCESS;
}
