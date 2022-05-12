#include <iostream>
#include "bb/pool.h"

int main() {
    bb::pool::obj().push([](){
        printf("test\n");
    });
    return 0;
}
