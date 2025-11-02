#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_CARDS 50
#define MAX_QUESTION 200
#define MAX_ANSWER 500

typedef struct {
    char question[MAX_QUESTION];
    char answer[MAX_ANSWER];
    int difficulty; // 1-5 scale
    int times_reviewed;
    int correct_count;
} Flashcard;

Flashcard deck[MAX_CARDS];
int card_count = 0;
int current_card = 0;

// Function prototypes
void initialize_deck();
void display_card(int index);
void quiz_mode();
void study_mode();
void add_custom_card();
void view_statistics();
void save_progress();
void load_progress();
int get_user_choice();
void clear_input_buffer();

int main() {
    srand(time(NULL));
    
    printf("=== Number Theory Flashcards ===\n");
    printf("Divisibility and Primes\n\n");
    
    load_progress();
    if (card_count == 0) {
        initialize_deck();
    }
    
    int choice;
    do {
        printf("\nMain Menu:\n");
        printf("1. Quiz Mode\n");
        printf("2. Study Mode\n");
        printf("3. Add Custom Card\n");
        printf("4. View Statistics\n");
        printf("5. Save and Exit\n");
        printf("Choice: ");
        
        choice = get_user_choice();
        
        switch(choice) {
            case 1:
                quiz_mode();
                break;
            case 2:
                study_mode();
                break;
            case 3:
                add_custom_card();
                break;
            case 4:
                view_statistics();
                break;
            case 5:
                save_progress();
                printf("Progress saved. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

void initialize_deck() {
    // Divisibility rules
    strcpy(deck[0].question, "Divisibility rule for 2");
    strcpy(deck[0].answer, "A number is divisible by 2 if its last digit is even (0, 2, 4, 6, 8).");
    deck[0].difficulty = 1;
    
    strcpy(deck[1].question, "Divisibility rule for 3");
    strcpy(deck[1].answer, "A number is divisible by 3 if the sum of its digits is divisible by 3.");
    deck[1].difficulty = 2;
    
    strcpy(deck[2].question, "Divisibility rule for 4");
    strcpy(deck[2].answer, "A number is divisible by 4 if its last two digits form a number divisible by 4.");
    deck[2].difficulty = 2;
    
    strcpy(deck[3].question, "Divisibility rule for 5");
    strcpy(deck[3].answer, "A number is divisible by 5 if its last digit is 0 or 5.");
    deck[3].difficulty = 1;
    
    strcpy(deck[4].question, "Divisibility rule for 6");
    strcpy(deck[4].answer, "A number is divisible by 6 if it is divisible by both 2 and 3.");
    deck[4].difficulty = 2;
    
    strcpy(deck[5].question, "Divisibility rule for 8");
    strcpy(deck[5].answer, "A number is divisible by 8 if its last three digits form a number divisible by 8.");
    deck[5].difficulty = 3;
    
    strcpy(deck[6].question, "Divisibility rule for 9");
    strcpy(deck[6].answer, "A number is divisible by 9 if the sum of its digits is divisible by 9.");
    deck[6].difficulty = 2;
    
    strcpy(deck[7].question, "Divisibility rule for 11");
    strcpy(deck[7].answer, "A number is divisible by 11 if the alternating sum of its digits is divisible by 11.");
    deck[7].difficulty = 4;
    
    // Prime number concepts
    strcpy(deck[8].question, "Definition of prime number");
    strcpy(deck[8].answer, "A natural number greater than 1 that has no positive divisors other than 1 and itself.");
    deck[8].difficulty = 1;
    
    strcpy(deck[9].question, "Definition of composite number");
    strcpy(deck[9].answer, "A natural number greater than 1 that is not prime (has divisors other than 1 and itself).");
    deck[9].difficulty = 1;
    
    strcpy(deck[10].question, "Fundamental Theorem of Arithmetic");
    strcpy(deck[10].answer, "Every integer greater than 1 can be represented uniquely as a product of prime numbers, up to the order of factors.");
    deck[10].difficulty = 3;
    
    strcpy(deck[11].question, "Sieve of Eratosthenes");
    strcpy(deck[11].answer, "Algorithm to find all primes up to N: List numbers, mark multiples of each prime starting from 2.");
    deck[11].difficulty = 3;
    
    strcpy(deck[12].question, "Prime factorization formula");
    strcpy(deck[12].answer, "Any integer n > 1 can be written as: n = p1^a1 * p2^a2 * ... * pk^ak where pi are primes and ai are positive integers.");
    deck[12].difficulty = 3;
    
    strcpy(deck[13].question, "Euclid's Lemma");
    strcpy(deck[13].answer, "If a prime p divides ab, then p divides a or p divides b (or both).");
    deck[13].difficulty = 4;
    
    strcpy(deck[14].question, "GCD using prime factorization");
    strcpy(deck[14].answer, "gcd(a,b) = product of primes raised to the minimum of their exponents in a and b's prime factorizations.");
    deck[14].difficulty = 3;
    
    strcpy(deck[15].question, "LCM using prime factorization");
    strcpy(deck[15].answer, "lcm(a,b) = product of primes raised to the maximum of their exponents in a and b's prime factorizations.");
    deck[15].difficulty = 3;
    
    strcpy(deck[16].question, "Relationship between GCD and LCM");
    strcpy(deck[16].answer, "For any two positive integers a and b: gcd(a,b) * lcm(a,b) = a * b");
    deck[16].difficulty = 3;
    
    strcpy(deck[17].question, "Euler's Totient Function φ(n)");
    strcpy(deck[17].answer, "Count of numbers ≤ n that are coprime to n. For prime p: φ(p) = p-1. For n = p^k: φ(n) = p^k - p^(k-1)");
    deck[17].difficulty = 5;
    
    strcpy(deck[18].question, "Wilson's Theorem");
    strcpy(deck[18].answer, "A natural number p > 1 is prime if and only if (p-1)! ≡ -1 (mod p)");
    deck[18].difficulty = 5;
    
    strcpy(deck[19].question, "Fermat's Little Theorem");
    strcpy(deck[19].answer, "If p is prime and a is not divisible by p, then a^(p-1) ≡ 1 (mod p)");
    deck[19].difficulty = 4;
    
    strcpy(deck[20].question, "Number of divisors formula");
    strcpy(deck[20].answer, "If n = p1^a1 * p2^a2 * ... * pk^ak, then number of divisors = (a1+1)(a2+1)...(ak+1)");
    deck[20].difficulty = 3;
    
    strcpy(deck[21].question, "Sum of divisors formula");
    strcpy(deck[21].answer, "If n = p1^a1 * p2^a2 * ... * pk^ak, then sum of divisors = ∏(pi^(ai+1)-1)/(pi-1)");
    deck[21].difficulty = 4;
    
    strcpy(deck[22].question, "Mersenne Prime");
    strcpy(deck[22].answer, "Prime of the form 2^p - 1 where p is prime.");
    deck[22].difficulty = 4;
    
    strcpy(deck[23].question, "Twin Primes");
    strcpy(deck[23].answer, "Prime pairs that differ by 2 (e.g., 3 and 5, 11 and 13).");
    deck[23].difficulty = 2;
    
    card_count = 24;
    
    // Initialize statistics
    for (int i = 0; i < card_count; i++) {
        deck[i].times_reviewed = 0;
        deck[i].correct_count = 0;
    }
}

void display_card(int index) {
    printf("\n=== Card %d/%d ===\n", index + 1, card_count);
    printf("Question: %s\n", deck[index].question);
    printf("\nPress Enter to see answer...");
    getchar();
    printf("Answer: %s\n", deck[index].answer);
    printf("Difficulty: %d/5\n", deck[index].difficulty);
}

void quiz_mode() {
    printf("\n=== Quiz Mode ===\n");
    printf("Answer correctly or press Enter to see answer.\n\n");
    
    int score = 0;
    int total_quizzed = 0;
    int *quiz_order = malloc(card_count * sizeof(int));
    
    // Create random order
    for (int i = 0; i < card_count; i++) {
        quiz_order[i] = i;
    }
    
    // Fisher-Yates shuffle
    for (int i = card_count - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = quiz_order[i];
        quiz_order[i] = quiz_order[j];
        quiz_order[j] = temp;
    }
    
    for (int i = 0; i < card_count; i++) {
        int card_index = quiz_order[i];
        
        printf("\nQuestion %d/%d: %s\n", i + 1, card_count, deck[card_index].question);
        printf("Your answer (or press Enter to skip): ");
        
        char user_answer[MAX_ANSWER];
        getchar(); // Clear newline
        fgets(user_answer, MAX_ANSWER, stdin);
        
        // Remove newline
        user_answer[strcspn(user_answer, "\n")] = 0;
        
        if (strlen(user_answer) == 0) {
            printf("Answer: %s\n", deck[card_index].answer);
        } else {
            printf("Correct answer: %s\n", deck[card_index].answer);
            printf("Did you get it right? (y/n): ");
            char response = getchar();
            getchar(); // Clear newline
            
            if (tolower(response) == 'y') {
                score++;
                deck[card_index].correct_count++;
            }
        }
        
        deck[card_index].times_reviewed++;
        total_quizzed++;
        
        printf("Continue quiz? (y/n): ");
        char cont = getchar();
        getchar(); // Clear newline
        if (tolower(cont) != 'y') {
            break;
        }
    }
    
    free(quiz_order);
    
    printf("\nQuiz completed! Score: %d/%d (%.1f%%)\n", 
           score, total_quizzed, total_quizzed > 0 ? (score * 100.0 / total_quizzed) : 0);
}

void study_mode() {
    printf("\n=== Study Mode ===\n");
    printf("Study cards in order. Press Enter to continue.\n\n");
    
    for (int i = 0; i < card_count; i++) {
        display_card(i);
        deck[i].times_reviewed++;
        
        if (i < card_count - 1) {
            printf("Next card? (y/n): ");
            char response = getchar();
            getchar(); // Clear newline
            if (tolower(response) != 'y') {
                break;
            }
        }
    }
}

void add_custom_card() {
    if (card_count >= MAX_CARDS) {
        printf("Deck is full! Cannot add more cards.\n");
        return;
    }
    
    printf("\n=== Add Custom Card ===\n");
    
    printf("Enter question: ");
    getchar(); // Clear newline
    fgets(deck[card_count].question, MAX_QUESTION, stdin);
    deck[card_count].question[strcspn(deck[card_count].question, "\n")] = 0;
    
    printf("Enter answer: ");
    fgets(deck[card_count].answer, MAX_ANSWER, stdin);
    deck[card_count].answer[strcspn(deck[card_count].answer, "\n")] = 0;
    
    printf("Enter difficulty (1-5): ");
    scanf("%d", &deck[card_count].difficulty);
    
    deck[card_count].times_reviewed = 0;
    deck[card_count].correct_count = 0;
    
    card_count++;
    printf("Card added successfully!\n");
}

void view_statistics() {
    printf("\n=== Statistics ===\n");
    
    int total_reviews = 0;
    int total_correct = 0;
    
    for (int i = 0; i < card_count; i++) {
        total_reviews += deck[i].times_reviewed;
        total_correct += deck[i].correct_count;
    }
    
    printf("Total cards: %d\n", card_count);
    printf("Total reviews: %d\n", total_reviews);
    printf("Overall accuracy: %.1f%%\n", 
           total_reviews > 0 ? (total_correct * 100.0 / total_reviews) : 0);
    
    printf("\nCards by difficulty:\n");
    int difficulty_count[6] = {0}; // 0-5
    for (int i = 0; i < card_count; i++) {
        difficulty_count[deck[i].difficulty]++;
    }
    
    for (int i = 1; i <= 5; i++) {
        printf("Difficulty %d: %d cards\n", i, difficulty_count[i]);
    }
}

void save_progress() {
    FILE *file = fopen("flashcards.dat", "wb");
    if (file == NULL) {
        printf("Error saving progress!\n");
        return;
    }
    
    fwrite(&card_count, sizeof(int), 1, file);
    fwrite(deck, sizeof(Flashcard), card_count, file);
    fclose(file);
}

void load_progress() {
    FILE *file = fopen("flashcards.dat", "rb");
    if (file == NULL) {
        return; // No saved progress
    }
    
    fread(&card_count, sizeof(int), 1, file);
    fread(deck, sizeof(Flashcard), card_count, file);
    fclose(file);
}

int get_user_choice() {
    int choice;
    if (scanf("%d", &choice) != 1) {
        clear_input_buffer();
        return -1;
    }
    return choice;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}