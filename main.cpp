#include <fstream>
using namespace std;

ifstream fin("kscale.in");
ofstream fout ("kscale.out");
int a[1001][1001], b[1001][1001], v[3];
int main(){
    int n, m, i, j, x, col=0, lin=0, coloana=1, linie=1, y, contor;
    fin >> n >> m;
    for(i=1; i<=n; i++){
        fin >> x;
        for(j=m; j>=1; j--){
            a[i][j]=x%10;
            x=x/10;
        }
    }
    if(n==1){
        for(j=1; j<=m; j++)
            if(a[1][j]==0)
                v[0]++;
            else
                v[1]++;
        if(v[0]>v[1])
            col=v[1];
        else
            col=v[0];
        x=1;
        y=m/col;
        for(j=1; j<=m; j++)
            if(j%col==0){
                lin++;
                b[1][lin]=a[1][j];
            }
    }
    else if(m==1){
        for(i=1; i<=n; i++)
            if(a[i][1]==0)
                v[0]++;
            else
                v[1]++;
        if(v[0]>v[1])
            col=v[1];
        else
            col=v[0];
        x=n/col;
        y=1;
        for(i=1; i<=n; i++)
            if(i%col==0){
                lin++;
                b[lin][1]=a[i][1];
            }
    }
    else{
        x=1;
        contor=1;
        for(j=1; j<m; j++)
            if(a[1][j]==a[1][j+1])
                coloana++;
            else
                j=m;
        for(i=1; i<n; i++)
            if(a[i][1]==a[i+1][1])
                linie++;
            else
                i=n;
            if(coloana==m && linie==n){
                x=1;
                y=1;
                b[1][1]=a[1][1];
            }
            else if(coloana==m){
                for(i=1; i<n; i++)
                    for(j=1; j<m; j++)
                        if(a[i][j]!=a[i][j+1]){
                            coloana=j;
                            i=n;
                            j=m;
                        }
            }
            else if(linie==n){
                for(j=1; j<m; j++)
                    for(i=1; i<n; i++)
                        if(a[i][j]!=a[i+1][j]){
                            linie=i;
                            i=n;
                            j=m;
                        }
            }
        for(i=1; i<=n; i=i+linie){
            for(j=1; j<=m; j++){
                if(j%coloana==0){
                    b[x][contor]=a[i][j];
                    contor++;
                }
            }
            y=contor-1;
            x++;
            contor=1;
        }
        x--;
    }
    fout << x << " " << y << endl;
    for(i=1; i<=x; i++){
        for(j=1; j<=y; j++)
            fout << b[i][j];
        fout << endl;
    }

}
