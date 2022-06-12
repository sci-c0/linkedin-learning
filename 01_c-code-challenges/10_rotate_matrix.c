
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef
struct Matrix
{
    int rows; 
    int cols;
    char *cells;
}
Mat_t;

void allocate_mem(Mat_t *mat)
{
    mat->cells = (char *)malloc(sizeof(char) * mat->rows * mat->cols);   
}

void generate_mat(Mat_t mat)
{
    for(int i = 0; i < mat.rows; ++i)
    {
        for(int j = 0; j < mat.cols; ++j)
        {
            mat.cells[(i * mat.cols) + j] = rand() % 26 + 'a';
        }
    }
}

void print_mat(Mat_t mat)
{
    for(int i = 0; i < mat.rows; ++i)
    {
        for(int j = 0; j < mat.cols; ++j)
        {
            printf(" %c ", mat.cells[(i * mat.cols) + j]);
        }
        printf("\n");
    }
}

void rotate_mat(Mat_t *mat)
{
    Mat_t temp = {mat->cols, mat->rows, NULL};

    allocate_mem(&temp);

    for(int j = 0, k = 0; j < mat->cols; ++j, ++k)
    {
        for(int i = mat->rows - 1, l = 0; i >= 0; --i, ++l)
        {
            temp.cells[(k * temp.cols) + l] = mat->cells[(i * mat->cols) + j];
        }
    }

    mat->cols = temp.cols;
    mat->rows = temp.rows;
    memcpy(mat->cells, temp.cells, mat->rows * mat->cols);

    free(temp.cells);
}


int main()
{
    Mat_t mats[] = {{3, 8, NULL}, {5, 5, NULL}, {6, 4, NULL}};

    srand((unsigned int)time(NULL));

    for(int i = 0; i < 3; i++)
    {
        allocate_mem(&mats[i]);

        generate_mat(mats[i]);

        printf("Initial Matrix/Grid %d (%dx%d):\n", i + 1, mats[i].rows, mats[i].cols);
        print_mat(mats[i]);
        
        printf("Rotated Matrix/Grid %d:\n", i + 1);
        rotate_mat(&mats[i]);
        print_mat(mats[i]);
        
        printf("\n");

        free(mats[i].cells);
    }

    return 0;
}