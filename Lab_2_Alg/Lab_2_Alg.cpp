#include <stdio.h>

// Рекурсивна функція для обчислення варіантів
long long countWaysRecursive(int );
long long countWaysCycle(int );
void printWays(int);

int main() {
    printWays(1);
	getchar();
    printWays(0);
    return 0;
}

long long countWaysRecursive(int n) {
    // Базові випадки (зупинка рекурсії)
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    // Рекурсивний крок: сума трьох попередніх станів
    return countWaysRecursive(n - 1) +
        countWaysRecursive(n - 2) +
        countWaysRecursive(n - 3);
}

long long countWaysCycle(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    long long first = 1;  // f(1)
    long long second = 2; // f(2)
    long long third = 4;  // f(3)
    long long current = 0;

    for (int i = 4; i <= n; i++) {
        current = first + second + third;
        first = second;
        second = third;
        third = current;
    }

    return third;
}

void printWays(int IsCycle) {
	printf("Ways to climb stairs using, %s:\n",IsCycle == 1 ? "Cycle" : "Recursive");
    printf("--------------------------------\n");
    printf("N\t|Values\n");
    printf("--------------------------------\n");
    for (int i = 1; i <= 72; i++) {
        printf("%d\t|%lld\n", i, IsCycle == 1 ? countWaysCycle(i): countWaysRecursive(i));
    }
	printf("\n");
}