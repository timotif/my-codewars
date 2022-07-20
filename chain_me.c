#include <stddef.h>
#include <stdio.h>

typedef int (*funcptr)(int);

int chain(int init_val, size_t length, const funcptr functions[length])
{
    int res;

    res = init_val;
    for (size_t i = 0; i < length; i++)
        res = functions[i](res);

    return (res);
}

int add10(int x)
{
    return (x + 10);
}

int mul30(int x)
{
    return (x * 30);
}

int main(void)
{
    funcptr functions[2];

    functions[0] = add10;
    functions[1] = mul30;

    printf("%d\n", functions[1](functions[0](50)));
    printf("%d\n", chain(50, 2, functions));
}
