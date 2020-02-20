```cpp
int up[100000+5][20];
void init(){
    for(int i = 1;i<=n;i++){
        up[i][0] = par[i];
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=17;j++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    
}
```