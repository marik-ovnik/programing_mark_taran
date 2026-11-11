


    
  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rows, cols, length = 3, score = 0;
int *snake, food;
char *field;

// Есть ли клетка в теле змейки?
int occupied(int cell, int count) {
    for (int i = 0; i < count; i++)
        if (snake[i] == cell) return 1;
    return 0;
}

void new_food() {
    do {
        food = rand() % (rows * cols);
    } while (occupied(food, length));
}

void draw() {
printf("\033[H\033[J");
    for (int i = 0; i < rows * cols; i++) field[i] = ' ';
    if (food != -1) field[food] = '*';

    for (int i = 0; i < length; i++)
        field[snake[i]] = (i == 0) ? '#' : 'o';

    putchar('+');
    for (int x = 0; x < cols; x++) putchar('-');
    puts("+");

    for (int y = 0; y < rows; y++) {
        putchar('|');
        for (int x = 0; x < cols; x++)
            putchar(field[y * cols + x]);
        puts("|");
    }

    putchar('+');
    for (int x = 0; x < cols; x++) putchar('-');
    puts("+");
    printf("украденно : %d\n", score);
}

int main() {
    printf("Rows and cols: ");
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < 3 || rows > 20 || cols < 5 || cols > 50) {
        puts("инвалид поле размер");
        return 1;
    }

    field = malloc(rows * cols * sizeof(char));
    snake = malloc(length * sizeof(int));
    if (!field || !snake) {
        free(field);
        free(snake);
        return 1;
    }

//=---=-=-=-=-=-
    int start = (rows / 2) * cols + cols / 2;
    for (int i = 0; i < length; i++) snake[i] = start - i;

    srand(time(NULL));
    new_food();
    draw();

    while (1) {
        char key;
        printf("двигай (w/a/s/d, q - quit): ");
        if (scanf(" %c", &key) != 1 || key == 'q') break;

        int x = snake[0] % cols;
        int y = snake[0] / cols;

        if (key == 'w') y--;
        else if (key == 's') y++;
        else if (key == 'a') x--;
        else if (key == 'd') x++;
        else continue;

        if (x < 0 || x >= cols || y < 0 || y >= rows) {
            puts("Game over: конец!");
            break;
        }

        int next = y * cols + x;
        int eating = (next == food);

        // двигай 
        if (occupied(next, eating ? length : length - 1)) {
            puts("Game over: бывает!");
            break;
        }

        if (eating) {
            int *temp = realloc(snake, (length + 1) * sizeof(int));
            if (!temp) {
                puts("поп память ерор");
                break;
            }
            snake = temp;
            length++;
            score++;
        }

        for (int i = length - 1; i > 0; i--)
            snake[i] = snake[i - 1];
        snake[0] = next;

        if (eating) {
            if (length == rows * cols) {
                food = -1;
                draw();
                puts("побэда");
                break;
            }
            new_food();
        }
        draw();
    }

    printf("итохо: %d\n", score);
    free(snake);
    free(field);
    return 0;
}
