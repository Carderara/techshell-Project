// Names: Landon Carderara and Nico Relle
// Description:
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Functional Prototype
void display(void);
void input(char *buf, size_t size);

int main(void){
    char cmd[1024];
    
    while(1){
        display();
        input(cmd, sizeof(cmd));
        if (strcmp(cmd, "exit") == 0){
            break;
        }
    }


    return 0;
}

// function to display the current path
void display(){
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL){
        printf("%s$ ", cwd);
    }
    else{
        perror("cwd error");
    }

    
}

// function to get the input from the user
void input(char *buf, size_t size) {
    if (fgets(buf, size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0';
}



