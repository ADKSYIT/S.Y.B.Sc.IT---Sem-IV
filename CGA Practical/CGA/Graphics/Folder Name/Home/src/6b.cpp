#include<stdio.h>

int main()
{
    int i,j,x,y;
    int arr[3][3],trans[3][3],result[3][3];
    
    // Input the 3x3 matrix to be translated
    printf("Enter a 3x3 matrix to be translated:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    // Input the translation values for x and y
    printf("Enter the translation values for x and y:\n");
    scanf("%d %d",&x,&y);
    
    // Initialize the translation matrix
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i==j)
                trans[i][j] = 1;
            else
                trans[i][j] = 0;
        }
    }
    
    // Set the translation values in the translation matrix
    trans[0][2] = x;
    trans[1][2] = y;
    
    // Multiply the translation matrix and the input matrix to get the result matrix
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            result[i][j] = 0;
            for(int k=0;k<3;k++)
            {
                result[i][j] += trans[i][k]*arr[k][j];
            }
        }
    }
    
    // Output the result matrix
    printf("\nTranslated matrix:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
