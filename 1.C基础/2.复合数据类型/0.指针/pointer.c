#include <stdio.h>
#include <string.h>
/**
 * data descp: 定义不同数据类型的枚举
 */
typedef enum
{
    TYPE_INT,
    TYPE_CHAR
} DataType;
/**
 * func descp: 通用打印数据类型版本
 */
void print_array(void *arr, int len, DataType type)
{
    if (arr == NULL || len <= 0)
        return;

    size_t elem_size = (type == TYPE_INT) ? sizeof(int) : sizeof(char);

    for (int i = 0; i < len; i++)
    {
        void *elem_ptr = (char *)arr + i * elem_size; // 按元素大小偏移

        if (type == TYPE_INT)
        {
            int value;
            memcpy(&value, elem_ptr, elem_size); // 安全复制数据
            printf("%d\t", value);
        }
        else
        {
            char value;
            memcpy(&value, elem_ptr, elem_size);
            printf("%c\t", value);
        }
    }
    printf("\n");
}
int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3};
    char arr3[6] = "hello";
    int len;
    printf("enter VLA's length:\n");
    scanf("%d", &len);
    int arr4[len];
    printf("enter VLA's element:\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr4[i]);
    }
    /**
     * data descp: 挨个打印
     */
    printf("print all:\n");
    {
        print_array(arr1, 5, TYPE_INT);
        print_array(arr2, 5, TYPE_INT);
        print_array(arr3, 5, TYPE_CHAR);
        print_array(arr4, 5, TYPE_INT);
    }
}