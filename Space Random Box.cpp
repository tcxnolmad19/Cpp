#include <iostream>
#include<time.h>
#include <cstdlib>
#include<fstream>
using namespace std;
int adet;
class space{
    private:
    double xmax;
    double ymax;
    protected:
    class box{
        public:
            class coord{
                public:
                    double x;
                    double y;
                    };
            double density;
            double width;
            double height;
            };
    public:
        space(double a, double b){
            xmax=a;
            ymax=b;
        }
        ~space(){
        }
    void fillRandomBox(int sayi,int maxboyut,int yogunluk);
   void printBoxCoordinates();
   void printCenterOfMass();
};

 void  space::fillRandomBox(int sayi,int maxboyut,int yogunluk){
    adet=sayi;
    double x0=0,y0=0;
    ofstream dosya;
    dosya.open("file.txt",ios::out);
    double r1, r2,y;
    srand (time(NULL));
    for (int i=0;i<sayi;i++){
        r1 = 1+rand() %maxboyut ;
        r2= 1+rand() % maxboyut;
        if(x0+r1<xmax && y0+r2<ymax){
            box a;
            box::coord b;
            a.density=r1*r2*yogunluk;
            a.width=r1;
            a.height=r2;
            b.x=x0;
            b.y=y0;
            x0=x0+r1;
            y=y0+r2;
            dosya<<endl<<b.x<<"        "<<b.y<<"        "<<x0<<"        "<<y<<"       "<<a.width<<"        "<<a.height<<"        "<<a.density;
            x0++;
        }else{
            x0=0;
            y0=y0+maxboyut+1;
                if(y0+r2<ymax){
                    box a;
                    box::coord b;
                    a.density=r1*r2*yogunluk;
                    a.width=r1;
                    a.height=r2;
                    b.x=x0;
                    b.y=y0;
                    x0=x0+r1;
                    y=y0+r2;
                    dosya<<endl<<b.x<<"        "<<b.y<<"        "<<x0<<"        "<<y<<"       "<<a.width<<"        "<<a.height<<"        "<<a.density;
                    x0++;
                    }else{
                    cout<<"maximum alan doldu!.."<<endl;
                    }
            }
    }
    dosya.close();
}

 void space::printBoxCoordinates(){
    ifstream dosya;
    ofstream yaz;
    double x0,y0,xs,ys,x,y,d;
    dosya.open("file.txt",ios::in);
    yaz.open("kordinat.txt",ios::out);
    int n=1;
    while(!dosya.eof()){
        dosya>>x0>>y0>>xs>>ys>>x>>y>>d;
        cout<<n<<". dikdortgenin  "<<"Baslangic kordinati:"<<x0<<","<<y0<<"    Bitis kordinati:";
        cout<<xs<<","<<ys<<"    Genisligi:"<<x<<"    Uzunlugu:"<<y<<"    yogunlugu:"<<d<<endl<<endl;
        yaz<<x0<<","<<y0<<"         "<<xs<<","<<ys<<"         "<<x<<"         "<<y<<"         "<<d<<endl;
        n++;
        }
    dosya.close();
    yaz.close();
 }
 void space::printCenterOfMass(){
    ifstream dosya;
    dosya.open("file.txt",ios::in);
    double x0,y0,xs,ys,x,y,d;
    double mass[adet];
    double x1[adet];
    double y1[adet];
    int i=0;
    while(!dosya.eof()){
        dosya>>x0>>y0>>xs>>ys>>x>>y>>d;
        mass[i]=d;
        x1[i]=(xs+x0)/2;
        y1[i]=(ys+y0)/2;
        i++;
    }
    dosya.close();
    double a,b,c;

    a=x1[0];
    b=y1[0];
    c=mass[0];
    for(int j=1;j<adet;j++){
       a=(a*c+x1[j]*mass[j])/(c+mass[j]);
       b=(b*c+y1[j]*mass[j])/(c+mass[j]);
       c=c+mass[j];
    }
    cout<<"kutularin agirlik merkezinin kordinatlari="<<a<<","<<b<<endl;
    cout<<" Sistemin agirligi="<<c<<endl;

}
int main()
{
    space s (30,40);
    s .fillRandomBox(10 , 3 , 1 );
    s .printBoxCoordinates();
    s .printCenterOfMass();
    return 0;
}
