#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int* s (int *a, int *b, int N, int M)
{
    int *c;
    c=(int *) malloc((N + M)*sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < N && j < M)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < N)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < M)
    {
        c[k] = b[j];
        j++;
        k++;
    }
    return c;
}


int main()
{

    setlocale(LC_ALL,"Rus");

    int *a,*b,*res,i,n,m,j,tmp;
    printf("Кол-во элементов массива n\n");

    scanf("%d", &n);
    a=(int*) malloc(n*sizeof(int));
    printf("Элементы массива n\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Кол-во элементов m \n");

    scanf("%d", &m);
    b=(int*) malloc(m*sizeof(int));
    printf("Элементы массива m\n");

    for (i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    res=s(a,b,n,m);
    for(i = 0;i <(n+m)-1;i++)
	{
		for (j = i + 1;j < n+m;j++)
		{
			if (res[i] > res[j])
			{
				tmp  = res[i];
				res[i] = res[j];
				res[j] = tmp;
            }
		}
	}
    printf("Объединённый массив :\n");
	for(i = 0;i <n+m;i++)
    {
		printf("\t%d",res[i]);
    }

    return 0;
}

