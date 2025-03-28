#include <stdio.h>
const char *word_set_a_1[] = {
    "an",
    "音标",
    "释义",
    NULL,
};
const char **word_set_a[] = {
    word_set_a_1,
    word_set_a_1,
    NULL,
};
const char ***lib_4[] = {
    word_set_a,
    word_set_a,
    NULL};
const char ****lib_5[] = {
    lib_4,
    lib_4,
    NULL};

int main()
{
    // 能通过编译就是正确的，记住，数组一定要往最底层赋值！不然一定会错！第一层就是线，编译器自动加了\0,我们不用管，所以我们一定要赋值到二维层面上！
    // 并在每一个维度后面加上NULL，这样才能正确的遍历！
    for (int i = 0; lib_5[i]; i++){
        for (int j = 0; lib_5[i][j]; j++){
            for (int k = 0; lib_5[i][j][k]; k++){
                for (int l = 0; lib_5[i][j][k][l]; l++){
                    for (int m = 0; lib_5[i][j][k][l][m]; m++){
                        printf("lib_5[%d][%d][%d][%d][%d]-----%c--%p\n",i,j,k,l,m,lib_5[i][j][k][l][m],&lib_5[i][j][k][l][m]);
                    }
                }
            }
        }
    }
    return 0;
}