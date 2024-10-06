#include <stdio.h>
#include <stdlib.h>

void calc_h(float k, float A, float T2, float T1, float X, float *H);
void calc_k(float H, float A, float T2, float T1, float X, float *k);
void calc_a(float H, float k, float T2, float T1, float X, float *A);
void calc_t2(float H, float k, float A, float T1, float X, float *T2);
void calc_t1(float H, float k, float A, float T2, float X, float *T1);
void calc_x(float H, float k, float A, float T2, float T1, float *X);

int main() {
    float H = 0, k = 0, A = 0, T1 = 0, T2 = 0, X = 0;
    char input_char;

    printf("Rate of heat transfer (watts) >> ");
    scanf("%f", &H);

    printf("Coefficient of thermal conductivity (W/m-K) >> ");
    scanf("%f", &k);

    printf("Cross-sectional area of conductor (m^2) >> ");
    scanf("%f", &A);

    printf("Temperature on one side (K) >> ");
    scanf("%f", &T1);

    printf("Temperature on the other side (K) >> ");
    scanf(" %c", &input_char);  
    if (input_char == '?') {
        calc_t2(H, k, A, T1, X, &T2);
        printf("Temperature on the other side is %.2f K.\n", T2);
    } else {
        T2 = atof(&input_char);  
    }

    printf("Thickness of conductor (m) >> ");
    scanf("%f", &X);

    printf("\nResults:\n");
    printf("H = %.2f W                T2 = %.2f K\n", H, T2);
    printf("k = %.3f W/m-K           T1 = %.2f K\n", k, T1);
    printf("A = %.3f m^2             X = %.3f m\n", A, X);

    if (H == 0) {
        calc_h(k, A, T2, T1, X, &H);
        printf("Calculated H = %.2f W\n", H);
    } else if (k == 0) {
        calc_k(H, A, T2, T1, X, &k);
        printf("Calculated k = %.3f W/m-K\n", k);
    } else if (A == 0) {
        calc_a(H, k, T2, T1, X, &A);
        printf("Calculated A = %.3f m^2\n", A);
    } else if (X == 0) {
        calc_x(H, k, A, T2, T1, &X);
        printf("Calculated X = %.3f m\n", X);
    }

    return 0;
}

void calc_h(float k, float A, float T2, float T1, float X, float *H) {
    *H = (k * A * (T2 - T1)) / X;
}

void calc_k(float H, float A, float T2, float T1, float X, float *k) {
    *k = (H * X) / (A * (T2 - T1));
}

void calc_a(float H, float k, float T2, float T1, float X, float *A) {
    *A = (H * X) / (k * (T2 - T1));
}

void calc_t2(float H, float k, float A, float T1, float X, float *T2) {
    *T2 = (H * X) / (k * A) + T1;
}

void calc_t1(float H, float k, float A, float T2, float X, float *T1) {
    *T1 = T2 - (H * X) / (k * A);
}

void calc_x(float H, float k, float A, float T2, float T1, float *X) {
    *X = (k * A * (T2 - T1)) / H;
}
