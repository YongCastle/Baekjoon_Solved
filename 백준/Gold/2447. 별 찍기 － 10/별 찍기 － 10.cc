#include <cstdio>

char Pattern[81*27][81*27];

void print_Blank(int x, int y, int N)
{
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            Pattern[x+i][y+j] = ' ';
        }
    }
}



void print_Pattern(int x, int y, int N)
{
    if(N==3){
        Pattern[x][y]       = '*';
        Pattern[x][y+1]     = '*';
        Pattern[x][y+2]     = '*';
        Pattern[x+1][y]     = '*';
        Pattern[x+1][y+1]   = ' ';
        Pattern[x+1][y+2]   = '*';
        Pattern[x+2][y]     = '*';
        Pattern[x+2][y+1]   = '*';
        Pattern[x+2][y+2]   = '*';
        return;
    }
    
    print_Pattern(x,          y,          N/3);
    print_Pattern(x,          y+N/3,      N/3);
    print_Pattern(x,          y+2*N/3,    N/3);
    
    print_Pattern(x+N/3,      y,          N/3);
    print_Blank(x+N/3,      y+N/3,      N/3);
    print_Pattern(x+N/3,      y+2*N/3,    N/3);
    
    print_Pattern(x+2*N/3,    y,          N/3);
    print_Pattern(x+2*N/3,    y+N/3,      N/3);
    print_Pattern(x+2*N/3,    y+2*N/3,    N/3);
    
    return;
}

int main(int argc, char* argv[])
{
    int N; scanf("%d", &N);
    
    print_Pattern(0, 0, N);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%c", Pattern[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}