#include <stdio.h>
#include <string.h>

int main() {
    int estudiantes, asignaturas;
    int max_estudiantes = 5;
    int max_asignaturas = 3;
    char nombres[max_estudiantes][50];
    char materias[max_asignaturas][50];
    float calificaciones[max_estudiantes][max_asignaturas];
    int calificaciones_ingresadas = 0;

    int opcion, check;
do{
    do {
        printf("\nMenú:\n");
        printf("1. Registrar estudiantes y materias\n");
        printf("2. Ingresar calificaciones\n");
        printf("3. Mostrar resultados por materia\n");
        printf("4. Mostrar resultados por estudiante.\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        check = scanf("%d", &opcion);
        if(check != 1){
            fflush(stdin);
            printf("Ingrese una opcion valida.\n");
        }
    }while(check != 1);
        switch (opcion) {
            case 1:
                printf("Ingrese número de estudiantes: ");
                scanf("%d", &estudiantes);
                getchar();
                if (estudiantes > max_estudiantes) {
                    printf("Número de estudiantes excede el límite (%d). Intente nuevamente desde el principio.\n", max_estudiantes);
                    break;
                }
                for (int i = 0; i < estudiantes; i++) {
                    printf("Nombre del estudiante %d: ", i + 1);
                    fgets(nombres[i], sizeof(nombres[i]), stdin);
                    nombres[i][strcspn(nombres[i], "\n")] = '\0';
                }

                printf("Ingrese número de asignaturas: ");
                scanf("%d", &asignaturas);
                getchar();
                if (asignaturas > max_asignaturas) {
                    printf("Número de asignaturas excede el límite (%d). Intente nuevamente desde el principio.\n", max_asignaturas);
                    break;
                }
                for (int i = 0; i < asignaturas; i++) {
                    printf("Nombre de la materia %d: ", i + 1);
                    fgets(materias[i], sizeof(materias[i]), stdin);
                    materias[i][strcspn(materias[i], "\n")] = '\0';
                }
                break;

            case 2:
                for (int i = 0; i < estudiantes; i++) {
                    for (int j = 0; j < asignaturas; j++) {
                        do {
                            printf("Ingrese la calificación de %s en %s: ", nombres[i], materias[j]);
                            check = scanf("%f", &calificaciones[i][j]);
                            if(check!=1){
                                fflush(stdin);
                                printf("Solo puedes ingresar numeros.\n");
                            }

                            if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                                printf("Calificación inválida. Debe estar entre 0 y 10.\n");
                            }
                        } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10 || check != 1);
                    }
                }
                calificaciones_ingresadas = 1;
                break;

            case 3:
                if (!calificaciones_ingresadas) {
                    printf("Debe ingresar calificaciones antes de ver los resultados.\n");
                    break;
                }

                for (int i = 0; i < estudiantes; i++) {
                    float suma = 0, max = 0, min = 10;
                    for (int j = 0; j < asignaturas; j++) {
                        suma += calificaciones[i][j];
                        if (calificaciones[i][j] > max) max = calificaciones[i][j];
                        if (calificaciones[i][j] < min) min = calificaciones[i][j];
                    }
                    printf("\nEstudiante: %s\n", nombres[i]);
                    printf("Promedio: %.2f\n", suma / asignaturas);
                    printf("Nota más alta: %.2f\n", max);
                    printf("Nota más baja: %.2f\n", min);
                }

                for (int j = 0; j < asignaturas; j++) {
                    float suma = 0;
                    int aprobados = 0;
                    for (int i = 0; i < estudiantes; i++) {
                        suma += calificaciones[i][j];
                        if (calificaciones[i][j] >= 6) aprobados++;
                    }
                    printf("\nMateria: %s\n", materias[j]);
                    printf("Promedio: %.2f\n", suma / estudiantes);
                    printf("Estudiantes aprobados: %d\n", aprobados);
                }
                break;
            case 4:
                if (!calificaciones_ingresadas) {
                    printf("Debe ingresar calificaciones antes de ver los resultados.\n");
                    break;
                }

                for (int i = 0; i < estudiantes; i++) {
                    float suma = 0;
                    for (int j = 0; j < asignaturas; j++) {
                        suma += calificaciones[i][j];
                    }
                    printf("\nEstudiante: %s\n", nombres[i]);
                    printf("Promedio: %.2f\n", suma / asignaturas);
                }
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 5);

    return 0;
}
