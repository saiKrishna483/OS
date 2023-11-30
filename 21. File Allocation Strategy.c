#include <stdio.h>
#include <stdlib.h>

struct block
{
    int data;
    struct block *next;
};

int main()
{
    int i, n, j, k, m, st, len, c, a[50], t;
    struct block *start, *temp, *newnode;

    start = NULL;

    printf("Enter the number of files: ");
    scanf("%d", &n);

    printf("Enter the starting block and length of each file: \n");
    for (i = 1; i <= n; i++)
    {
        printf("File %d:\n", i);
        scanf("%d%d", &st, &len);
        for (j = 1; j <= len; j++)
        {
            newnode = (struct block *)malloc(sizeof(struct block));
            newnode->data = st;
            newnode->next = NULL;
            if (start == NULL)
            {
                start = newnode;
                temp = newnode;
            }
            else
            {
                temp->next = newnode;
                temp = newnode;
            }
            st++;
        }
    }

    printf("\nLinked list representation of the files:\n");
    temp = start;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
