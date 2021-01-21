#include "proiect.h"


struct list
{
    int cod;
    int gramaj;
    float pret;
    char nume[100];
    struct list *next;
};

struct bauturi
{
    int cod;
    int gramaj;
    float pret;
    char nume[100];
};

struct list *head=NULL,*p,*last=NULL,*q=NULL;
struct bauturi obj;
FILE *f;
int found=0;
int n,i;



int tag(int nr)
{
    system("cls");
    printf("\n*******************************************************************************\n");
    printf("\n\t\t\t||  MAGAZIN BAUTURI  ||\n");
    printf("\n*******************************************************************************\n");
}

void PanouAdmin()
{

    printf("-------------------------------------------------------------------------------------\n");
    printf("\n\n");
    printf("\n\t\t\t||  MENIU-ADMIN  ||");
    printf("\n\n");
    printf("--------------------------------------------------------------------------------------\n");

}

void PanouClient()

{

    printf("--------------------------------------------------------------------------------------\n");
    printf("\n\n");
    printf("\n\t\t\t||  MENIU-CLIENT  ||");
    printf("\n\n");
    printf("--------------------------------------------------------------------------------------\n");
}


void info()
{
    system("cls");
    system("color f1");
    printf("\n \n \n");
    printf("\nProiect de: \t Abobului Ioan \n Grupa: \t 3114-A \n ");
    printf("\n\t\t\t\t\tO zi buna sa aveti:))......");
    getch();
}

void Client()
{
    tag(0);
    int optiune;
    printf("\n\t1.Vezi produsele.");
    printf("\n\t2.Cauta un produs.");
    printf("\n\t3.Cumpara.");
    printf("\n\t4.Revino la meniul anterior");
    printf("\n\t5.Iesire");
    printf("\n\n\tAlege-ti optiunea:");
    scanf("%d",&optiune);
    switch(optiune)
    {
    case 1:
        aratas();
        printf("\nApasati orice tasta pentru a reveni la meniul anterior...");
        getch();
        system("cls");
        Client();
        break;
    case 2:
        cauta();
        printf("\nApasati orice tasta pentru a reveni la meniul anterior...");
        getch();
        system("cls");
        Client();
    case 3:
        cumpara();
        printf("\nApasati orice tasta pentru a reveni la meniul anterior...");
        getch();
        system("cls");
        Client();
    case 4:
        main();
        break;
    case 5:
        exit(0);
    default:
        printf("\n\n\t\tOptiunea aleasa nu exita....");
        getch();
        Client();
    }
}

int acces()
{
    fflush(stdin);
    char admin[30];
    static char parola[3];
    int a;
    printf("\n\t\tIntroduce-ti numele administrator:\n");
    scanf("%s",&admin);
    if (strcmpi(admin,"manager")==0 || strcmpi(admin,"admin")==0)
    {
        printf("\n\n\t\t\tIdentitate confirmata!");
        printf("\n\t\tIntroduce-ti parola de 3 numere:\n");
        for(int i=0; i<3; i++)
        {
            parola[i]=getch();
            if (parola[i]=='\r')
            {
                acces();
                break;
            }
            else
                printf("*");
        }
        if(strcmpi(parola,"123")==0 || strcmpi(parola,"000")==0)
        {
            printf("\033[1;32m");
            puts("\n\n\t\t\t\tACCES PERMIS!");
            printf("\033[0m");
            getch();
            system("color f1");
            a=1;
        }
        else
        {
            printf("\033[1;31m");
            puts("\n\n\t\t\t\tACCES RESPINS!");
            printf("\033[0m");
            a=0;
        }
    }

    else
    {
        tag(0);
        printf("\033[1;31m");
        puts("\n\n\t\t\t\tIDENTITATE NECUNOSCUTA!!!!!");
        printf("\033[0m");
        a=0;
    }
    return a;
}

void Admin()
{
    int optiune1;
    tag(0);
    PanouAdmin();
    printf("\n\t1.Adauga un produs nou.");
    printf("\n\t2.Vezi produsele existente.");
    printf("\n\t3.Sorteaza produsele(dupa cod).");
    printf("\n\t4.Modifica un produs.");
    printf("\n\t5.Sterge un produs.");
    printf("\n\t6.Cauta un produs.");
    printf("\n\t7.Intoarcere la meniul anterior.");
    printf("\n\n\tAlege-ti optiunea dorita:");
    scanf("%d",&optiune1);
    switch (optiune1)
    {
    case 1:
        adauga();
        printf("\nApasati orice tasta pentru a reveni la meniul anterior...");
        getch();
        system("cls");
        Admin();
        break;
    case 2:
        arata();
        printf("\nApasati orice tasta pentru a reveni la meniul anterior...");
        getch();
        system("cls");
        Admin();
        break;
    case 3:
        sorteaza();
        printf("\nApasati orice tasta pentru a reveni la meniul anterior...");
        getch();
        system("cls");
        Admin();
        break;
    case 4:
        modifica();
        printf("\nApasati orice tasta pentru a reveni la meniul anterior...");
        getch();
        system("cls");
        Admin();
        break;
    case 5:
        sterge();
        printf("\nApasati orice tasta pentru a reveni la meniul anterior...");
        getch();
        system("cls");
        Admin();
        break;
    case 6:
        cauta();
        printf("\nApasati orice tasta pentru a reveni la meniul anterior...");
        getch();
        system("cls");
        Admin();
        break;
    case 7:
        main();
        break;
    default:
        printf("/n/n/t/tOptiunea aleasa nu exita....");
        printf("\nApasati orice tasta pentru a reveni la meniul anterior...");
        getch();
        Admin();

    }
}



void citeste()
{
    int filempty=0;
    FILE *f=fopen("proiect.txt","r");
    p=head;
    fseek(f,0,SEEK_END);
    if(p==NULL)
    {
        p=(struct list*)malloc(sizeof(struct list));
        head=p;
    }
    int len=(int)ftell(f);
    if(len<=0)
    {
        filempty=1;
        printf("Fisier gol");
        p=NULL;
        head=p;
    }
    if(filempty==0)
    {
        rewind(f);
        while(fscanf(f,"\n%d\t %s\t %d\t %f\t",&(p->cod),p->nume,&(p->gramaj),&(p->pret)))
        {
            if(feof(f))
            {
                break;
            }
            p->next=(struct list*)malloc(sizeof(struct list));
            p=p->next;
            last=p;
            p->next=NULL;
        }
    }
}



void arata()
{
    citeste();
    p=head;
    if(p==NULL)
    {
        printf("list is empty");
    }
    else
    {
        printf("\n----------------------------------------------------------------\n");
        printf("||    COD    ||     Nume      ||    Gramaj    ||    Pret    ||");
        printf("\n----------------------------------------------------------------\n   ");
        for(int i=0; p!=NULL; i++)
        {
            printf("\n  %d\t\t%s\t\t%d ml\t\t %.2f lei\t ",(p->cod),p->nume,(p->gramaj),(p->pret));
            p=p->next;
        }
    }
}



void scrie()
{
    FILE *f1=fopen("proiect.txt","w");
    int i;
    struct list *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("Fisier gol");
    }
    else
    {
        for(i=0; temp!=NULL; i++)
        {
            fprintf(f1,"\n%d\t %s\t %d\t %f\t",(temp->cod),temp->nume,(temp->gramaj),(temp->pret));
            temp=temp->next;
        }
    }
    fclose(f1);
}
void sorteaza()
{
    citeste();
    struct list *i,*j;
    for(i=head; i!=NULL; i=i->next)
    {
        for(j=i->next; j!=NULL; j=j->next)
        {
            if((i->cod)>(j->cod))
            {
                obj.cod=i->cod;
                obj.gramaj=i->gramaj;
                obj.pret=i->pret;

                i->cod=j->cod;
                i->gramaj=j->gramaj;
                i->pret=j->pret;

                j->cod=obj.cod;
                j->gramaj=obj.gramaj;
                j->pret=obj.pret;

                strcpy(obj.nume,i->nume);
                strcpy(i->nume,j->nume);
                strcpy(j->nume,obj.nume);

            }
        }
    }
    scries();
    printf("\n\n\t\tSortarea a fost realizata cu succes...\n\n\n");
    aratas();

}

void scries()
{
    FILE *f1=fopen("sproiect.txt","w");
    int i;
    struct list *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("lista goala");
    }
    else
    {
        for(i=0; temp!=NULL; i++)
        {
            fprintf(f1,"\n%d\t %s\t %d\t %f\t",(temp->cod),temp->nume,(temp->gramaj),(temp->pret));
            temp=temp->next;
        }
    }
    fclose(f1);
}

void citestes()
{
    int i,filempty=0;
    FILE *f=fopen("sproiect.txt","r");
    p=head;
    fseek(f,0,SEEK_END);
    if(p==NULL)
    {
        p=(struct list*)malloc(sizeof(struct list));
        head=p;
    }
    int len=(int)ftell(f);
    if(len<=0)
    {
        filempty=1;
        printf("Fisier gol");
        p=NULL;
        head=p;
    }
    if(filempty==0)
    {
        rewind(f);
        while(fscanf(f,"\n%d\t %s\t %d\t %f\t",&(p->cod),p->nume,&(p->gramaj),&(p->pret)))
        {
            if(feof(f))
            {
                break;
            }
            p->next=(struct list*)malloc(sizeof(struct list));
            p=p->next;
            last=p;
            p->next=NULL;
        }
    }
}

void aratas()
{
    citestes();
    int i;
    p=head;
    if(p==NULL)
    {
        printf("lista goala");
    }
    else
    {
        printf("\n----------------------------------------------------------------\n");
        printf("||    COD    ||     Nume      ||    Gramaj    ||    Pret    ||");
        printf("\n----------------------------------------------------------------\n   ");
        for(int i=0; p!=NULL; i++)
        {
            printf("\n  %d\t\t%s\t\t%d ml\t\t %.2f lei\t ",(p->cod),p->nume,(p->gramaj),(p->pret));
            p=p->next;
        }
    }
}

void adauga()
{
    do
    {
        citeste();
        found=0;
        p=head;
        printf("Introduceti codul bauturi:\n");
        scanf("%d",&(obj.cod));
        printf("Introduceti numele bauturi:\n");
        scanf("%s",obj.nume);
        printf("Introduceti gramajul bauturi:\n");
        scanf("%d",&(obj.gramaj));
        printf("Introduceti pretul bauturi:\n");
        scanf("%f",&(obj.pret));
        strlwr(obj.nume);
        for(int i=1; p!=NULL; i++)
        {
            if(p->cod==obj.cod)
            {
                printf("\n  %d\t\t%s\t\t%d ml\t\t %.2f lei\t ",(p->cod),p->nume,p->gramaj,(p->pret));
                found=1;
                printf("\n\t\t Oopps  !!!  Exista deja o bautura cu acest cod ....\n\n") ;
            }
            p=p->next;

        }
    }
    while(found==1);
    struct list *p;
    int i=0;
    p=last;
    if(last==NULL)
    {
        i=1;
        last=(struct list*)malloc(sizeof(struct list));
        last->next=NULL;
        last->cod=obj.cod;
        strcpy(last->nume,obj.nume);
        last->gramaj=obj.gramaj;
        last->pret=obj.pret;
        p=last;
        head=last;
    }
    else
    {
        i=0;
        p=last;
        p->next=(struct list*)malloc(sizeof(struct list));
        p=p->next;
        last=p;
        p->cod=obj.cod;
        strcpy(p->nume,obj.nume);
        p->gramaj=obj.gramaj;
        p->pret=obj.pret;
        p->next=NULL;
    }
    scrie();
    printf("\n\n\t\tBautura adaugata cu succes ....!!!!!!!\n\n") ;

}


void sterge()
{
    struct list *p,*q;
    citeste();
    arata();
    int loc,i;
    printf("\nA cata bautura vreti sa stergeti:\n");
    scanf("%d",&loc);
    if(p!=NULL)
    {
        if(loc==1)
        {
            p=head;
            head=head->next;
            scries();
            free(p);
            return(head);
        }
        else
        {
            q=head;
        }
        for(i=1; i<loc-1; i++)
        {
            q=q->next;
        }
        p=q->next;
        q->next=p->next;
        scrie();
        free(p);
        n=n-1;
    }
    else
    {
        printf("\nSorry,Lista goala");
    }
    printf("\n\n\t\tBautura a fost stearsa cu succes....\n");
}

void cauta()
{
    citestes();
    int cod,found=0;
    char nume[100];
    p=head;
    int optiune2;
    do
    {
        system("CLS");
        printf("\n--------------------------------------------------------\n");
        printf("                       MENIU CAUTARE                      ");
        printf("\n--------------------------------------------------------\n\n");
        printf("\t1. Codul bauturii \n");
        printf("\t2. Numele bauturii\n");
        printf("\t0. EXIT\n");
        printf("\n--------------------------------------------------------\n");
        printf("Optiune:\t");
        scanf("%d",&optiune2);
        switch(optiune2)
        {
        case 1:
            system("CLS");
            citestes();
            p=head;
            printf("\nIntroduce-ti codul bauturii :\t");
            scanf("%d",&cod);
            printf("\n----------------------------------------------------------------\n");
            printf("||    COD    ||     Nume      ||    Gramaj    ||    Pret    ||");
            printf("\n----------------------------------------------------------------\n   ");
            for(i=1; p!=NULL; i++)
            {
                if(p->cod==cod)
                {
                    found=1;
                    printf("\n  %d\t\t%s\t\t%d ml\t\t %.2f lei\t ",(p->cod),p->nume,p->gramaj,(p->pret));

                }
                p=p->next;
            }
            if(found==0)
            {
                printf("\n\t\t Oops !!!! Bautura nu a fost gasita\n\n");
            }
            printf("\n\n\n0. MAIN MENU\t\t\t");
            printf("1. SUB MENU\n\n");
            printf("Optiune:\t");
            scanf("%d",&optiune2);
            break;

        case 2:
            system("CLS");
            found=0;
            citestes();
            p=head;
            printf("\n\nIntroduce-ti numele bauturii:\t");
            scanf("%s",nume);
            strlwr(nume);
            printf("\n----------------------------------------------------------------\n");
            printf("||    COD    ||     Nume      ||    Gramaj    ||    Pret    ||");
            printf("\n----------------------------------------------------------------\n   ");
            for(i=1; p!=NULL; i++)
            {
                if(strcmp(p->nume,nume)==0)
                {
                    found=1;
                    printf("\n  %d\t\t%s\t\t%d ml\t\t %.2f lei\t ",(p->cod),p->nume,p->gramaj,(p->pret));

                }
                p=p->next;
            }
            if(found==0)
            {
                printf("\n\t\t Oops !!!! Bautura nu a fost gasita\n\n");
            }
            printf("\n\n\n0. MAIN MENU\t\t\t");
            printf("1. SUB MENU\n\n");
            printf("Optiune:\t");
            scanf("%d",&optiune2);
            break;
        }
    }
    while(optiune2!=0);
}


void modifica()
{
    struct list *p,*q;
    citeste();
    arata();
    fflush(stdin);
    int loc,i;
    printf("\nA cata bautura vreti sa o modificati?:\t");
    scanf("%d",&loc);
    if(p!=NULL)
    {
        if(loc==0)
        {
            p=head;
            head=head->next;
            scries();
            aratas();
            free(p);
            return(head);
        }
        else
        {
            q=head;
        }
        for(i=1; i<loc-1; i++)
        {
            q=q->next;
        }
        p=q->next;
        q->next=p->next;
        scrie();
        arata();
        free(p);
        n=n-1;
    }
    else
    {
        printf("\n\t\tSorry,Lista goala");
    }
    citeste();
    p=head;
    q=head;
    int cod;
    int gramaj;
    char nume[100];
    float pret;
    printf("\nIntroduceti codul bauturi:\n");
    scanf("%d",&(cod));
    printf("\nIntroduceti numele bauturi:\n");
    scanf("%s",nume);
    printf("\nIntroduceti gramajul bauturi:\n");
    scanf("%d",&(gramaj));
    printf("\nIntroduceti pretul bauturi:\n");
    scanf("%f",&(pret));
    strlwr(nume);
    p=(struct list*)malloc(sizeof(struct list));
    p->cod=cod;
    strcpy(p->nume,nume);
    p->gramaj=gramaj;
    p->pret=pret;
    p->next=NULL;
    if(loc==1)
    {
        p->next=head;
        head=p;
        scrie();
        return(p);
    }
    q=head;
    for(i=1; i<loc-1; i++)
    {
        if(q!=NULL)
        {
            q=q->next;
        }
    }
    p->next=q->next;
    q->next=p;
    n=n+1;
    scrie();
    printf("\n\n\t\tBautura a fost modificata");
    return(head);
}

void cumpara()
{

    int bcod,ok = 1, icod = 0, icant = 0, cod[10], canti[10],ipret=0,pret[10],inume=0;
    char bnume[100],buff[10][10],choice;
    float bpret,temptotal=0,total=0,cant;
    aratas();
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    while(ok)
    {
        printf("\nApasati y daca vreti sa cumparati un produs si n daca vreti sa va opriti:");
        choice = toupper(getch());
        switch(choice)
        {
        case 'Y':
            do
            {
                printf("\nIntroduce-ti codul bauturi:");
                scanf("%d",&bcod);
                printf("\nIntroduce-ti cantitatea dorita:");
                scanf("%f",&cant);
                struct list *p;
                p=head;
                p=(struct list*)malloc(sizeof(struct list));
                p->cod=bcod;
                head=p;
                citeste();
                found=0;
                p=head;
                for(i=1; p!=NULL; i++)
                {
                    if(p->cod==bcod)
                    {
                        bpret=(p->pret);
                        strcpy(bnume,p->nume);
                        found=1;
                        temptotal=(cant)*(bpret);
                        total+=temptotal;

                    }
                    p=p->next;
                }

                if(!found)
                {
                    printf("Introdu un cod valid\n");
                    found=3;
                }
            }
            while(found==3);
            cod[icod++] = bcod;
            canti[icant++] = cant;
            pret[ipret++] = bpret;
            strcpy(buff[inume++],bnume);
            break;
        case 'N':
            ok=0;
            break;
        }
    }
    system("cls");
    printf("\n\n--------------------------------------------------------\n");
    printf("||   \t\t\t BON\t\t\t      ||");
    printf("\n\n--------------------------------------------------------\n");
    for(int i = 0; i < icod; i++)
    {

        printf("\tCod:%d\tCantitate:%d\tPret:%d\tNume:%s\n", cod[i],canti[i],pret[i],buff[i]);
    }
    printf("\n______________________________________________________________\n");
    printf("\n\t\t\tTOTAL:%2.f lei",total);
    printf("\n______________________________________________________________\n");

}


