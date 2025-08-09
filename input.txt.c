#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int sum(int a, int b) {
    return (a + b);
}

float average(float a, float b) {
    return ((a + b) / 2.00f);
}

bool is_positive(int x) {
    if ((x > 0)) {
        return 1;
    } else {
        return 0;
    }
}

int fact(int n) {
    if ((n <= 1)) {
        return 1;
    } else {
        return (n * fact((n - 1)));
    }
}

int lambda_2(int v) {
    return sum(v, 5);
}

int lambda_1(int sq) {
    return (sq * sq);
}

int lambda_0(int y) {
    return (y + 1);
}

int main() {
    int x = 5;
    int y = 10;
    float z = 2.50f;
    double pi = 3.14f;
    char* msg = "Hello!";
    printf("%d\n", sum(x, y));
    float avg_val = average(z, pi);
    printf("%.2f\n", avg_val);
    printf("%s\n", msg);
    bool t1 = is_positive(-(3));
    bool t2 = is_positive(7);
    printf("%d\n", t1);
    printf("%d\n", t2);
    int f5 = fact(5);
    printf("%d\n", f5);
    if ((x > y)) {
        printf("%s\n", "x is greater");
    } else {
        printf("%s\n", "x is not greater");
    }
    if ((x > 5)) {
        y = (x * 2);
        int sum_val = (y + 10);
        printf("%d\n", sum_val);
    } else {
        y = (z - 5);
        int w = (y * 3);
        printf("%d\n", w);
    }
    y = lambda_0(y);
    printf("%d\n", y);
    int sq = 0;
    sq = lambda_1(sq);
    printf("%d\n", sq);
    int v = 3;
    v = lambda_2(v);
    printf("%d\n", v);
    return 0;
}

