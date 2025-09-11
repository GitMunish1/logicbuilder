#include <stdio.h>
#include <string.h>

enum Rooms {
    LIVING_ROOM,
    KITCHEN,
    BEDROOM
};

int main() {
    char* room_descriptions[] = {
        "You are in a cozy living room. There is a kitchen to the north.",
        "You are in a clean kitchen. There is a living room to the south and a bedroom to the east.",
        "You are in a messy bedroom. There is a kitchen to the west."
    };

    int current_room = LIVING_ROOM;
    char input[50];

    printf("Welcome to a simple text adventure!\n");
    printf("Type 'go [direction]', 'look' or 'quit'.\n\n");

    while (1) {
        printf("\n%s\n", room_descriptions[current_room]);
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        } else if (strcmp(input, "look") == 0) {
            continue;
        } 
        
        // This is where we add the movement logic
        else if (strcmp(input, "go north") == 0) {
            // Only allow this move from the LIVING_ROOM
            if (current_room == LIVING_ROOM) {
                current_room = KITCHEN;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "go south") == 0) {
            // Only allow this move from the KITCHEN
            if (current_room == KITCHEN) {
                current_room = LIVING_ROOM;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "go east") == 0) {
            // Only allow this move from the KITCHEN
            if (current_room == KITCHEN) {
                current_room = BEDROOM;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "go west") == 0) {
            // Only allow this move from the BEDROOM
            if (current_room == BEDROOM) {
                current_room = KITCHEN;
            } else {
                printf("You can't go that way.\n");
            }
        } else {
            printf("I don't understand that command.\n");
        }
    }

    return 0;
}