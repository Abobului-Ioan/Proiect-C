#include "proiect.h"

int main()
{
    system("color f1");
    int optiune,acc;
    tag(0);
    puts(" 1. Client");
    puts(" 2. Administrator");
    puts(" 3. Informatii.");
    puts(" 4. Iesire.");
    puts("\nAlegeti o optiune:");
    scanf("%d",&optiune);
    switch (optiune)
    {
    case 1:
        Client();
        break;

    case 2:
        acc=acces();
        if(acc==1)
            Admin();
        else
        {
            printf("\nApasa-ti orice tasta pentru a reveni la meniu\n");
            getch();
            main();
        }
        break;

    case 3:

        tag(0);
        info();
        printf("\nApasa-ti orice tasta pentru a reveni la meniu\n");
        getch();
        main();
        break;
    case 4:
        exit(0);
    default:

        printf("\n\n\t\tOptiunea aleasa nu exita....");
        getch();
        main();

    }
    return 0;
}
