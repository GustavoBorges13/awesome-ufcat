#include "shell.h"
#include "kb.h"
#include "system.h"
#include "idt.h"
#include "isr.h"
#include "string.h"
#include "screen.h"

int kmain() {
    isr_install();
    clearScreen();

    print("\n------->Basic");
    print("\n	Operating");
    print("\n	System<------- ");

    print("Bem vindo ao B.OS ------->\n\n\n\nEntre um comando\n");
    launch_shell(0);
}

