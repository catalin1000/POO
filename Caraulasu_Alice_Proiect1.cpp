#include <iostream>
#include <string.h>
#include <map>
using namespace std;
int extrage(string s)
{
    int i = 0;
    string res = "";
    while(isdigit(s[i]))
    {
        res += s[i];
        i++;
    }
    return stoi(res);
}

class Spectator
{
    static int contorId;
    const int bilet;
    char* numeSpectator;
    string loc;
    static int numarSpectatori;
    ///constructori
public:
    Spectator():bilet(contorId++)
    {
        numeSpectator=new char [strlen("Anonim")+1];
        strcpy(numeSpectator,"Anonim");
        loc="_";
        numarSpectatori++;

    }
    Spectator(char* numeSpectator, string loc):bilet(contorId++)
    {
        this->numeSpectator=new char [strlen(numeSpectator)+1];
        strcpy(this->numeSpectator,numeSpectator);
        this->loc=loc;
        numarSpectatori++;

    }
    Spectator(const Spectator& obj):bilet(obj.bilet)
    {
        this->numeSpectator=new char [strlen(obj.numeSpectator)+1];
        strcpy(this->numeSpectator,obj.numeSpectator);
        this->loc=obj.loc;
        numarSpectatori++;

    }
    ///Set+Get
    string getloc()
    {
        return this->loc;
    }
    const int getbilet()
    {
        return this->bilet;
    }
    char* getnumeSpectator()
    {
        return this->numeSpectator;
    }
    static int getcontorId()
    {
        return Spectator::contorId;
    }
    static int getnumarSpectatori()
    {
        return Spectator::numarSpectatori;
    }

    void setloc(string l)
    {
        this->loc=l;
    }
    void setnumeSpectator(char* p)
    {

        if(this->numeSpectator != NULL)
        {
            delete[] this->numeSpectator;
            this->numeSpectator = NULL;
        }

        this->numeSpectator = new char[strlen(p) + 1];
        strcpy(this->numeSpectator, p);
    }
    void setnumarSpectatori(int spec)
    {
        Spectator::numarSpectatori=spec;
    }
    void setcontorId(int contor)
    {
        Spectator::contorId=contor;
    }

    ///Operator
    Spectator& operator = (const Spectator&);
    friend ostream& operator <<(ostream& out, const Spectator& obj);
    friend istream& operator >>(istream& in, Spectator& obj);
    Spectator& operator++();
    Spectator operator++(int);
    string operator+(const Spectator&);
    bool operator==(const Spectator&);
    bool operator<(const Spectator&);
    bool operator>(const Spectator&);
    operator int ();
    ///metoda
    void locuriLibereLanga(map<string,bool> mp,string l);
    ///Destructor
    ~Spectator();

};
int Spectator::contorId = 1;
int Spectator::numarSpectatori = 0;
///Metode
void Spectator::locuriLibereLanga(map<string,bool> mp,string l)
{


    int i = 0;
    string res ="";
    while(isdigit(l[i]))
    {
        i++;

    }
    res+=l[i];
    int mij=extrage(l);
    int st=mij-1;
    int dr=mij+1;
    string locst, locdr;
    locst=to_string(st)+res;
    locdr=to_string(dr)+res;
    if(mij!=1 && mij!=10 && mij!=11 && mij!=20 && mij!=21 && mij!=30)
    {

        if(mp[locst]==0 || mp[locdr]==0)
            cout<<"liber\n";
        else
            cout<<"ocupat\n";
    }
    else if(mij==1 && mp[locdr]==0)
    {
        cout<<"liber\n";
    }
    else if(mij==10 && mp[locst]==0)
    {
        cout<<"liber\n";
    }
    else if(mij==11 && mp[locdr]==0)
    {
        cout<<"liber\n";
    }
    else if(mij==20 && mp[locst]==0)
    {
        cout<<"liber\n";
    }
    else if(mij==21 && mp[locdr]==0)
    {
        cout<<"liber\n";
    }
    else if(mij==30 && mp[locst]==0)
    {
        cout<<"liber\n";
    }
    else
        cout<<"ocupat\n";
}

///Get+Set


Spectator& Spectator::operator = (const Spectator& obj)
{
    if(this != &obj)
    {
        if(this->numeSpectator != NULL)
        {
            delete[] this->numeSpectator;
            this->numeSpectator = NULL;
        }

        this->numeSpectator = new char[strlen(obj.numeSpectator) + 1];
        strcpy(this->numeSpectator, obj.numeSpectator);
        this->loc = obj.loc;
    }
    return *this;
}
istream& operator >>(istream& in, Spectator& obj)
{
    cout << "Introduceti numele: " << endl;
    char numeSpectator[50];
    in.getline(numeSpectator,50) ;

    if(obj.numeSpectator != NULL)
    {
        delete[] obj.numeSpectator;
        obj.numeSpectator = NULL;
    }
    obj.numeSpectator = new char[strlen(numeSpectator) + 1];
    strcpy(obj.numeSpectator, numeSpectator);
    cout << "Introduceti locul: " << endl;
    in >> obj.loc;
    in.get();
    return in;
}
ostream& operator <<(ostream& out, const Spectator& obj)
{
    out << "Numar bilet: " << obj.bilet << endl;
    out << "Nume: " << obj.numeSpectator<< endl;
    out << "Locul: " << obj.loc << endl;
    return out;
}
Spectator& Spectator::operator++()
{
    this->numarSpectatori++;
    return *this;
}
Spectator Spectator::operator++(int)
{
    Spectator aux(*this);
    this->numarSpectatori++;
    return aux;
}
string Spectator::operator+(const Spectator& obj)
{
    int a=extrage(this->loc);
    int b=extrage(obj.loc);
    if(a==b+1 || a==b-1)
        return "vecini la concert";
    return "distantati la concert";
}
bool Spectator::operator==(const Spectator& obj)
{
    int a=strcmp(this->numeSpectator,obj.numeSpectator);
    if(!a)
        return true;
    return false;
}
bool Spectator::operator<(const Spectator& obj)
{
    return this->bilet<obj.bilet;
}
bool Spectator::operator>(const Spectator& obj)
{
    return this->bilet>obj.bilet;
}

Spectator::operator int ()
{
    return this->bilet;
}
Spectator::~Spectator()
{
    if(this->numeSpectator != NULL)
    {
        delete[] this->numeSpectator;
        this->numeSpectator = NULL;
        ///cout<<'\n'<<"destructor"<<Spectator::numarSpectatori;
    }
    this->loc="_";
    Spectator::numarSpectatori--;


}




class Concert
{
    static int numarConcerte;
    //const int idConcert;
    float* pretLocuri;///pentru M :a-h=100lei, i,j,k,l,n,o= 80.3lei, m,p,q,r,s,t=60.2lei, u-z=85.5lei. pentru m: a-l=52.8lei,m-t=45.2lei,u-z=40.1lei.
    char sala;/// M=mare, m=mica
    char* ora;///hh:mm
    char* data;///dd.MM
    string lucrareMuzicala;
public:
    ///metode;
    char* nextTime( int w[],char c,int sf,char*date);///cand va fi urmatorul concert
    ///constructori
    Concert();
    Concert(char sala, char* ora, char* data, string lucrareMuzicala);
    Concert(const Concert& obj);
    ///operatori
    Concert& operator = (const Concert&);
    friend ostream& operator <<(ostream& out, const Concert& obj);
    friend istream& operator >>(istream& in, Concert& obj);
    Concert& operator++();
    Concert operator++(int);
    bool operator==(const Concert&);
    bool operator<(const Concert&);
    bool operator>(const Concert&);
    float operator[](int);
    operator string();
    friend double operator+(Spectator,Concert);
    friend double operator+(Concert,Spectator);
    ///friend class
    // friend class Spectator;
    ///Set+Get
    string getlucrareMuzicala()
    {
        return this->lucrareMuzicala;
    }
    float* getpretLocuri()
    {
        return this->pretLocuri;
    }
    char getSala()
    {
        return this->sala;
    }
    char* getOra()
    {
        return this->ora;
    }
    char* getData()
    {
        return this->data;
    }
    static int getnumarConcerte()
    {
        return Concert::numarConcerte;
    }



    void setlucrareMuzicala(string nume)
    {
        this->lucrareMuzicala=nume;
    }
    void setpretLocuri(float * v)
    {
        if(this->pretLocuri != NULL)
        {
            delete[] this->pretLocuri;
            pretLocuri = NULL;
        }
        if(this->sala=='m')
        {
            this->pretLocuri= new float [131];
            for(int i=0; i<131; i++)
                this->pretLocuri[i]=v[i];
        }
        else
        {
            this->pretLocuri= new float [261];
            for(int i=0; i<261; i++)
                this->pretLocuri[i]=v[i];
        }

    }
    void setSala(char c)
    {
        this->sala=c;
        if(this->sala=='m')
        {
            this->pretLocuri= new float [131];
            for(int i = 1; i < 131; i++)
                if(i>=1 && i<=60)
                    this->pretLocuri[i] =52.8;
                else if(i>=61 && i<=100)
                    this->pretLocuri[i]=45.2;
                else
                    this->pretLocuri[i]=40.1;
        }
        else
        {
            this->pretLocuri= new float [261];
            for(int i = 1; i < 261; i++)
                if(i>=1 && i<=80)
                    this->pretLocuri[i] =100;
                else if((i>=81 && i<=120) || (i>=131 && i<=150))
                    this->pretLocuri[i]=80.3;
                else if(i>=201 && i<=260)
                    this->pretLocuri[i]=85.5;
                else
                    this->pretLocuri[i]=60.2;
        }

    }
    void setOra(char* p)
    {
        if(this->ora != NULL)
        {
            delete[] this->ora;
            this->ora = NULL;
        }
        this->ora=new char[6];
        strcpy(this->ora,p);
    }
    void setData(char* p)
    {
        if(this->data != NULL)
        {
            delete[] this->data;
            this->data = NULL;
        }
        this->data=new char[6];
        strcpy(this->data,p);
    }
    void setnumarConcerte(int numar)
    {
        Concert::numarConcerte=numar;
    }





///Destructor
    ~Concert();

};

int Concert::numarConcerte =0;
//string Concert::nextTime( int w[],char c,int sf,char*date)
char* Concert::nextTime(int w[],char c,int sf,char*date)
{
    char* mini=new char[6];
    strcpy(mini,"1232~");
    char* aux=new char[6];
    aux[5]=NULL;
    int i,j;
    for(i=1; i<sf; i+=4)
    {
        for(j=0; j<=3; j++)
            aux[j]=w[i+j]+'0';

        swap(aux[0],aux[2]);
        swap(aux[1],aux[3]);
        //  cout<<"merge"<<endl;
        //  cout<<aux<<endl;
        //   cout<<date<<endl;
        //   cout<<mini<<endl;
        if(strcmp(aux,mini)<=0 && strcmp(aux,date)>0)
            strcpy(mini,aux);

    }
    swap(mini[0],mini[2]);
    swap(mini[1],mini[3]);
    swap(mini[4],mini[3]);
    swap(mini[3],mini[2]);
    //cout<<mini<<endl;
    mini[2]='.';
    mini[5]=NULL;

    if(!strcmp(mini,"32.12"))
    {
        return "Nu exista data programata pentru concert in viitorul anului 2025.\n";
    }
    else
    {
        cout<<"Urmatorul concert din anul 2025 va fi in data de: ";
        return mini;
    }
}

Concert::Concert()
{
    data = new char[strlen("Nestabilita") + 1];
    strcpy(data, "Nestabilita");
    ora = new char[strlen("Nestabilita") + 1];
    strcpy(ora, "Nestabilita");
    lucrareMuzicala = "Necunoscuta";
    sala = '_';
    pretLocuri= NULL;
    numarConcerte++;
}
Concert::Concert(char sala, char* ora, char* data, string lucrareMuzicala)
{
    this->data = new char[6];
    strcpy( this->data,data);
    this->ora = new char[6];
    strcpy(this->ora,ora );
    this->lucrareMuzicala=lucrareMuzicala;
    this->sala=sala;
    if(sala=='m')
    {
        this->pretLocuri= new float [131];
        for(int i = 1; i < 131; i++)
            if(i>=1 && i<=60)
                this->pretLocuri[i] =52.8;
            else if(i>=61 && i<=100)
                this->pretLocuri[i]=45.2;
            else
                this->pretLocuri[i]=40.1;
    }
    else
    {
        this->pretLocuri= new float [261];
        for(int i = 1; i < 261; i++)
            if(i>=1 && i<=80)
                this->pretLocuri[i] =100;
            else if((i>=81 && i<=120) || (i>=131 && i<=150))
                this->pretLocuri[i]=80.3;
            else if(i>=201 && i<=260)
                this->pretLocuri[i]=85.5;
            else
                this->pretLocuri[i]=60.2;
    }
    numarConcerte++;
}
Concert::Concert(const Concert& obj)
{
    numarConcerte++;
    this->data = new char[6];
    strcpy( this->data,obj.data);
    this->ora = new char[6];
    strcpy(this->ora,obj.ora );
    this->lucrareMuzicala=obj.lucrareMuzicala;
    this->sala=obj.sala;
    if(this->pretLocuri != NULL)
    {
        delete[] this->pretLocuri;
        pretLocuri = NULL;
    }
    if(obj.sala=='m')
    {
        this->pretLocuri= new float [131];
        for(int i = 1; i < 131; i++)
            if(i>=1 && i<=60)
                this->pretLocuri[i] =52.8;
            else if(i>=61 && i<=100)
                this->pretLocuri[i]=45.2;
            else
                this->pretLocuri[i]=40.1;
    }
    else
    {
        this->pretLocuri= new float [261];
        for(int i = 1; i < 261; i++)
            if(i>=1 && i<=80)
                this->pretLocuri[i] =100;
            else if((i>=81 && i<=120) || (i>=131 && i<=150))
                this->pretLocuri[i]=80.3;
            else if(i>=201 && i<=260)
                this->pretLocuri[i]=85.5;
            else
                this->pretLocuri[i]=60.2;
    }

}
Concert& Concert::operator = (const Concert& obj)
{
    if(this != &obj)
    {
        if(this->data != NULL)
        {
            delete[] this->data;
            this->data = NULL;
        }
        if(this->ora != NULL)
        {
            delete[] this->ora;
            this->ora = NULL;
        }

        if(this->pretLocuri != NULL)
        {
            delete[] this->pretLocuri;
            pretLocuri = NULL;
        }

        this->data = new char[6];
        strcpy( this->data,obj.data);
        this->ora = new char[6];
        strcpy(this->ora,obj.ora );

        this->lucrareMuzicala = obj.lucrareMuzicala;
        this->sala = obj.sala;
        if(obj.sala=='m')
        {
            this->pretLocuri= new float [131];
            for(int i = 1; i < 131; i++)
                if(i>=1 && i<=60)
                    this->pretLocuri[i] =52.8;
                else if(i>=61 && i<=100)
                    this->pretLocuri[i]=45.2;
                else
                    this->pretLocuri[i]=40.1;
        }
        else
        {

            this->pretLocuri= new float [261];
            for(int i = 1; i < 261; i++)
                if(i>=1 && i<=80)
                    this->pretLocuri[i] =100;
                else if((i>=81 && i<=120) || (i>=131 && i<=150))
                    this->pretLocuri[i]=80.3;
                else if(i>=201 && i<=260)
                    this->pretLocuri[i]=85.5;
                else
                    this->pretLocuri[i]=60.2;
        }
    }
    return *this;
}
ostream& operator <<(ostream& out, const Concert& obj)
{
    out << "Lucrarea muzicala a concertului: " << obj.lucrareMuzicala << endl;
    out << "Data concertului din anul 2025: " << obj.data<<" la ora: "<< obj.ora<< endl;
    out << "Sala: " << obj.sala << endl;
    out << "Lista cu pretul biletelor: ";
    for(int i = 1; i < 131 && obj.sala=='m'; i++)
        out << obj.pretLocuri[i] << " ";
    for(int i = 1; i < 261 && obj.sala=='M'; i++)
        out << obj.pretLocuri[i] << " ";
    out << endl;
    return out;
}

istream& operator >>(istream& in, Concert& obj)
{
    cout << "Introduceti lucrarea muzicala: " << endl;
    getline(in,obj.lucrareMuzicala) ;

    cout << "Introduceti data concertului din anul 2025: " << endl;
    char data[6];
    in >> data;
    if(obj.data != NULL)
    {
        delete[] obj.data;
        obj.data = NULL;
    }
    obj.data = new char[6];
    strcpy(obj.data, data);
    cout << "Introduceti ora concertului: " << endl;
    char ora[6];
    in >> ora;
    if(obj.ora!= NULL)
    {
        delete obj.ora;
        obj.ora = NULL;
    }
    obj.ora = new char[6];
    strcpy(obj.ora, ora);

    cout << "Introduceti sala: " << endl;
    in >> obj.sala;


    if(obj.pretLocuri != NULL)
    {
        delete[] obj.pretLocuri;
        obj.pretLocuri = NULL;
    }
    if(obj.sala=='m')
    {
        obj.pretLocuri= new float [131];
        for(int i = 1; i < 131; i++)
            if(i>=1 && i<=60)
                obj.pretLocuri[i] =52.8;
            else if(i>=61 && i<=100)
                obj.pretLocuri[i]=45.2;
            else
                obj.pretLocuri[i]=40.1;
    }
    else
    {

        obj.pretLocuri= new float [261];
        for(int i = 1; i < 261; i++)
            if(i>=1 && i<=80)
                obj.pretLocuri[i] =100;
            else if((i>=81 && i<=120) || (i>=131 && i<=150))
                obj.pretLocuri[i]=80.3;
            else if(i>=201 && i<=260)
                obj.pretLocuri[i]=85.5;
            else
                obj.pretLocuri[i]=60.2;
    }
    in.get();
    return in;
}
Concert& Concert::operator++()
{
    char*aux=new char[6];
    strcpy(aux,this->data);
    if(aux[3]=='0' && (aux[4]=='1' || aux[4]=='3' || aux[4]=='5' || aux[4]=='7' || aux[4]=='8' || aux[4]=='10' || aux[4]=='12' ))///31 de zile pe luna
    {
        if(aux[1]=='9')
        {
            aux[1]='0';
            aux[0]++;
        }
        else if(aux[0]=='3' && aux[1]=='1')
        {
            aux[0]='0';
            aux[1]='1';
            if(aux[4]=='9')
            {
                aux[3]='1';
                aux[4]='0';
            }
            else
                aux[4]++;
        }
        else
            aux[1]++;
    }
    else if(aux[3]=='0' && aux[3]=='2')///28 de zile
    {
        if(aux[1]=='9')
        {
            aux[1]='0';
            aux[0]++;
        }
        else if(aux[0]=='2' && aux[1]=='8')
        {
            aux[0]='0';
            aux[1]='1';
            if(aux[4]=='9')
            {
                aux[3]='1';
                aux[4]='0';
            }
            else
                aux[4]++;
        }
        else
            aux[1]++;
    }
    else ///30 de zile
    {
        if(aux[1]=='9')
        {
            aux[1]='0';
            aux[0]++;
        }
        else if(aux[0]=='3' && aux[1]=='0')
        {
            aux[0]='0';
            aux[1]='1';
            if(aux[4]=='9')
            {
                aux[3]='1';
                aux[4]='0';
            }
            else
                aux[4]++;
        }
        else
            aux[1]++;
    }
    strcpy(this->data,aux);
    return *this;
}
Concert Concert::operator++(int)
{
    Concert aux(*this);
    ++*this;
    return aux;
}
bool Concert::operator==(const Concert& obj)
{
    return this->lucrareMuzicala==obj.lucrareMuzicala;
}
bool Concert::operator<(const Concert& obj)
{
    int a=0,b=0;
    char*aux=new char[6];
    strcpy(aux,this->data);
    a=((((aux[3]-'0')*10)+(aux[4]-'0'))*10+(aux[0]-'0'))*10+(aux[1]-'0');
    b=((((obj.data[3]-'0')*10)+(obj.data[4]-'0'))*10+(obj.data[0]-'0'))*10+(obj.data[1]-'0');
    return a<b;

}
bool Concert::operator>(const Concert& obj)
{
    int a=0,b=0;
    char*aux=new char[6];
    strcpy(aux,this->data);
    a=((((aux[3]-'0')*10)+(aux[4]-'0'))*10+(aux[0]-'0'))*10+(aux[1]-'0');
    b=((((obj.data[3]-'0')*10)+(obj.data[4]-'0'))*10+(obj.data[0]-'0'))*10+(obj.data[1]-'0');
    return a>b;
}
Concert::operator string()
{
    return this->lucrareMuzicala;
}
float Concert::operator[](int x)
{
    if(this->sala=='m')
    {
        if(x<0 || x>130)
            throw runtime_error("Index invalid");
        else
            return this->pretLocuri[x];
    }
    if(this->sala=='M')
    {
        if(x<0 || x>260)
            throw runtime_error("Index invalid");
        else
            return this->pretLocuri[x];
    }
    throw runtime_error("Eroare daorita salii gresite");

}
double operator+(Spectator obj1,Concert obj2)
{
    int i=0;
    string l=obj1.getloc();
    string res ="";
    while(isdigit(l[i]))
    {
        i++;

    }
    res+=l[i];
    if(obj2.sala=='M')
    {

        if(extrage(l)<=10 && extrage(l)>=1)///a-h=100lei, i,j,k,l,n,o= 80.3lei, m,p,q,r,s,t=60.2lei, u-z=85.5lei
        {
            if(res>="a" && res<="h")/// randurile din fata
                return 100.0;
            if(res=="i" || res=="j" || res=="k" || res=="l" || res=="n" || res=="o")///randurile putin mai in spate
                return 80.3;
            if(res=="m" || res=="p" || res=="q" || res=="r" || res=="s" || res=="t")///randurile din spate
                return 60.2;
            if(res>="u" && res<="z")///lojele
                return 85.5;
        }
    }
    if(obj2.sala=='m')
    {
        if(extrage(l)<=5 && extrage(l)>=1)///a-l=52.8lei,m-t=45.2lei,u-z=40.1lei.
        {
            if(res>="a" && res<="l")/// randurile din fata
                return 52.8;
            if(res>="m" && res<="t")/// randurile de la mijloc
                return 45.2;
            if(res>="u" && res<="z")/// randurile din spate
                return 40.1;
        }
    }
    throw runtime_error("Eroare daorita locului gresit");
}
double operator+(Concert obj2,Spectator obj1)
{
    return obj1+obj2;
}
Concert::~Concert()
{
    if(this->data != NULL)
    {
        delete[] this->data;
        this->data = NULL;

    }
    if(this->ora != NULL)
    {
        delete[] this->ora;
        this->ora = NULL;

    }
    if(this->pretLocuri != NULL)
    {
        delete[] this->pretLocuri;
        this->pretLocuri = NULL;

    }
    this->sala = '_';
    this->lucrareMuzicala="Fara nume";
    //cout<<'\n'<<"destructor"<<numarConcerte;
    numarConcerte--;

}


class Orchestra
{
    string numeOrchestra;
    string dirijor;
    string concertMaestru;
    int nrMembrii;
public:
    ///constructori
    Orchestra();
    Orchestra(string numeOrchestra, string dirijor, string concertMaestru,int nrMembrii);
    Orchestra(const Orchestra& obj);
    ///operatori
    Orchestra& operator = (const Orchestra&);
    friend ostream& operator << (ostream& out, const Orchestra& obj);
    friend istream& operator >> (istream& in, Orchestra& obj);
    Orchestra& operator++();/// operator ++obj
    Orchestra operator++(int);/// operator obj++
    Orchestra operator+(int);///obj+x
    friend Orchestra operator+(int, Orchestra);///x+obj
    Orchestra operator-(int);///obj-x
    bool operator==(const Orchestra&);
    bool operator<(const Orchestra&);
    bool operator>(const Orchestra&);
    operator string();
    string operator[](int);

    ///metode
    /// cate orchestre a mai dirijat dirijorul; NUMAR
    void nrAparitii(map<string,unsigned int> mp,string nume);
    ///Set+Get
    string getnumeOrchestra()
    {
        return this->numeOrchestra;
    }
    string getdirijor()
    {
        return this->dirijor;
    }
    string getconcertMaestru()
    {
        return this->concertMaestru;
    }
    int getnrMembrii()
    {
        return this->nrMembrii;
    }

    void setnumeOrchestra(string nume)
    {
        this->numeOrchestra=nume;
    }
    void setdirijor(string diri)
    {
        this->dirijor=diri;
    }
    void setconcertMaestru(string maestru)
    {
        this->concertMaestru=maestru;
    }
    void setnrMembrii(int mem)
    {
        this->nrMembrii=mem;
    }
    ///Destructor
    ~Orchestra();
};
void Orchestra::nrAparitii(map<string,unsigned int> mp,string nume)
{
    cout<<"Dirijorul "<<nume<<" a dirijat "<<mp[nume]<<" orchestre.\n";
}
Orchestra::Orchestra()
{
    numeOrchestra="Necunoscut";
    dirijor="Necunoscut";
    concertMaestru="Necunoscut";
    nrMembrii=0;
}
Orchestra::Orchestra(string numeOrchestra, string dirijor, string concertMaestru,int nrMembrii)
{
    this->numeOrchestra=numeOrchestra;
    this->dirijor=dirijor;
    this->concertMaestru=concertMaestru;
    this->nrMembrii=nrMembrii;
}
Orchestra::Orchestra(const Orchestra& obj)
{
    this->numeOrchestra=obj.numeOrchestra;
    this->dirijor=obj.dirijor;
    this->concertMaestru=obj.concertMaestru;
    this->nrMembrii=obj.nrMembrii;
}
Orchestra& Orchestra::operator = (const Orchestra& obj)
{
    if(this != &obj)
    {

        this->numeOrchestra=obj.numeOrchestra;
        this->dirijor=obj.dirijor;
        this->concertMaestru=obj.concertMaestru;
        this->nrMembrii=obj.nrMembrii;
    }
    return *this;
}
istream& operator >> (istream& in, Orchestra& obj)
{
    cout<<"Introduceti numele orchestrei: ";
    getline(in,obj.numeOrchestra);
    cout<<"Introduceti numele dirijorului: ";
    getline(in,obj.dirijor);
    cout<<"Introduceti numele concertmaestrului: ";
    getline(in,obj.concertMaestru);
    cout<<"Introduceti numarul de membrii din "<<obj.numeOrchestra<<": ";
    in>>obj.nrMembrii;
    in.get();
    return in;

}
ostream& operator << (ostream& out, const Orchestra& obj)
{
    out<<"Orchestra: "<<obj.numeOrchestra;
    out<<" cu "<<obj.nrMembrii<<" de membrii"<<'\n';
    out<<"Avand ca dirijor pe maestrul: "<<obj.dirijor<<'\n';
    out<<"Alaturi de concertmaestrul: "<<obj.concertMaestru<<'\n';
    return out;

}
Orchestra& Orchestra::operator++()
{
    this->nrMembrii++;
    return *this;
}
Orchestra Orchestra::operator++(int)
{
    Orchestra aux(*this);
    this->nrMembrii++;
    return aux;
}
Orchestra Orchestra::operator+(int x)
{
    Orchestra aux(*this);
    aux.nrMembrii+=x;
    return aux;
}
Orchestra operator+(int x, Orchestra obj)
{
    return obj+x;
}
Orchestra Orchestra::operator-(int x)
{
    Orchestra aux(*this);
    aux.nrMembrii-=x;
    return aux;
}
bool Orchestra::operator==(const Orchestra& obj)
{
    return this->numeOrchestra==obj.numeOrchestra;
}
bool Orchestra::operator<(const Orchestra& obj)
{
    return this->nrMembrii<obj.nrMembrii;
}
bool Orchestra::operator>(const Orchestra& obj)
{
    return this->nrMembrii>obj.nrMembrii;
}
Orchestra::operator string()
{
    return this->numeOrchestra;
}
string Orchestra::operator[](int i)
{
    if(i==1)
        return this->numeOrchestra;
    if(i==2)
        return this->dirijor;
    if(i==3)
        return this->concertMaestru;
    return "Indexul este gresit";
}
Orchestra::~Orchestra()
{
    this->numeOrchestra="Fara nume";
    this->dirijor="Fara nume";
    this->concertMaestru="Fara nume";
    this->nrMembrii=0;
}




class Solist
{
    string numeSolist;
    bool participare;
    int varstaParticipare;
    string instrument;
    string taraStudii;
public:
    ///metode
    /// la ce varsta a cantat prima data;
    unsigned int FisrtTime (map<string,unsigned int> mp,string nume);

    ///constructori
    Solist();
    Solist(string numeSolist, string instrument, string taraStudii, int varstaParticipare, bool participare);
    Solist(const Solist&);
    ///operatori
    Solist& operator = (const Solist&);
    friend ostream& operator << (ostream& out, const Solist& obj);
    friend istream& operator >> (istream& in, Solist& obj);
    Solist& operator++();/// operator ++obj
    Solist operator++(int);/// operator obj++
    string operator+(const Solist& );/// fiecare solisti vor forma 2 duet sau duo
    friend string operator+(string, Solist);///vom adunca solisti ca muzicieni formand astfel asambluri de muzica de camera
    friend string operator-(string, Solist);///pentru scadere fiecare ansamblu va scadea la numar formand un ansamblu mai mic
    friend string operator+(Solist,string); ///vom adunca solisti ca muzicieni formand astfel asambluri de muzica de camera
    bool operator==(const Solist&);
    bool operator<(const Solist&);
    bool operator>(const Solist&);
    string operator[](int);/// index operator
    operator int();/// cast operator

    ///Set+Get
    string getnumeSolist()
    {
        return this->numeSolist;
    }
    bool getparticipare()
    {
        return this->participare;
    }
    int getvarsta()
    {
        return this->varstaParticipare;
    }
    string getinstrument()
    {
        return this->instrument;
    }
    string gettaraStudii()
    {
        return this->taraStudii;
    }


    void setnumeSolist(string nume)
    {
        this->numeSolist=nume;
    }
    void setparticipare(bool a)
    {
        this->participare=a;
        this->varstaParticipare=0;
    }
    void setvarsta(int v)
    {
        this->varstaParticipare=v;
    }
    void setinstrument(string instrum)
    {
        this->instrument=instrum;
    }
    void settaraStudii(string tara)
    {
        this->taraStudii=tara;
    }

    ///destructor
    ~Solist();
};
unsigned int Solist::FisrtTime(map<string,unsigned int> mp,string nume)
{
    return mp[nume];
}
Solist::Solist()
{
    numeSolist="Necunoscut";
    instrument="Necunoscut";
    taraStudii="Necunoscuta";
    varstaParticipare=0;
    participare=false;
}
Solist::Solist(string numeSolist,string instrument, string taraStudii,int varstaParticipare,bool participare)
{
    this->numeSolist=numeSolist;
    this->participare=participare;
    this->varstaParticipare=varstaParticipare;
    this->instrument=instrument;
    this->taraStudii=taraStudii;
}
Solist::Solist(const Solist& obj)
{
    this->numeSolist=obj.numeSolist;
    this->participare=obj.participare;
    this->varstaParticipare=obj.varstaParticipare;
    this->instrument=obj.instrument;
    this->taraStudii=obj.taraStudii;
}
Solist& Solist::operator = (const Solist& obj)
{
    if(this != &obj)
    {
        this->numeSolist=obj.numeSolist;
        this->participare=obj.participare;
        this->varstaParticipare=obj.varstaParticipare;
        this->instrument=obj.instrument;
        this->taraStudii=obj.taraStudii;
    }
    return *this;
}
istream& operator >> (istream& in, Solist& obj)
{
    cout<<"Introduceti numele Solistului: ";
    getline(in,obj.numeSolist);
    cout<<"Introduceti instrumentul cu care canta: ";
    getline(in,obj.instrument);
    cout<<"Introduceti tara in care si-a perfectionat studiile: ";
    getline(in,obj.taraStudii);
    cout<<"Introduceti 1 daca a participat ca solist sau 0 in caz contrar: ";
    in >> obj.participare;
    if(obj.participare)
    {
        cout<<"Introduceti varsta la care a concertat: ";
        in>>obj.varstaParticipare;
    }
    in.get();
    return in;

}
ostream& operator << (ostream& out, const Solist& obj)
{
    out<<"Solistul: "<<obj.numeSolist<<'\n';
    out<<"Instrument: "<<obj.instrument<<'\n';
    out<<"Tara studii: "<<obj.taraStudii<<'\n';
    return out;

}
Solist& Solist::operator++()
{
    this->varstaParticipare++;
    return *this;
}
Solist Solist::operator++(int)
{
    Solist aux(*this);
    this->varstaParticipare++;
    return aux;
}
bool Solist::operator<(const Solist& obj)
{
    return this->varstaParticipare<obj.varstaParticipare;
}

bool Solist::operator>(const Solist& obj)
{
    return this->varstaParticipare>obj.varstaParticipare;
}

bool Solist::operator==(const Solist& obj)
{
    return this->numeSolist==obj.numeSolist;
}

string Solist::operator+(const Solist& obj)
{
    return "duet";
}
string operator+(string s, Solist obj)
{
    if(s=="duet")
        return "tertet";
    if(s=="tertet")
        return "quartet";
    if(s=="quartet")
        return "quintet";
    if(s=="quintet")
        return "sextet";
    if(s=="sextet")
        return "septet";
    if(s=="septet")
        return "octet";
}
string operator+(Solist obj,string s)
{
    if(s=="duet")
        return "tertet";
    if(s=="tertet")
        return "quartet";
    if(s=="quartet")
        return "quintet";
    if(s=="quintet")
        return "sextet";
    if(s=="sextet")
        return "septet";
    if(s=="septet")
        return "octet";
    return "ansamblul este prea mare";
}
string operator-(string s, Solist obj)
{

    if(s=="tertet")
        return "duet";
    if(s=="quartet")
        return "tertet";
    if(s=="quintet")
        return "quartet";
    if(s=="sextet")
        return "quintet";
    if(s=="septet")
        return "sextet";
    if(s=="octet")
        return "septet";
}
string Solist::operator[](int x)
{
    if(x==1)
        return this->numeSolist;
    if(x==2)
        return this->instrument;
    if(x==3)
        return this->taraStudii;
    else
        return "Indexul este gersit";
}
Solist::operator int()
{
    return this->varstaParticipare;
}
Solist::~Solist()
{
    this->numeSolist="Fara nume";
    this->instrument="Fara nume";
    this->taraStudii="Fara nume";
    this->varstaParticipare=0;
    this->participare=false;
}




int main()
{


    ///**
    map<string, bool> ocupat;
    map<string,unsigned int> aparitii;
    map<string,unsigned int> aparitie;
    int n;
    //cout<<"Introduceti numarul de spectatori: ";
    cout<<"Va felicit ca ati ales sa va delectati mergand la un concert!\nCate persoane doriti sa mergeti la concert?\n";

    cin>>n;
    ///cin.get();
    cout<<"Introduceti 1 daca doriti sa alegeti unul din concertele programate, sau 0 daca doriti sa introduceti dumneavoastra altele.\n";
    bool alegere0;
    cin>>alegere0;
    int m=0;
    Spectator v[100];
    Orchestra o[100];
    Solist s[100];
    Concert konzert[100];
    int v1[1001],v2[1001];
    char* p="1";
    int j=1;
    int l=1;
    int k=0;
    int i;
    if(alegere0)
    {


        // cout<<"La ce concert doriti sa mergeti?\n";
        Concert k0('M', "18:00", "25.03", "Beethoven Concerto for piano No.3");
        Concert k1('M', "19:00", "30.04", "Haydn Trumpet Concerto in Eb");
        Concert k2('M', "16:00", "03.05", "Dvorak Cello Concerto in B minor, Op. 104");
        Concert k3('m', "17:30", "10.05", "Mozart Klarineto Concerto KV 622");
        Concert k4('M', "18:00", "25.05", "Mozart Serenade No 10 for Winds 'Gran Partita'");
        Concert k5('m', "20:00", "30.06", "Sphor clarinet concerto  no.1");
        Concert k6('m', "19:00", "15.07", "Crusell clarinet concerto no.2 en fa mineur, Op. 5");
        Concert k7('M', "17:30", "08.08", "Mozart Concerto in D major KV 314");
        konzert[0]=k0;
        konzert[1]=k1;
        konzert[2]=k2;
        konzert[3]=k3;
        konzert[4]=k4;
        konzert[5]=k5;
        konzert[6]=k6;
        konzert[7]=k7;

        Orchestra o0("Orchestra filarmonica Bucuresti", "Carlos Kleiber", "Avy Abramovici", 30);
        Orchestra o1("Orchestra filarmonica Gerorge Enescu", "Zubin Mehta", "Ion Albeșteanu", 33);
        Orchestra o2("Orchestra filarmonica Sibiu", "Riccardo Muti", "Dan Andrei Aldea", 25);
        Orchestra o3("Orchestra nationala radio","Sergiu Celibidache", "Alexander Bălănescu", 33);
        Orchestra o4("Orchestra operei nationale Bucuresti", "Klaus Makela", "Ion Covaci", 30);
        Orchestra o5("Orchestra filarmonica Pitesti ", "Gustavo Dudamel", "Corina Belcea", 26);
        Orchestra o6("Orchestra filarmonica Ploiesti 'Paul Constantinescu'", "Cristian Macelaru", "Vladimir Cosma", 25);
        Orchestra o7("Orchestra filarmonica de Stat Transilvania din Cluj-Napoca", "Alexandru Ilie", "Razvan Stoica", 30);
        o[0]=o0;
        o[1]=o1;
        o[2]=o2;
        o[3]=o3;
        o[4]=o4;
        o[5]=o5;
        o[6]=o6;
        o[7]=o7;

        Solist s0("Teodora Chirca", "pian", "Romania", 27,1);
        Solist s1("Alison Balsom", "trompeta", "SUA", 33,1);
        Solist s2("Cornelius Zirbo", "violoncel", "Franta", 24,1);
        Solist s3("Catalin Caraulasu", "clarinet", "Romania", 20,1);
        Solist s4("Eleonora Bordanc", "violoncel", "Romania", 26,0);
        Solist s5("Martin Frost", "clarinet", "Suedia", 51,1);
        Solist s6("Kevin Spagnolo", "clarinet", "Suedia", 25,1);
        Solist s7("Magali Mosnier", "flaut", "Franta", 30,1);
        s[0]=s0;
        s[1]=s1;
        s[2]=s2;
        s[3]=s3;
        s[4]=s4;
        s[5]=s5;
        s[6]=s6;
        s[7]=s7;
        for( i=0; i<8 ; i++)//konzert[0].getnumarConcerte()
        {
            aparitii[o[i].getdirijor()]++;
            if(!aparitie[s[i].getnumeSolist()])
                aparitie[s[i].getnumeSolist()]=s[i].getvarsta();
            else
            {
                if(s[i].getvarsta()<aparitie[s[i].getnumeSolist()] && s[i].getvarsta()>0 && s[i].getparticipare()==true)
                    aparitie[s[i].getnumeSolist()]=s[i].getvarsta();
            }
            p=konzert[i].getData();
            if(konzert[i].getSala()=='m')
            {

                for(k=0; k<strlen(p) && p[k]<58; k++)
                    if(k<2)
                    {
                        v1[j++]=p[k]-'0';

                    }
                    else if(k>2)
                    {
                        v1[j++]=p[k]-'0';

                    }
            }
            else if (konzert[i].getSala()=='M')
            {

                for(k=0; k<strlen(p) && p[k]<58; k++)
                    if(k<2)
                    {
                        v2[l++]=p[k]-'0';

                    }
                    else if(k>2)
                    {
                        v2[l++]=p[k]-'0';

                    }
            }

        }



    }
    else
    {
        cout<<"Introduceti numarul de concerte,solisti si orchestre pe care vreti sa le introduceti chiar in aceasta ordine.\n";
        cin>>m;
        cin.get();
        for( i=0; i<m; i++)
        {
            cin>>konzert[i];
            cout<<"Solistul aferent concertului\n";
            cin>>s[i];
            cout<<"Orchestra aferenta concertului\n";
            cin>>o[i];


        }
    }
    bool alegere5=false;
    if(m)
    {
        cout<<"Doriti sa modificati/stergeti datele despre concerte,orchestre sau solisti?\nIntroduceti 1 in pentru un raspuns afirmativ sau 0 pentru un raspuns negativ\n";

        cin>>alegere5;
        if(alegere5)
        {

            string alegere6;
            cout<<"Doriti sa stergeti sau sa modificati? Pentru stergere inserati 'stergere', iar pentru modificare inserati 'modificare' \n";
            cin.get();
            getline(cin,alegere6);
            if(alegere6=="stergere")
            {
                int alegere8;
                cout<<"Introduceti numarul pentru concert, orchestra, respectiv solist pe care vreti sa le stergeti\n";
                cin>>alegere8;
                Concert aux1;
                Orchestra aux2;
                Solist aux3;
                for(i=alegere8-1; i<m-1; i++) ///ducem elemntul la sf prin interschimbare si scadem sf cu 1
                {
                    aux1=konzert[i];
                    konzert[i]=konzert[i+1];
                    konzert[i+1]=aux1;
                    aux2=o[i];
                    o[i]=o[i+1];
                    o[i+1]=aux2;
                    aux3=s[i];
                    s[i]=s[i+1];
                    s[i+1]=aux3;
                }
                m--;



            }
            if(alegere6=="modificare")
            {
                string alegere7;
                cout<<"Pentru concert introduceti concert, pentru orchestra introduceti orchestra, pentru solist introduceti solist\n";
                //cin.get();
                getline(cin,alegere7);
                if(alegere7=="concert")
                {
                    int alegere8;
                    cout<<"Introduceti numarul pentru concert pe care vreti sa il modificati.\n";
                    cin>>alegere8;
                    cin.get();
                    cin>>konzert[alegere8-1];
                }
                if(alegere7=="orchestra")
                {
                    int alegere8;
                    cout<<"Introduceti numarul pentru orchestra pe care vreti sa o modificati.\n";
                    cin>>alegere8;
                    cin.get();
                    cin>>o[alegere8-1];
                }
                if(alegere7=="solist")
                {
                    int alegere8;
                    cout<<"Introduceti numarul pentru solistul pe care vreti sa il modificati.\n";
                    cin>>alegere8;
                    cin.get();
                    cin>>s[alegere8-1];
                }

            }
            for(i=0;i<m;i++)
        {
            aparitii[o[i].getdirijor()]++;
            if(!aparitie[s[i].getnumeSolist()])
                aparitie[s[i].getnumeSolist()]=s[i].getvarsta();
            else
            {
                if(s[i].getvarsta()<aparitie[s[i].getnumeSolist()] && s[i].getvarsta()>0 && s[i].getparticipare()==true)
                    aparitie[s[i].getnumeSolist()]=s[i].getvarsta();
            }
            p=konzert[i].getData();
            if(konzert[i].getSala()=='m')
            {

                for(k=0; k<strlen(p) && p[k]<58; k++)
                    if(k<2)
                    {
                        v1[j++]=p[k]-'0';

                    }
                    else if(k>2)
                    {
                        v1[j++]=p[k]-'0';

                    }
            }
            else if (konzert[i].getSala()=='M')
            {

                for(k=0; k<strlen(p) && p[k]<58; k++)
                    if(k<2)
                    {
                        v2[l++]=p[k]-'0';

                    }
                    else if(k>2)
                    {
                        v2[l++]=p[k]-'0';

                    }
            }
        }
        }


    }

    cout<<"In functie de ce caracteristica vreti sa alegeti concertul?\nDirijor,solist,orchestra sau lucrare muzicala?\n";
    string alegere1;
    if(!m || !alegere5)
        cin.get();
    getline(cin,alegere1);
    string alegere2;


    if(alegere1=="dirijor" || alegere1=="Dirijor")
    {
        cout<<"Introduceti numele dirijorului: ";
       // cin.get();
        getline(cin,alegere2);
        if(!m)
        {
            for( i=0; i<8; i++)
            {
                if(o[i].getdirijor()==alegere2)
                    break;
                if(i==7)
                    cout<<"Numele dirijorului introdus nu a corespuns cu datele reale\n";
            }
        }
        else
        {
            for( i=0; i<m; i++)
            {
                if(o[i].getdirijor()==alegere2)
                    break;
                if(i==m-1)
                    cout<<"Numele dirijorului introdus nu a corespuns cu datele reale\n";
            }
        }

    }
    if(alegere1=="solist")
    {
        cout<<"Introduceti numele solistului: ";
        getline(cin,alegere2);
        if(!m)
        {
            for( i=0; i<8; i++)
            {
                if(s[i].getnumeSolist()==alegere2)
                    break;
                if(i==7)
                    cout<<"Numele solistului introdus nu a corespuns cu datele reale\n";
            }
        }
        else
        {
            for( i=0; i<m; i++)
            {
                if(s[i].getnumeSolist()==alegere2)
                    break;
                if(i==m-1)
                    cout<<"Numele solistului introdus nu a corespuns cu datele reale\n";
            }
        }
    }
    if(alegere1=="orchestra")
    {
        cout<<"Introduceti numele orchestrei: ";
        getline(cin,alegere2);
        if(!m)
        {
            for( i=0; i<8; i++)
            {
                if(o[i].getnumeOrchestra()==alegere2)
                    break;
                if(i==7)
                    cout<<"Numele orchestrei introdus nu a corespuns cu datele reale\n";
            }
        }
        else
        {
            for( i=0; i<m; i++)
            {
                if(o[i].getnumeOrchestra()==alegere2)
                    break;
                if(i==m-1)
                    cout<<"Numele orchestrei introdus nu a corespuns cu datele reale\n";
            }
        }
    }
    if(alegere1=="lucrare muzicala")
    {
        cout<<"Introduceti numele lucrarii muzicale: ";
        getline(cin,alegere2);
        if(!m)
        {
            for( i=0; i<8; i++)
            {
                if(konzert[i].getlucrareMuzicala()==alegere2)
                    break;
                if(i==7)
                    cout<<"Numele lucrarii muzicale introdus nu a corespuns cu datele reale\n";
            }
        }
        else
        {
            for( i=0; i<m; i++)
            {
                if(konzert[i].getlucrareMuzicala()==alegere2)
                    break;
                if(i==m-1)
                    cout<<"Numele lucrarii muzicale introdus nu a corespuns cu datele reale\n";
            }
        }
    }
    int cautat=i;
    cout<<"In acest moment va trebui sa alegeti "<<n<<" locuri.\n";
    for( j=0; j<n; j++)
    {



        cout<<"Locurile disponibile din sala concertului la care vreti sa mergeti sunt: ";
        if(konzert[cautat].getSala()=='m')
        {
            string loc1="";
            for(char c='a'; c<='z'; c++)
                for(i=1; i<=5; i++)
                {
                    loc1=to_string(i)+c;
                    if(ocupat[loc1]==false)
                        cout<<loc1<<" ";
                }
            cout<<"Preturile sunt urmatoarele:\nPentru Categoria 1 (a-l):52.8 lei\nPentru Categoria 2 (m-t):45.2 lei\nPentru Categoria 3 (u-z):40.1 lei\n";

        }
        else
        {
            string loc1="";
            for(char c='a'; c<='z'; c++)
                for(i=1; i<=10; i++)
                {
                    loc1=to_string(i)+c;
                    if(ocupat[loc1]==false)
                        cout<<loc1<<" ";
                }
            cout<<"Preturile sunt urmatoarele:\nPentru Categoria 1 (a-h):100 lei\nPentru Categoria 2 (i,j,k,l,n,o):80.3 lei\nPentru Categoria 3 (m,p,q,r,s,t):60.2 lei\nPentru loje (u-z):85.5 lei\n";

        }
        cin>>v[j];
        ocupat[v[j].getloc()]=true;
    }
    cout<<"Pentru a afla mai multe detalii introduceti 1 sau 0 in caz contrar.\n";
    bool alegere3;
    cin>>alegere3;
    if(alegere3)
    {
        int alegere4;
        cout<<"Ce doriti sa aflati?\n";
        cout<<"Optiunea 1: Daca aveti un loc liber langa dumneavoastra.\n";
        cout<<"Optiunea 2: Aflati urmatorul concert de la o anumita data.\n";
        cout<<"Optiunea 3: Cate orchestre a dirijat dirijorul care va fi la concert?\n";
        cout<<"Optiunea 4: La ce varsta a concertat prima data solistul care va fi la concert.\n";
        cout<<"Optiunea 5: Ce ansamblu cameral se poate forma cu toti solistii din datele existente?\n";
        cin>>alegere4;
        if(alegere4==1)
        {
            string loc1;
            cout<<"Introduceti locul: ";
            cin.get();
            getline(cin,loc1);
            v[0].locuriLibereLanga(ocupat,loc1);
        }
        if(alegere4==2)
        {
            cout<<"Introduceti data de la care doriti sa aflati urmatorul concert: ";
            cin>>p;
            swap(p[2],p[3]);
            swap(p[3],p[4]);
            p[strlen(p)-1]=NULL;
            swap(p[0],p[2]);
            swap(p[1],p[3]);
            char c;
            cout<<"Introduceti sala in care se va tine concertul: ";
            cin>>c;
            if(c=='m')
                cout<<konzert[0].nextTime(v1,c,j,p)<<endl;
            else if(c=='M')
                cout<<konzert[0].nextTime(v2,c,l,p)<<endl;
        }
        if(alegere4==3)
        {
            o[0].nrAparitii(aparitii,o[cautat].getdirijor());
        }
        if(alegere4==4)
        {

            if(s[0].FisrtTime(aparitie,s[cautat].getnumeSolist()))
                cout<<s[cautat].getnumeSolist()<<" a concertat prima data la varsta de "<<s[0].FisrtTime(aparitie,s[cautat].getnumeSolist())<<" de ani.\n";
            else
                cout<<s[cautat].getnumeSolist()<<" nu a concertat ca solist pana acum.\n";
        }
        if(alegere4==5)
        {
            string ansamblu;
            if(!m)
            {
                ansamblu=s[0]+s[1];
                for(i=2; i<8; i++)
                {
                    ansamblu=ansamblu+s[i];
                }
            }
            else
            {
                ansamblu=s[0]+s[1];
                for(i=2; i<m; i++)
                {
                    ansamblu=ansamblu+s[i];
                }

            }
            cout<<"Ansamblul cameral format este "<<ansamblu<<endl;
        }


    }

    double pret=0;

    for(i=0; i<n; i++)
        pret=pret+(konzert[cautat]+v[i]);
    if(n==1)
        cout<<"Locul: "<<v[0].getloc()<<" la concertul din data de "<<konzert[cautat].getData()<<" 2025 la ora "<<konzert[cautat].getOra()<<" unde se va interpreta "<<konzert[cautat].getlucrareMuzicala()<<" de catre "<<o[cautat].getnumeOrchestra()<<" alaturi de dirijorul "<<o[cautat].getdirijor()<<" si solistul "<<s[cautat].getnumeSolist()<<"."<<endl;
    else
    {
        cout<<"Locurile: ";
        for(i=0; i<n; i++)
        {
            cout<<v[i].getloc()<<" ";
        }
        cout<<"la concertul din data de "<<konzert[cautat].getData()<<" 2025 la ora "<<konzert[cautat].getOra()<<" unde se va interpreta "<<konzert[cautat].getlucrareMuzicala()<<" de catre "<<o[cautat].getnumeOrchestra()<<" alaturi de dirijorul "<<o[cautat].getdirijor()<<" si solistul "<<s[cautat].getnumeSolist()<<"."<<endl;
    }
    cout<<"Suma totala a biletului/biletelor este: "<<pret<<" lei.\n";

    cout<<"Va multumesc pentru atentia acordata, va mai astept si alta data, multa sanatate!";




///pentru M :a-h=100lei, i,j,k,l,n,o= 80.3lei, m,p,q,r,s,t=60.2lei, u-z=85.5lei. pentru m: a-l=52.8lei,m-t=45.2lei,u-z=40.1lei.


///v[0].locuriLibereLanga(ocupat,v[0].getloc());
    ///cout<<endl;

    ///cout << v[5].getloc()<<endl;

    // */
    /**
    Concert konzert[100];
    char* p="1";
    int n;
    cout<<"Introduceti numarul de concerte: ";
    cin>>n;
    cin.get();
    int v1[1001],v2[1001];


    int j=1;
    int l=1;
    int k=0;
    for(int i=0; i<n ; i++)//konzert[0].getnumarConcerte()
    {
       cin>>konzert[i];
       cout<<endl<<konzert[i].getpretLocuri()[60];
       p=konzert[i].getData();
       if(konzert[i].getSala()=='m')
       {

           for(k=0; k<strlen(p) && p[k]<58; k++)
               if(k<2)
               {
                   v1[j++]=p[k]-'0';

               }
               else if(k>2)
               {
                   v1[j++]=p[k]-'0';

               }
       }
       else if (konzert[i].getSala()=='M')
       {

           for(k=0; k<strlen(p) && p[k]<58; k++)
               if(k<2)
               {
                   v2[l++]=p[k]-'0';

               }
               else if(k>2)
               {
                   v2[l++]=p[k]-'0';

               }
       }
       konzert[i]++;
       cout<<endl<<konzert[i];

    }
    //  cout<<konzert[0][261];
    //cout<<(konzert[0]==konzert[1])<<endl<<(konzert[0]<konzert[1])<<endl<<(konzert[0]>konzert[1]);


    for(int i=1; i<j; i++)
       cout<<v1[i]<<" ";
    cout<<'\n';
    for(int i=1; i<l; i++)
       cout<<v2[i]<<" ";
    cout<<"Introduceti data de la care doriti sa aflati urmatorul concert: ";
    cin>>p;
    swap(p[2],p[3]);
    swap(p[3],p[4]);
    p[strlen(p)-1]=NULL;
    swap(p[0],p[2]);
    swap(p[1],p[3]);
    char c;
    cout<<"Introduceti sala in care se va tine concertul: ";
    cin>>c;
    if(c=='m')
       cout<<konzert[0].nextTime(v1,c,j,p);
    else if(c=='M')
       cout<<konzert[0].nextTime(v2,c,l,p);
    */
    /**
    map<string,unsigned int> aparitii;
    Orchestra o[100];
    o[1].setnrMembrii(10);
    //cout<<o[1]<<endl<<(o[1]>o[0]);
    int n;
    cout<<"Introduceti numarul de orchestre: ";
    cin>>n;
    cin.get();
    for(int i=0; i<n; i++)
    {
        cin>>o[i];
        aparitii[o[i].getdirijor()]++;
        cout<<o[i];
    }
    string numedirijor;
    cout<<"Introduceti numele dirijorului pentru care doriti sa stiti numarul de orchestre dirijate: ";
    getline(cin,numedirijor);
    o[0].nrAparitii(aparitii,numedirijor);
    */
    /**
    Solist solisti[100];
    map<string,unsigned int> aparitie;
    int n;
    string grup=solisti[0]+solisti[1]+solisti[2]+solisti[3]+solisti[4];
    cout<<solisti[0]+grup<<'\n';
    cout<<grup-solisti[0]<<'\n';

    cout<<"Introduceti numarul de solisti: ";
    cin>>n;
    cin.get();
    for(int i=0; i<n; i++)
    {
       cin>>solisti[i];
       if(i>=1)
           cout<<(solisti[i]>solisti[i-1])<<'\n';
       cout<<'\n'<<solisti[i].getvarsta()<<'\n';
       if(!aparitie[solisti[i].getnumeSolist()])
           aparitie[solisti[i].getnumeSolist()]=solisti[i].getvarsta();
       else
       {
           if(solisti[i].getvarsta()<aparitie[solisti[i].getnumeSolist()] && solisti[i].getvarsta()>0 && solisti[i].getparticipare()==true)
               aparitie[solisti[i].getnumeSolist()]=solisti[i].getvarsta();
       }
       cout<<solisti[i];
    }
    string nume;
    cout<<"Introduceti numele solistului pentru care vreti afla prima varsta unde a concertat: ";
    getline(cin,nume);
    if(solisti[0].FisrtTime(aparitie,nume))
       cout<<nume<<" a concertat prima data la varsta de "<<solisti[0].FisrtTime(aparitie,nume)<<" de ani.";
    else
       cout<<nume<<" nu a concertat ca solist pana acum.";
       cout<<(int)solisti[0];

    */
    return 0;
}
