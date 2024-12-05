#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    const char* face;
    const char* suit;
} Card;

void fillDeck(Card* wDeck, const char* wFace[], const char* wSuit[]);
void shuffle(Card* wDeck);
void deal(const Card* wDeck);

int main() {
    srand((unsigned)time(NULL));


    const char* face[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six",
                          "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };


    Card deck[52];


    fillDeck(deck, face, suit);
    shuffle(deck);
    deal(deck);

    return 0;

}
void fillDeck(Card* wDeck, const char* wFace[], const char* wSuit[]) {
    if (!wDeck || !wFace || !wSuit) { // ���{����chatgpt���ڭק諸�����A�ت����ˬd�O�_�� NULL ����
        printf("Error: Null pointer detected in fillDeck.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 52; i++) { // ��R�C�i�d�P���I�ƩM���
        wDeck[i].face = wFace[i % 13];
        wDeck[i].suit = wSuit[i / 13];
    }
}


void shuffle(Card* wDeck) {
    if (!wDeck) { //�o�]�Ochatgpt���ڭק諸���� �ˬd�O�_�� NULL ����
        printf("Error: Null pointer detected in shuffle.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 52 ; i++) { 
        int j = rand() % 51;
        Card temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
}


void deal(const Card* wDeck) {
    if (!wDeck) { //�o�]�Ochatgpt���ڭק諸���� �ˬd�O�_�� NULL ����
        printf("Error: Null pointer detected in deal.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 52; i++) { 
        if (!wDeck[i].face || !wDeck[i].suit) { 
            printf("Error: Null pointer in card %d.\n", i);
            exit(EXIT_FAILURE);
        }
        printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit,
            (i + 1) % 4 == 0 ? "\n" : "\t");
    }
}
