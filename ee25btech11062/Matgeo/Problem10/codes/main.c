#include <stdio.h>
#include <math.h>
#define MAX 4
void print_matrix(int n,double mat[MAX][MAX]){
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%lf",mat[i][j]);
        }
        printf("\n");
    }
}
int inverse_matrix(int n,double mat[MAX][MAX],double inverse[MAX][MAX]){
    double augvec[MAX][MAX*2];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            augvec[i][j]=mat[i][j];
        }
        for(int j=0;j<n;j++){
            augvec[i][j+n]=(i==j)?1:0;
        }
    }
    for(int i=0;i<n;i++){
        double pivot=augvec[i][i];
        if(pivot>-0.01 && pivot < 0.01){
int max_row = i;
for (int k = i + 1; k < n; k++) {
    if (fabs(augvec[k][i]) > fabs(augvec[max_row][i])) {
        max_row = k;
    }
}


if (max_row != i) {
    for (int j = 0; j < 2 * n; j++) {
        double temp = augvec[i][j];
        augvec[i][j] = augvec[max_row][j];
        augvec[max_row][j] = temp;
    }
}
        }
        pivot=augvec[i][i];
        
        if(pivot>-0.01 & pivot<0.01)return 0;
        for(int j=0;j<2*n;j++){
            augvec[i][j]/=pivot;
        }
        for (int k=0;k<n;k++){
            if(k!=i){
                double factor=augvec[k][i];
                for(int j=0;j<2*n;j++){
                    augvec[k][j]-=factor*augvec[i][j];
                }
            }
        }
        
    }
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                inverse[i][j]=augvec[i][j+n];
            }
        }
    return 1;

}

void matmul(int m, int n, int p, double A[m][n], double B[n][p], double C[m][p]){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<p; j++){
            C[i][j]=0;
            for(int k =0; k<n; k++){
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
}
void find_sol(){
    int n = 4;
    double mat[4][4] = {{1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, -1, 0}, {0, 1, 0, -1}};
    double inv[MAX][MAX];
    
    inverse_matrix(n,mat,inv);
    if(inverse_matrix(n,mat,inv)==0){
        printf("The matrix is singular");
    }
    double Y[4][2] = {{7,0}, {2,5}, {3,0}, {0,4}};
    double res[4][2];
    matmul(4, 4, 2, inv, Y, res);
    printf("Matrix X\n");
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++) printf("%lf ", res[i][j]);
        printf("\n");
    }
    printf("Matrix Y\n");
    for(int i = 2; i<4; i++){
        for(int j = 0; j<2; j++) printf("%lf ", res[i][j]);
        printf("\n");
    }
}
