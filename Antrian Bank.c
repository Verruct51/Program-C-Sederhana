#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

int isQueueFull(Queue *q) {
    return (q->rear == MAX_QUEUE_SIZE - 1);
}

void enqueue(Queue *q, int data) {
    if (isQueueFull(q)) {
        printf("Antrian penuh. Tidak dapat menambahkan antrian baru.\n");
        return;
    }

    if (isQueueEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }

    q->queue[q->rear] = data;
    printf("Antrian dengan nomor %d ditambahkan.\n", data);
}

void dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Antrian kosong. Tidak dapat menghapus antrian.\n");
        return;
    }

    int data = q->queue[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }

    printf("Antrian dengan nomor %d selesai dilayani.\n", data);
}

void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Antrian kosong.\n");
        return;
    }

    printf("Daftar Antrian: ");

    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queue[i]);
    }

    printf("\n");
}

void bubbleSort(Queue *q) {
    int i, j;
    int n = q->rear - q->front + 1;

    for (i = q->front; i <= q->rear; i++) {
        for (j = q->front; j <= q->rear - i - 1; j++) {
            if (q->queue[j] > q->queue[j + 1]) {
                int temp = q->queue[j];
                q->queue[j] = q->queue[j + 1];
                q->queue[j + 1] = temp;
            }
        }
    }

    printf("Antrian berhasil diurutkan.\n");
}

int linearSearch(Queue *q, int key) {
    if (isQueueEmpty(q)) {
        printf("Antrian kosong.\n");
        return -1;
    }

    for (int i = q->front; i <= q->rear; i++) {
        if (q->queue[i] == key) {
            return i;
        }
    }

    return -1;
}

int main() {
    Queue q;
    initQueue(&q);

    int choice, data;

    do {
        printf("\nProgram Antrian Bank\n");
        printf("1. Tambah Antrian\n");
        printf("2. Panggil Antrian Selanjutnya\n");
        printf("3. Tampilkan Antrian\n");
        printf("4. Urutkan Antrian\n");
        printf("5. Cari Antrian\n");
        printf("6. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Masukkan nomor antrian: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                bubbleSort(&q);
                break;
            case 5:
                printf("Masukkan nomor antrian yang ingin dicari: ");
                scanf("%d", &data);
                int index = linearSearch(&q, data);
                if (index != -1) {
                    printf("Antrian dengan nomor %d ditemukan pada indeks %d.\n", data, index);
                } else {
                    printf("Antrian dengan nomor %d tidak ditemukan.\n", data);
                }
                break;
            case 6:
                printf("Terima kasih. Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid. Ulangi.\n");
        }
    } while (choice != 6);

    return 0;
}
