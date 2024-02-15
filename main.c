#include <stdio.h>

double convertirDevises(double montant, double tauxDeChange) {
    return montant * tauxDeChange;
}

int main() {
    double tauxDeChange[] = {1.0, 0.85, 0.74, 0.0097, 1.30, 0.91};

    const char* devises[] = {"Dollar", "Euro", "Livre Sterling", "Yen", "Dollar Canadien", "Dollar Australien"};

    while (1) {
        printf("\nCurrencies available :\n");
        for (int i = 0; i < sizeof(devises) / sizeof(devises[0]); i++) {
            printf("%d. %s\n", i + 1, devises[i]);
        }

        int deviseSource, deviseDestination;
        printf("Choose the source currency (1-%d, 0 to exit): ", sizeof(devises) / sizeof(devises[0]));
        scanf("%d", &deviseSource);

        if (deviseSource == 0) {
            break;
        }

        printf("Choose the destination currency (1-%d) : ", sizeof(devises) / sizeof(devises[0]));
        scanf("%d", &deviseDestination);

        if (deviseSource < 1 || deviseSource > sizeof(devises) / sizeof(devises[0]) ||
            deviseDestination < 1 || deviseDestination > sizeof(devises) / sizeof(devises[0])) {
            printf("Invalid currency choice.\n");
            continue;
        }

        double montant;
        printf("Enter the amount to convert: ");
        scanf("%lf", &montant);

        double montantConverti = convertirDevises(montant, tauxDeChange[deviseDestination - 1] / tauxDeChange[deviseSource - 1]);

        printf("%lf %s equals %lf %s.\n", montant, devises[deviseSource - 1], montantConverti, devises[deviseDestination - 1]);
    }

    return 0;
}
