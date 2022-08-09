#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
class matrix{
protected:
    int rows;
    int cols;
    };
class Goruntu:public matrix{
 private:
     int genislik;
     int yukseklik;
     int s[255][255];
public:
    Goruntu(){
    }
    ~Goruntu(){
    }
    void goruntumatrix();
    void sobel();
    void threshold( int filter);
    void print(int a);
    friend Goruntu operator +(Goruntu g1, Goruntu g2);
    friend Goruntu operator *(Goruntu g1, Goruntu g2);
    friend Goruntu operator !(Goruntu g1);
};
void Goruntu::goruntumatrix(){
    ifstream dosya;
    char adres[11];
    cout<<endl<<"Goruntu dosyasinin adini giriniz: "; cin>>adres;
    dosya.open(adres,ios::binary);
    char *arr;
    arr = new char[2];
    dosya.read(arr,2);
    rows = int((arr[0]+256)%256);
    cols= int((arr[1]+256)%256);
    int imgSize =rows*cols;
    yukseklik=rows;
    genislik=cols;
    delete arr;
    dosya.seekg(2,ios::beg);
    arr = new char[imgSize];
    dosya.read(arr, imgSize);
    int q=0;
    for(int i=0;i<yukseklik;i++){
        for(int j=0;j<genislik;j++){
           s[i][j]= int((arr[q]+256)%256);
            q++;
        }
    }
    dosya.close();
    delete arr;
}
void Goruntu::sobel(){
    goruntumatrix();
  ofstream dosya;
dosya.open("s.txt",ios::out);
       int maskx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
        int masky[3][3] = {{1,2,1},{0,0,0},{-1,-2,-1}};
        int maxival;

        int i,j,p,q,mr,sum1,sum2;


        mr = 1;

        maxival = 0;
        for (i=mr;i<yukseklik-mr;i++)
        { for (j=mr;j<genislik-mr;j++)
          {
             sum1 = 0;
             sum2 = 0;
             for (p=-mr;p<=mr;p++)
             {
                for (q=-mr;q<=mr;q++)
                {
                   sum1 += s[i+p][j+q] * maskx[p+mr][q+mr];
                   sum2 += s[i+p][j+q] * masky[p+mr][q+mr];
                }
             }
          s[i][j]=(int) (sqrt((double)((sum1*sum1) + (sum2*sum2))));
             if (s[i][j] > maxival)
                maxival = s[i][j];
          }
        }

        for (i=0;i<yukseklik;i++)
          { for (j=0;j<genislik;j++)
            {
             s[i][j] = ((s[i][j]*1.0) / maxival) * 255;
            }
          }
    }
void Goruntu::threshold( int filter){
    ofstream dosya;
    dosya.open("threshold.txt",ios::out);
    for(int i=0;i<yukseklik;i++){
        for(int j=0;j<genislik;j++){
            if(s[i][j]<filter){
                s[i][j]=0;
            }else{
            s[i][j]=1;
            }
           dosya<<s[i][j]<<"   ";

        }
        dosya<<endl;
    }

    dosya.close();
}
void Goruntu::print(int a){
    ofstream file;
    if(a==1){
    file.open("or.txt",ios::out);
    }
    if(a==2){
    file.open("and.txt",ios::out);
    }
    if(a==3){
    file.open("not.txt",ios::out);
    }
    for(int i=0;i<yukseklik;i++){
        for(int j=0;j<genislik;j++){
            if(s[i][j]==0){
                file<<"-";
            }else{
                file<<"*";
            }
        }
    file<<endl;
    }
}
Goruntu operator +(Goruntu g1, Goruntu g2){
    Goruntu g3;
    for(int i=0;i<g1.yukseklik;i++){
        for(int j=0;g1.genislik;j++){
            if(g1.s[i][j]==1 || g2.s[i][j]==1){
                g3.s[i][j]=1;
            }else{
            g3.s[i][j]=0;
            }
        }
    }
    g3.print(1);
    return g3;
}
Goruntu operator *(Goruntu g1, Goruntu g2){
Goruntu g3;
    for(int i=0;i<g1.yukseklik;i++){
        for(int j=0;g1.genislik;j++){
            if(g1.s[i][j]==1 && g2.s[i][j]==1){
                g3.s[i][j]=1;
            }else{
            g3.s[i][j]=0;
            }
        }
    }
    g3.print(2);
return g3;
}
Goruntu operator !(Goruntu g1){
Goruntu g3;
 for(int i=0;i<g1.yukseklik;i++){
        for(int j=0;g1.genislik;j++){
            if(g1.s[i][j]==1 ){
                g3.s[i][j]=0;
            }else{
            g3.s[i][j]=1;
            }
        }
    }
    g3.print(3);
return g3;
}
int main(){
    Goruntu g1,g2,g3;
    g1.sobel();
    g2.sobel();
    g1.threshold(100);
    g2.threshold(100);
    g2.print(1);
    //g3=g1+g2;
    //g3=!g1;
    //g3=g1*g2;
    return 0;
}
