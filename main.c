#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
void pac(){system ("pause");
            system("cls");}
void loader() {
    int i;
    char str[] = "                                        ";
    for(i = 0 ; i <= 40 ; i++) {
        printf("\r[%s]", str);
        str[i] = '|';
        Sleep(150);
    }

}
int hp, m, ehp, r, scelta, attacco, eattacco, magia, cura, usmagic, stmagic, x, protection, fchance, rage, adamage, restart,
lifesteal, fireball, meter,c=0, stun, tut;
int enattacco;
int attack[4], magic[3], heal[2], umagic[2], eattack[3], smagic[1], fdamage[2];
int main()
{
    printf("Vuoi vedere il tutorial?\n1=Si\n");
    scanf("%d", &tut);
    if(tut==1)
    {
        system("cls");
        printf("l'obbiettivo del gioco e' far arrivare la vita dell'avversario a 0\n");
        pac();
        printf("Puoi fare attaccandolo(1)\n");
        pac();
        printf("Se la tua vita scende a zero, hai perso\n");
        pac();
        printf("Gli MP servono per usare gli incantesimi, se scendono sotto lo zero, hai perso\n");
        pac();
        printf("premendo 2 apri il menu degli incantesimi\nVengono dati gli incantesimi, una descrizone, ed il costo\n");
        pac();
        printf("Buona Fortuna!\n");
        pac();
        printf("\n\n\n\n\n\nNe avrai bisogno...\n");
        Sleep(50);
        system("cls");
        loader();
        system("cls");
    }
restart=1;
while(restart=1){
c++;
fdamage[0]=8; ///incomincio a dichiarare tutti gli array e variabili
fdamage[2]=9;
fdamage[1]=10;
protection=0;
rage=0;
hp=30;
ehp=45;
r=clock();
attack[0]=2;
attack[1]=3;
attack[2]=4;
attack[3]=5;
attack[4]=6;
magic[0]=4;
magic[1]=5;
magic[2]=6;
magic[3]=7;
heal[0]=6;
heal[1]=7;
heal[2]=8;
umagic[0]=1;
umagic[1]=2;
umagic[2]=3;
eattack[0]=3;
eattack[1]=4;
eattack[2]=5;
eattack[3]=6;
smagic[0]=2;
smagic[1]=3;
m=10;
    while(ehp>0)///finchè la vita del nemico è superiore a 0 il gioco non si ferma
    {
    system("cls");
    printf("Stai combattendo contro Nemico #%d\nSeleziona la tua prossima mossa!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n1: Attacca 2: Incantesimi\n\n",c, hp, m, ehp); /// schermata iniziale
    scanf("%d", &scelta);
        if(scelta==1) /// se la prima scelta è di attaccare
        {
        system("cls");
        srand(time(0));
        attacco=( rand() % 4 );
        adamage=attack[attacco];
        if(rage>0)
        {
        rage--;
        adamage=adamage*2;
        ehp=ehp-adamage;
        printf("Stai combattendo contro Nemico #%d\nAttacchi l'avversario togliendogli %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,adamage, hp, m, ehp);
        }
        else
        {
        x=( rand() % 99);
            if(x<=6) /// prova a rollare per un attacco critico
            {
            adamage=adamage*2;
            ehp=ehp-adamage;
            printf("Stai combattendo contro Nemico #%d\nAttacchi l'avversario togliendogli %d di vita!\n\nCOLPO CRITICO!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,adamage, hp, m, ehp);

            }
        else
        {
            if(x>=90) /// prova a rollare per un attacco missato
            {
            printf("Stai combattendo contro Nemico #%d\nIl tuo attacco manca l'avversario!\n\nCOLPO MANCATO!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, m, ehp);
            }
            else
            {
            ehp=ehp-adamage;
             printf("Stai combattendo contro Nemico #%d\nAttacchi l'avversario togliendogli %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,adamage, hp, m, ehp);
            }
        }
        }
            pac();
        }

    else
    {
        if(scelta==2) ///se scegli incantesimi
        {
        system("cls");
        printf("Vita: %d | MP: %d | Vita dell'avversario: %d\n\nScegli che incantesimo usare:\n1)Heal: Ti curi aggiungendo qualcosa alla tua vita(costo: 2 MP)\n2)Concentration: Aggiunge qualche punto ai tuoi MP(Costo: 0 MP)\n3)Protection: per 3 turni il danno subito sara' minore(costo: 5 MP)\n4)Rage: Farai piu' danni per 3 turni(Costo: 10 MP)\n5)Stun: Stordisci l'avversario impedendogli di attaccare per 2 turni(Costo: 7 MP)", hp, m, ehp);
        scanf("%d",&scelta); /// va nel menù incantesimi
            if(scelta==1) /// heal
            {
            system("cls");
            srand(time(0));
            cura=( rand() % 2 );
            hp=hp+heal[cura];
            m=m-2;
            printf("Stai combattendo contro Nemico #%d\nUsando 2 di magia, aggiungi %d alla tua vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,heal[cura], hp, m, ehp);
            pac();
            }
        else
        {
            if(scelta==2) /// concentration
            {
            system("cls");
            srand(time(0));
            magia=( rand() % 3 );
            m=m+magic[magia];
            printf("Stai combattendo contro Nemico #%d\nAggiungi %d alla tua magia!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,magic[magia], hp, m, ehp);
            pac();
            }
        else
        {
            if(scelta==3) ///protection
            {
            system("cls");
            protection=protection+3;
            m=m-5;
            printf("Stai combattendo contro Nemico #%d\nUsi 5 MP Per ridurre il danno che subisci per 3 turni!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, m, ehp);
            pac();
            }
        else
        {
            if(scelta==4) /// rage
            {
            system("cls");
            rage=rage+3;
            m=m-10;
            printf("Stai combattendo contro Nemico #%d\nUsi 10 MP Per aumentare il danno che fai per 3 turni!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, m, ehp);
            pac();
            }
            else{
            if(scelta==5) /// stun
            {
            system("cls");
            stun=stun+2;
            m=m-7;
            printf("Stai combattendo contro Nemico #%d\nUsi 7 MP Per bloccare il nemico per 2 turni!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, m, ehp);
            pac();
        }
    }
        }
        }
}
}
} ///turno dell'avversario
if(stun>0)
{
   stun=stun-1;
   printf("Stai combattendo contro Nemico #%d\nL'avversario non riesce a muoversi\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, m, ehp);
   meter=0;
}
else{
if(meter==-666)
{
    enattacco=15;
    hp=hp-enattacco;
    meter=0;
    printf("Stai combattendo contro Nemico #%d\nL'avversario ti colpisce con un colpo caricato, togliendoti %d di vita!\n\nCOLPO CRITICO!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,enattacco, hp, m, ehp);
    system ("pause");
}
else
{
if(meter>=30)
{
    meter=-666;
    printf("Stai combattendo contro Nemico #%d\nL'avversario sta caricando un colpo potente...\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c, hp, m, ehp);
}
else
{
srand(time(0));
fchance=(rand() % 9);
        if(fchance>=8) /// rolla per tirare una fireball, più danno
        {
        if(protection>0)
        protection--;
        fireball=(rand() % 2);
        enattacco=fdamage[fireball];
        hp=hp-enattacco;
        printf("Stai combattendo contro Nemico #%d\nL'avversario ti colpisce con una palla di fuoco, togliendoti %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,enattacco, hp, m, ehp);
        meter=meter+enattacco;
        }
    else
{
    eattacco=( rand() % 3 );
    enattacco=eattack[eattacco];

        if(protection>0) /// controlla se c'è protezione
        {
        protection--;
        enattacco=eattack[eattacco]-3;
        }
        srand(time(0));
        fchance=(rand() % 99);
    if(fchance<10)/// rolla per un lifesteal
    {
    hp=hp-enattacco;
    ehp=ehp+enattacco;
    printf("Stai combattendo contro Nemico #%d\nL'avversario ti ruba %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,enattacco, hp, m, ehp);
    meter=meter+enattacco;
    }
    else
    {
    hp=hp-enattacco;
    printf("Stai combattendo contro Nemico #%d\nL'avversario ti colpisce togliendoti %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",c,enattacco, hp, m, ehp);
    meter=meter+enattacco;
    }
    }
}
}
    }
pac();
    if((m < 0) || (hp <= 0)) /// controlla se ci sono endgame variabili
    {
    printf("Sei Morto!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\nGame Over!\n\n", hp, m, ehp);
     system("pause");
     return 0;
    }
    }
/// esce e vinci
printf("Hai Vinto!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\nComplimenti!\n\n", hp, m, ehp);
system ("pause");
printf("Vuoi ricominciare?\n\n1=Si   0=No\n");
scanf("%d",&restart);

}
return 0;

}
