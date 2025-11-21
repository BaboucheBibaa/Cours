#include <stdio.h>
#include <time.h>

int main(void) {
    time_t now = time(NULL);
    struct tm ajd = *localtime(&now);
    struct tm *maintenant= localtime(&now);

    printf("Heure actuelle : %02d:%02d:%02d\n",
        maintenant->tm_hour, maintenant->tm_min, maintenant->tm_sec);

    ajd.tm_hour = 13;
    ajd.tm_min = 30;
    ajd.tm_sec = 0;

    time_t target = mktime(&ajd);

    double diff = difftime(now, target);

    if (diff < 0) {
        printf("Il est avant 13h30 (dans %.0f secondes)\n", -diff);
    } else {
        int heures = (int)(diff / 3600);
        int minutes = ((int)diff % 3600) / 60;
        int secondes = (int)diff % 60;

        printf("Il s'est écoulé %d h %d min %d s depuis 13h30.\n", heures, minutes, secondes);
    }

    return 0;
}
