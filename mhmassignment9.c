#include <stdio.h>

struct RobotData {
    float moisture, temp, humidity;
    int health;
    double lat, lon;
};

int main() {
    struct RobotData r;
    FILE *fp;
    printf("Enter soil moisture (%%), temp (C), humidity (%%): ");
    scanf("%f %f %f", &r.moisture, &r.temp, &r.humidity);

    printf("Enter crop health (1-10): ");
    scanf("%d", &r.health);

    printf("Enter GPS (latitude longitude): ");
    scanf("%lf %lf", &r.lat, &r.lon);
    fp = fopen("data.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "%.1f %.1f %.1f %d %.4f %.4f\n", 
            r.moisture, r.temp, r.humidity, r.health, r.lat, r.lon);
    fclose(fp);

    printf("\n--- FIELD MONITORING REPORT ---\n");
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error reading file!\n");
        return 1;
    }

    while (fscanf(fp, "%f %f %f %d %lf %lf", 
                  &r.moisture, &r.temp, &r.humidity, &r.health, &r.lat, &r.lon) != EOF) {
        
        char *irrigation = (r.moisture < 35.0) ? "NEEDED" : "OK";

        printf("GPS: (%.4f, %.4f) | Moisture: %.1f%% | Temp: %.1f | Humidity: %.1f%% | Health: %d/10 | Irrigation: %s\n",
               r.lat, r.lon, r.moisture, r.temp, r.humidity, r.health, irrigation);
    }

    fclose(fp);
    return 0;
}
