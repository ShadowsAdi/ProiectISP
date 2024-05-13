#include <iostream>
#include <string>
#include <list>

using namespace std;

class Depou;
class Ruta;
class Angajat;

class Coordonate
{   
    private:
        double latitudine;
        double longitudine;
        double altitudine;
        string strada;
        int numar;
        string sector;
        string oras;
        string judet;
        string tara;
    public:
        Coordonate(double latitudine, double longitudine, double altitudine, string strada, int numar, string sector, string oras, string judet, string tara)
        {
            this->latitudine = latitudine;
            this->longitudine = longitudine;
            this->altitudine = altitudine;
            this->strada = strada;
            this->numar = numar;
            this->sector = sector;
            this->oras = oras;
            this->judet = judet;
            this->tara = tara;
        }
};

enum tip_angajat
{
    sofer = 0,
    dispecer,
    mentenanta,
    birou
};

enum tipMentenanta
{
    S = 0,
    C,
    Mu,
    Ma,
    Mg,
    ITP
};

enum tip_ruta
{
    neelec_bul = 0,
    neelec_strsec,
    neelec_mixt,
    elect_tr_bul,
    elect_tr_strsec,
    elect_tr_mixt,
    elect_trol_bul,
    elect_trol_strsec,
    elect_trol_mixt
};

enum tipOrientare
{
    punct_oprire = 0,
    punct_trecere
};

enum tipStatie
{
    tramvai = 0,
    autobuz
};


enum pozitieOrientare
{
    lateral_stanga = 0,
    lateral_dreapta,
    axul_drumului
};

enum tip_vehicul
{
    autobuzDiesel = 0,  
    autobuzElectric,
    autobuzHibrid,
    troleibuz,
    tr_mono_dir,
    tr_bidirectional
};

class coordonateOrientare
{
    private:
        double latitudine;
        double longitudine;
        double altitudine;
    public:
        coordonateOrientare(double latitudine, double longitudine, double altitudine)
        {
            this->latitudine = latitudine;
            this->longitudine = longitudine;
            this->altitudine = altitudine;
        }
};


class Data
{
    private:
        int zi;
        int luna;
        int an;
    public:
        Data(int zi, int luna, int an)
        {
            this->zi = zi;
            this->luna = luna;
            this->an = an;
        }
};

class Mentenanta
{
    private:
        tipMentenanta tip_mentenanta;
        Data *dataMentenanta;
    public:
        Mentenanta(tipMentenanta tip_mentenanta, Data *dataMentenanta)
        {
            this->tip_mentenanta = tip_mentenanta;
            this->dataMentenanta = dataMentenanta;
        }
};

class Vehicul
{
    private:
        int id;
        tip_vehicul tipVehicul;
        Depou *depouApartenenta;
        string numar_parc;
        string producator;
        string numeConstructie;
        Data *dataConstructiei;
        list<Mentenanta> mentenanta;
        Ruta *rutaArondata;
        Angajat *soferArondat;
        double lungime;
        int capacitateLocScaun;
        int capacitateTotala;
        coordonateOrientare *pozitieActuala;
        int numarPersoaneInVehicul;
        string linkCamereSupraveghere;
        string comentarii;
    public:
        Vehicul(int id, tip_vehicul tipVehicul, string numar_parc, string producator, string numeConstructie, Data *dataConstructiei, double lungime, int capacitateLocScaun, int capacitateTotala, coordonateOrientare *pozitieActuala, int numarPersoaneInVehicul, string linkCamereSupraveghere, string comentarii)
        {
            this->id = id;
            this->tipVehicul = tipVehicul;
            this->numar_parc = numar_parc;
            this->producator = producator;
            this->numeConstructie = numeConstructie;
            this->dataConstructiei = dataConstructiei;
            this->lungime = lungime;
            this->capacitateLocScaun = capacitateLocScaun;
            this->capacitateTotala = capacitateTotala;
            this->pozitieActuala = pozitieActuala;
            this->numarPersoaneInVehicul = numarPersoaneInVehicul;
            this->linkCamereSupraveghere = linkCamereSupraveghere;
            this->comentarii = comentarii;
        }
        
        void adaugareMentenanta(const Mentenanta& ment) 
        {
            mentenanta.push_back(ment);
        }
        
        void addDepou(Depou *depou)
        {
            this->depouApartenenta = depou;
        }
};

class punct_orientare
{
    private:
        int id;
        tipOrientare tip_punct;
        coordonateOrientare *coordonateXYZ;
        tipStatie tip_Statie;
        pozitieOrientare pozitie_pe_drum;
    public:
        punct_orientare(int id, tipOrientare tip_punct, tipStatie tip_Statie, pozitieOrientare pozitie_pe_drum)
        {
            this->id = id;
            this->tip_punct = tip_punct;
            this->tip_Statie = tip_Statie;
            this->pozitie_pe_drum = pozitie_pe_drum;
        }
        
        void addCoords(coordonateOrientare *coord)
        {
            this->coordonateXYZ = coord;
        }
};

class Traseu
{
    private:
        int id;
        list<punct_orientare> puncteOrientare;
        string directia_de_mers;
    public:
        Traseu(int id, list<punct_orientare> puncteOrientare, string directia_de_mers)
        {
            this->id = id;
            this->puncteOrientare = puncteOrientare;
            this->directia_de_mers = directia_de_mers;
        }
};

class Ruta
{
    private:
        int id;
        Depou *depouApartenenta;
        tip_ruta tipRuta;
        list<Vehicul> vehicule_active;
        list<Vehicul> vehicule_arondate;
        Traseu *traseu_urmarit;
        list<Traseu> trasee_posibile;
        string comentarii;
    public:
        Ruta(int id, tip_ruta tipRuta, list<Vehicul> vehicule_active, list<Vehicul> vehicule_arondate, list<Traseu> trasee_posibile, string comentarii)
        {
            this->id = id;
            this->tipRuta = tipRuta;
            this->vehicule_active = vehicule_active;
            this->vehicule_arondate = vehicule_arondate;
            this->trasee_posibile = trasee_posibile;
            this->comentarii = comentarii;
        }

        void addDepou(Depou* depou)
        {
            this->depouApartenenta = depou;
        }

        void addTraseu(Traseu* traseu)
        {
            this->traseu_urmarit = traseu;
        }
};

class Angajat
{   
    private:
        tip_angajat tipAngajat;
        Depou *depouApartenenta;
        Data *dataAngajarii;
        string nume;
        string prenume;
        Ruta *ruta_preferata;
        Vehicul *vehicul_preferat;
    public:
        Angajat(tip_angajat tipAngajat, Depou *depouApartenenta, Data *dataAngajarii, string nume, string prenume, Ruta *ruta_preferata, Vehicul *vehicul_preferat)
        {
            this->tipAngajat = tipAngajat;
            this->depouApartenenta = depouApartenenta;
            this->dataAngajarii = dataAngajarii;
            this->nume = nume;
            this->prenume = prenume;
            this->ruta_preferata = ruta_preferata;
            this->vehicul_preferat = vehicul_preferat;
        }
};

class Depou
{
    private:
        int id;
        Coordonate *amplasament;
        list<Vehicul> vehiculeGestiune;
        list<Angajat> angajati;
        list<Ruta> ruteGestiune;
        int capacitateMentenanta;
        list<Vehicul> vehiculMentenanta;
        string comentarii;
    public:
        Depou(int id, Coordonate *amplasament, list<Vehicul> vehiculeGestiune, list<Angajat> angajati, list<Ruta> ruteGestiune, int capacitateMentenanta, list<Vehicul> vehiculMentenanta, string comentarii)
        {
            this->id = id;
            this->amplasament = amplasament;
            this->vehiculeGestiune = vehiculeGestiune;
            this->angajati = angajati;
            this->ruteGestiune = ruteGestiune;
            this->capacitateMentenanta = capacitateMentenanta;
            this->vehiculMentenanta = vehiculMentenanta;
            this->comentarii = comentarii;
        }
};

int LoadData()
{
    Coordonate *cords = new Coordonate(44.4295590, 25.9774500, 80.0, "Str. Preciziei 19-21", 19, "Sector 6", "Bucuresti", "Bucuresti-Ilfov", "Romania");
    
    Data *data = new Data(05, 03, 2020);
    
    Data *dataMen = new Data(14, 05, 2024);
    
    Mentenanta *ment = new Mentenanta(ITP, dataMen);

    coordonateOrientare *coordCur = new coordonateOrientare(44.46344643, 26.07423449, 91.0);
    
    Vehicul *vehicul = new Vehicul(1, autobuzDiesel, nullptr, "13", "Otokar", "", data, 12.3, 31, 106, coordCur, 15, "http://localhost:8888", "Fara comentarii");
    vehicul->adaugareMentenanta(ment);
    
    Ruta *ruta = new Ruta(41, neelec_mixt, )
    
    Depou depou = new Depou(41, cords, );
    
    return 1;
}

int main()
{
    LoadData();
    
    printf("Bine ai venit in aplicatia STB!\nCe actiune doresti sa realizezi?\n");
    printf("1. Cauta rute\n2.Cauta linie\n3.Cauta destinatie\n4.Cauta punct preluare\n5.Logare Administrator\n");
    int iRaspuns;
    cin >> iRaspuns;
    
    string sRaspuns;
    
    switch(iRaspuns)
    {
        case 1:
        {
            printf("Introdu ruta de interes:\n");
            cin >> sRaspuns;
            //CautaRuta(sRaspuns);
            break;
        }
        case 2:
        {
            printf("Introdu linia de interes:\n");
            cin >> iRaspuns;
            //CautaLinie(iRaspuns);
            break;
        }
        case 3:
        {
            printf("Introdu destinatia de inters:\n");
            cin >> sRaspuns;
            CautaRutaByDest(sRaspuns);
            break;
        }
        case 4:
        {
            printf("Introdu punctul de preluare:\n");
            cin >> sRaspuns;
            //CautaRutaByPct(sRaspuns);
            break;
        }
        case 5:
        {
            printf("Introdu numele si parola de Administrator:\n");
            string sTemp;
            cin >> sRaspuns;
            cin >> sTemp;
            //Login(sRaspuns, sTemp);
            break;
        }
        
    }
    
    return 0;
}

void CautaRuta(string arg)
{
    
}