
#include "../include/gdt.h"
#include "../include/console.h"
#include "../include/debug.h"

int kernel_entry(){
    
    init_debug();
    init_gdt();
    
    console_clear();
    printk_color(background_color_black, foreground_color_green, "Hello HeOS kernel!\n");
    panic("test");
    
    return 0;
}