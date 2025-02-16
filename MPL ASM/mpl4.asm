; Problem Statement: Write a switch case driven x86/64 ALP to perform 64 bit hexadecimal arithmetic operations (+, /, -, *)
; using suitable macros. Define procedure for each operation.
;---------------------------------------------------------------------------------------------------------------

%macro scall 4
        mov rax, %1
        mov rdi, %2
        mov rsi, %3
        mov rdx, %4
        syscall
%endmacro

;-------------------------.data section------------------------------
section .data
        name db 'User is Naresh Ashok Mali SCOD16', 0xA    ; User name followed by newline
        name_len equ $ - name    ; Length of the name string
        menu db 10d,13d,"--------MENU--------"
             db 10d,13d,"1. Addition"
             db 10d,13d,"2. Subtraction"
             db 10d,13d,"3. Multiplication"
             db 10d,13d,"4. Division"
             db 10d,13d,"5. Exit"
             db 10d,13d,"Enter your Choice: "
        menu_len equ $-menu

        prompt1 db 10d,13d,"Enter first 64-bit hexadecimal number: "
        prompt1_len equ $-prompt1

        prompt2 db 10d,13d,"Enter second 64-bit hexadecimal number: "
        prompt2_len equ $-prompt2

        m1 db 10d,13d,"Addition: "
        l1 equ $-m1
        m2 db 10d,13d,"Subtraction: "
        l2 equ $-m2
        m3 db 10d,13d,"Multiplication: "
        l3 equ $-m3
        m4 db 10d,13d,"Division: "
        l4 equ $-m4

;-------------------------.bss section------------------------------	
section .bss
        num1 resq 1
        num2 resq 1
        answer resb 16
        choice resb 2
        input resb 17

;------------------------.text section -----------------------------
section .text
        global _start
        _start:
            ; Print user name
    mov eax, 4          ; System call number for write (sys_write)
    mov ebx, 1          ; File descriptor 1 (stdout)
    mov ecx, name       ; Pointer to the name string
    mov edx, name_len   ; Length of the name string
    int 0x80            ; Call the kernel
        ; Prompt for first number
        scall 1, 1, prompt1, prompt1_len
        scall 0, 0, input, 17
        call ascii_to_hex
        mov [num1], rax

        ; Prompt for second number
        scall 1, 1, prompt2, prompt2_len
        scall 0, 0, input, 17
        call ascii_to_hex
        mov [num2], rax

        ; Display menu and get choice
up:     scall 1, 1, menu, menu_len
        scall 0, 0, choice, 2

        ; Perform operation based on choice
        cmp byte [choice], '1'
        je case1
        cmp byte [choice], '2'
        je case2
        cmp byte [choice], '3'
        je case3
        cmp byte [choice], '4'
        je case4
        cmp byte [choice], '5'
        je case5

        ; Invalid choice, prompt again
        jmp up

case1:  scall 1, 1, m1, l1
        call addition
        jmp up

case2:  scall 1, 1, m2, l2
        call subtraction
        jmp up

case3:  scall 1, 1, m3, l3
        call multiplication
        jmp up

case4:  scall 1, 1, m4, l4
        call division
        jmp up

case5:  mov rax, 60
        mov rdi, 0
        syscall

; Procedures for arithmetic operations
addition:
        mov rax, [num1]
        add rax, [num2]
        call display
        ret

subtraction:
        mov rax, [num1]
        sub rax, [num2]
        call display
        ret

multiplication:
        mov rax, [num1]
        imul rax, [num2]
        call display
        ret

division:
        mov rax, [num1]
        mov rdx, 0
        idiv qword [num2]
        call display
        ret

; Procedure to convert ASCII to hex
ascii_to_hex:
        mov rcx, 16
        mov rsi, input
        xor rax, rax
convert_loop:
        rol rax, 4
        mov bl, [rsi]
        cmp bl, '9'
        jbe sub30
        sub bl, 7
sub30:  sub bl, '0'
        add al, bl
        inc rsi
        loop convert_loop
        ret

; Procedure to display the result in hexadecimal
display:
        mov rsi, answer + 15
        mov rcx, 16
        mov rbx, 16
cnt:    mov rdx, 0
        div rbx
        cmp dl, 9
        jbe add30
        add dl, 7
add30:  add dl, '0'
        mov [rsi], dl
        dec rsi
        dec rcx
        jnz cnt
        scall 1, 1, answer, 16
        ret

