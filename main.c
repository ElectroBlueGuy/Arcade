#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int hp, m, ehp, r, scelta, attacco, eattacco, magia, cura, usmagic, stmagic, x, protection, fchance, rage, adamage, lifesteal, fireball;
int enattacco;
int attack[4], magic[3], heal[2], umagic[2], eattack[3], smagic[1], fdamage[2];
int main()
{
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
    while(ehp>0)///finch� la vita del nemico � superiore a 0 il gioco non si ferma
    {
    system("cls");
    printf("Seleziona la tua prossima mossa!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n1: Attacca 2: Incantesimi\n\n", hp, m, ehp); /// schermata iniziale
    scanf("%d", &scelta);
        if(scelta==1) /// se la prima scelta � di attaccare
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
        printf("Attacchi l'avversario togliendogli %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",adamage, hp, m, ehp);
        }
        else
        {
        x=( rand() % 99);
            if(x<=6) /// prova a rollare per un attacco critico
            {
            adamage=adamage*2;
            ehp=ehp-adamage;
            printf("Attacchi l'avversario togliendogli %d di vita!\n\nCOLPO CRITICO!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",adamage, hp, m, ehp);

            }
        else
        {
            if(x>=90) /// prova a rollare per un attacco missato
            {
            printf("Il tuo attacco manca l'avversario!\n\nCOLPO MANCATO!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n", hp, m, ehp);
            }
            else
            {
            ehp=ehp-adamage;
             printf("Attacchi l'avversario togliendogli %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",adamage, hp, m, ehp);
            }
        }
        }
            system ("pause");
            system("cls");
        }

    else
    {
        if(scelta==2) ///se scegli incantesimi
        {
        system("cls");
        printf("Vita: %d | MP: %d | Vita dell'avversario: %d\n\nScegli che incantesimo usare:\n1)Heal: Ti curi aggiungendo qualcosa alla tua vita(costo: 2 MP)\n2)Concentration: Aggiunge qualche punto ai tuoi MP(Costo: 0 MP)\n3)Protection: per 3 turni il danno subito sara' minore(costo: 5 MP)\n4)Rage: Farai piu' danni per 3 turni(Costo: 10 MP)\n", hp, m, ehp);
        scanf("%d",&scelta); /// va nel men� incantesimi
            if(scelta==1) /// heal
            {
            system("cls");
            srand(time(0));
            cura=( rand() % 2 );
            hp=hp+heal[cura];
            m=m-2;
            printf("Usando 2 di magia, aggiungi %d alla tua vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",heal[cura], hp, m, ehp);
            system ("pause");
            system("cls");
            }
        else
        {
            if(scelta==2) /// concentration
            {
            system("cls");
            srand(time(0));
            magia=( rand() % 3 );
            m=m+magic[magia];
            printf("Aggiungi %d alla tua magia!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",magic[magia], hp, m, ehp);
            system ("pause");
            system("cls");
            }
        else
        {
            if(scelta==3) ///protection
            {
            system("cls");
            protection=protection+3;
            m=m-5;
            printf("Usi 5 MP Per ridurre il danno che subisci per 3 turni!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n", hp, m, ehp);
            system ("pause");
            system("cls");
            }
        else
        {
            if(scelta==4) /// rage
            {
            system("cls");
            rage=rage+3;
            m=m-10;
            printf("Usi 10 MP Per aumentare il danno che fai per 3 turni!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n", hp, m, ehp);
            system ("pause");
            system("cls");
            }
        }
    }
}
}
} ///turno dell'avversario
srand(time(0));
fchance=(rand() % 9);
        if(fchance>=8) /// rolla per tirare una fireball, pi� danno
        {
        if(protection>0)
        protection--;
        fireball=(rand() % 2);
        hp=hp-fdamage[fireball];
        printf("L'avversario ti colpisce con una palla di fuoco, togliendoti %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",fdamage[fireball], hp, m, ehp);
        }
    else
{
    eattacco=( rand() % 3 );
    enattacco=eattack[eattacco];

        if(protection>0) /// controlla se c'� protezione
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
    printf("L'avversario ti ruba %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",enattacco, hp, m, ehp);
    }
    else
    {
    hp=hp-enattacco;
    printf("L'avversario ti colpisce togliendoti %d di vita!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\n",enattacco, hp, m, ehp);
    }
    }

system ("pause");
system("cls");
    if((m < 0) || (hp <= 0)) /// controlla se ci sono endgame variabili
    {
    printf("Sei Morto!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\nGame Over!\n\n", hp, m, ehp);
    system ("pause");
    return 0;
    }

 }/// esce e vinci
printf("Hai Vinto!\n\nVita: %d | MP: %d | Vita dell'avversario: %d\n\nComplimenti!\n\n", hp, m, ehp);
system ("pause");
return 0;
}







