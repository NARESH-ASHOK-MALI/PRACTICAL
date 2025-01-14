section .data
        msg1 db 10,13,&quot;Enter 5 64 bit numbers&quot;
        len1 equ $-msg1
        msg2 db 10,13,&quot;Entered 5 64 bit numbers&quot;
        len2 equ $-msg2
section .bss ; statically allocated variables that are declared but have
        not been assigned a value yet.
        array resd 200 ; 200 byte memory
        counter resb 1 ; 1 byte memory
section .text
        global _start
        _start:
;display
        mov Rax,1 ; write mode
        mov Rdi,1 ; wrie mode
        mov Rsi,msg1
        mov Rdx,len1
        syscall ; invoke operating system to exit
;accept
mov byte[counter],05
mov rbx,00
            loop1:
                mov rax,0 ; 0 for read
                mov rdi,0 ; 0 for keyboard
                mov rsi, array ;move pointer to start of array add
                rsi,rbx
                mov rdx,17
                syscall ; invoke operating system to exit
        add rbx,17 ;to move counter dec byte[counter]
                JNZ loop1

;display
        mov Rax,1 ;1 for write
        mov Rdi,1 ;1 for write
        mov Rsi,msg2
        mov Rdx,len2
        syscall ; invoke operating system to exit
;display
mov byte[counter],05
mov rbx,00
            loop2:
                mov rax,1 ;1 for write
                mov rdi, 1 ;1 for monitor
                mov rsi, array
                add rsi,rbx
                                mov rdx,17 ;16 bit +1 for enter

                syscall
                add rbx,17
                dec byte[counter]
                JNZ loop2
            ;exit system call
            mov rax ,60
            mov rdi,0
            syscall