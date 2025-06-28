inline int min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        int x = min(3, i); // 编译器可能直接替换为 “3 < i ? 3 : i”，减少调用栈开销
        printf("%d\n", x);
    }
}