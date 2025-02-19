section .data
    name db 'User is Naresh Ashok Mali SCOD16', 0xA
    name_len equ $ - name

    menu_msg db "1. HEX to BCD", 0xA, "2. BCD to HEX", 0xA, "3. Exit", 0xA
    menu_len equ $ - menu_msg

    prompt_choice db "Enter your choice: ", 0
    choice_len equ $ - prompt_choice

    prompt_hex db "Enter HEX number: ", 0
    hex_len equ $ - prompt_hex

    prompt_bcd db "Enter BCD number: ", 0
    bcd_len equ $ - prompt_bcd

    result_hex db "Equivalent HEX number: ", 0
    result_hex_len equ $ - result_hex

    result_bcd db "Equivalent BCD number: ", 0
    result_bcd_len equ $ - result_bcd

    newline db 0xA
    newline_len equ $ - newline

section .bss
    choice resb 4    ; Increased buffer size for safety
    num resb 10      ; Buffer for input number
    result resb 10   ; Buffer for result storage
    digitcount resb 1
    ans resb 10

section .text
global _start

_start:
    ; Display user name
    mov rax, 1
    mov rdi, 1
    mov rsi, name
    mov rdx, name_len
    syscall

menu:
    ; Print menu
    mov rax, 1
    mov rdi, 1
    mov rsi, menu_msg
    mov rdx, menu_len
    syscall

    ; Ask for user choice
    mov rax, 1
    mov rdi, 1
    mov rsi, prompt_choice
    mov rdx, choice_len
    syscall

    ; Read choice
    mov rax, 0
    mov rdi, 0
    mov rsi, choice
    mov rdx, 4      ; Allow space for newline
    syscall

    ; Process choice
    cmp byte [choice], '1'
    je case1
    cmp byte [choice], '2'
    je case2
    cmp byte [choice], '3'
    je case3

case3:
    mov rax, 60    ; Exit system call
    mov rdi, 0
    syscall

case1:
    ; Prompt for HEX number
    mov rax, 1
    mov rdi, 1
    mov rsi, prompt_hex
    mov rdx, hex_len
    syscall

    ; Read HEX input
    mov rax, 0
    mov rdi, 0
    mov rsi, num
    mov rdx, 6     ; Increased buffer size
    syscall

    call hex_to_bcd

    jmp menu

case2:
    ; Prompt for BCD number
    mov rax, 1
    mov rdi, 1
    mov rsi, prompt_bcd
    mov rdx, bcd_len
    syscall

    ; Read BCD input
    mov rax, 0
    mov rdi, 0
    mov rsi, num
    mov rdx, 6
    syscall

    call bcd_to_hex

    jmp menu

hex_to_bcd:
    mov ax, bx
    mov rbx, 10
back:
    xor rdx, rdx
    div rbx
    push dx
    inc byte[digitcount]
    cmp rax, 0h
    jne back

print:
    pop dx
    add dl, 30h   
    mov [result], dl
    mov rax, 1
    mov rdi, 1
    mov rsi, result
    mov rdx, 1
    syscall
    dec byte[digitcount]
    jnz print
    ret

bcd_to_hex:
    xor rax, rax
    mov rbx, 10
    mov rcx, 05
up2: 
    xor rdx, rdx
    mul ebx
    xor rdx, rdx
    mov dl, [rsi]
    sub dl, 30H
    add rax, rdx
    inc rsi
    dec rcx
    jnz up2

    mov [result], ax

    ; Print Equivalent HEX Number
    mov rax, 1
    mov rdi, 1
    mov rsi, result_hex
    mov rdx, result_hex_len
    syscall

    mov ax, [result]
    call display

    ret

display: 
    mov rsi, ans+3
    mov rcx, 4

count:
    mov rdx, 0
    mov rbx, 16
    div rbx
    cmp dl, 09H
    jbe skip2
    add dl, 07H

skip2:
    add dl, 30H
    mov [rsi], dl
    dec rsi
    dec rcx
    jnz count

    mov rax, 1
    mov rdi, 1
    mov rsi, ans
    mov rdx, 4
    syscall
    ret
