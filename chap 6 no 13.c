#include <stdio.h>
#include <ctype.h>

typedef enum {
    start,
    build_id,
    build_num,
    identifier,
    number,
    stop
} State;

State transition(State current_state, char transition_char) {
    switch (current_state) {
        case start:
            if (isspace(transition_char)) {
                return start;  
            } else if (isdigit(transition_char)) {
                return build_num;  
            } else if (isalpha(transition_char) || transition_char == '_') {
                return build_id;  
            }
            break;

        case build_id:
            if (isalpha(transition_char) || isdigit(transition_char) || transition_char == '_') {
                return build_id;  
            } else {
                return identifier;  
            }

        case build_num:
            if (isdigit(transition_char)) {
                return build_num;  
            } else if (transition_char == '.') {
                return build_num;  
            } else if (transition_char == '-' || transition_char == '+') {
                return build_num;  
            } else {
                return number;  
            }

        case identifier:
            if (isspace(transition_char)) {
                return start; 
            } else {
                return stop;  
            }

        case number:
            if (isspace(transition_char)) {
                return start; 
            } else {
                return stop;  
            }

        default:
            return stop;  
    }
    return stop;  
}

int main() {
    State current_state = start;
    char transition_char;

    printf("Enter a line of data: ");
    
    do {
        scanf("%c", &transition_char);
        
        if (isspace(transition_char)) {
            continue;  
        }

        
        printf("%c", transition_char);  

        
        current_state = transition(current_state, transition_char);

        // Check state for output
        if (current_state == identifier) {
            printf(" - Identifier\n");
            current_state = start;  
        } else if (current_state == number) {
            printf(" - Number\n");
            current_state = start;  
        }

    } while (current_state != stop);

    return 0;
}
