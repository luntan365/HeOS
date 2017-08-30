typedef struct strMultiBootHeader{
    unsigned long magic;
    unsigned long flags;
    unsigned long checksum;
} MultiBootHeader;

void mbprint(char* str);
unsigned long magic;

MultiBootHeader mbh __attribute__((section(".text"))) = {
    .magic = 0X1BADB002,
    .flags = 0X00000003,
    .checksum = -(0X1BADB002+0X00000003),
};

void KernelEntry(void){
    __asm__ __volatile__("movl %%eax,%0":"=m"(magic));
    
    if(magic != 0X1BADB002){
        mbprint("Kernel load error!\n");
        while(1);
        return;
    }

    mbprint("Hello world!\n");
    while(1);

    return ;
}

void mbprint(char* str){
    char *pvideo = (char*)0xB8000;
    while(*str != '\n'){
        *pvideo++ = *str++;
        *pvideo++ = 0x04;
    }
    return;
}
