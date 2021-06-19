#include <iostream>
#include<string>
#include<fstream>
#define max 20
using namespace std;
unsigned int saniye, yazmahizi;
int j=0,n=0,f=0;
string dizi1[20];
int dizi2[20];
struct belge{
string belgeyol;
float boyut;
int sayfa;

};
struct kisi{
string ad;
string soyad;
string nick;
string email;

};
struct tarih{
    int yil;
    int gun;
    int ay;
    int saat;
    int dakika;
    int saniye;
};

struct circularyqueue{
string kuyruk[max];
int page[max];
int son;
int baslangic;
circularyqueue(){
son=-1;
baslangic=-1;
}
~circularyqueue(){

}
void ekle(string elem,int sayfa);
void sil();
void printer();
};


void circularyqueue::ekle(string elem,int sayfa){

    int  b=j*saniye;
    if(son+1==f || son+1== max){

    cout<<b<<"sn - PC kuyruga yazamadi."<<endl;

    }
    else{
            n++;
            if(baslangic==-1){
                baslangic=0;
            }
           son=son+1;
            kuyruk[son]=elem;
            page[son]=sayfa;
        cout<<b<<"sn     "<<"- Pc kuyruga yazdi -     "<<kuyruk[son]<<endl;

    }
}
void circularyqueue::sil(){
 if(baslangic==-1 || baslangic>son){
        baslangic=-1;
        son=-1;

    }
    else{
        cout<<saniye*j/2<<"sn - Yazici kuyruktan okudu - 	"<<kuyruk[baslangic]<<endl;
        for(int k=baslangic;k<son;k++){
            kuyruk[k]=kuyruk[k+1];
            page[k]=page[k+1];
            }
    son=son-1;

        }

    }
void circularyqueue::printer(){
    string elem=kuyruk[baslangic];
    int sayfa=page[baslangic];
    int k=j+(sayfa*yazmahizi);
    sil();
    while(j<k){
            j++;
        if(n<f){
        ekle(dizi1[n],dizi2[n]);}

    }
    cout<<k<<"sn - Yazici belgeyi yazdi. 	"<<elem<<endl;

   if(baslangic==-1 || baslangic>son){
        baslangic=-1;
        son=-1;

    }else{
    printer();
    }
}
int main()
{
    circularyqueue kuyruk1;
    fstream file;
    file.open("belgeler.txt",ios::in);
    belge b1; tarih t1; kisi k1;

    cout<<" PC kac saniyede kuyruga belge gonderir (sn) :   ";
    cin>>saniye;
    cout<<endl<<"Yazicinin bir sayfayi yazma hizi nedir? (cn):   ";
    cin>>yazmahizi;


 while(!file.eof()){

    file>>b1.belgeyol>>b1.boyut>>b1.sayfa>>k1.ad>>k1.soyad>>k1.nick>>k1.email;
    file>>t1.yil>>t1.ay>>t1.gun>>t1.saat>>t1.dakika>>t1.saniye;
    dizi1[f]=b1.belgeyol;
     dizi2[f]=b1.sayfa;
    f++;
 }
 kuyruk1.ekle(dizi1[n],dizi2[n]);
 kuyruk1.printer();

    cout<<"Tum Belgeler Yazdirildi..."<<endl;
    return 0;
}
