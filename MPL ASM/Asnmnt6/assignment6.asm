section .data
    name db 'User is Naresh Ashok Mali SCOD16', 0xA 
    name_len equ $ - name

    menu_msg db "1. HEX to BCD", 0xA, "2. BCD to HEX", 0xA, "3. Exit", 0xA
    menu_len equ $ - menu_msg

    prompt_choice db "Enter your choice: ", 0
    choice_len equ $ - prompt_choice

    prompt_hex db "Enter HEX number (max 4 digits): ", 0
    hex_len equ $ - prompt_hex

    prompt_bcd db "Enter BCD number (max 5 digits): ", 0
    bcd_len equ $ - prompt_bcd

    result_hex db "Equivalent HEX number: ", 0
    result_hex_len equ $ - result_hex

    result_bcd db "Equivalent BCD number: ", 0
    result_bcd_len equ $ - result_bcd

    newline db 0xA
    newline_len equ $ - newline

section .bss
    choice resb 2    
    num resb 6      
    result resb 10   
    ans resb 5       
    temp resb 2      

section .text
global _start

_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, name
    mov rdx, name_len
    syscall

menu:
    mov rax, 1
    mov rdi, 1
    mov rsi, menu_msg
    mov rdx, menu_len
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, prompt_choice
    mov rdx, choice_len
    syscall

    mov rax, 0
    mov rdi, 0
    mov rsi, choice
    mov rdx, 2
    syscall

    mov al, [choice]
    cmp al, 0xA
    je menu

    cmp byte [choice], '1'
    je case1
    cmp byte [choice], '2'
    je case2
    cmp byte [choice], '3'
    je case3

    jmp menu

case3:
    mov rax, 60    
    mov rdi, 0
    syscall

case1:
    mov rax, 1
    mov rdi, 1
    mov rsi, prompt_hex
    mov rdx, hex_len
    syscall

    mov rax, 0
    mov rdi, 0
    mov rsi, num
    mov rdx, 5     
    syscall

    call hex_to_bcd
    jmp menu

case2:
    mov rax, 1
    mov rdi, 1
    mov rsi, prompt_bcd
    mov rdx, bcd_len
    syscall

    mov rax, 0
    mov rdi, 0
    mov rsi, num
    mov rdx, 6
    syscall

    call bcd_to_hex
    jmp menu

hex_to_bcd:
    call hex_to_int
    mov rbx, 10
    xor rcx, rcx   

    mov rdi, result
    mov byte [rdi], 0
    add rdi, 4  

back:
    xor rdx, rdx
    div rbx
    add dl, '0'
    mov [rdi], dl
    dec rdi
    inc rcx
    cmp rax, 0h
    jne back

    mov rax, 1
    mov rdi, 1
    mov rsi, result_bcd
    mov rdx, result_bcd_len
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, result
    mov rdx, 5
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, newline_len
    syscall

    ret

hex_to_int:
    xor rax, rax
    mov rsi, num
parse_hex:
    movzx rcx, byte [rsi]
    cmp rcx, 0
    je done_parse
    cmp rcx, 0xA
    je done_parse
    shl rax, 4 
    cmp rcx, '9'
    jbe is_digit
    sub rcx, 'A' - 10
    jmp store_value
is_digit:
    sub rcx, '0'
store_value:
    or rax, rcx
    inc rsi
    jmp parse_hex
done_parse:
    ret

bcd_to_hex:
    xor rax, rax
    mov rbx, 10
    mov rcx, 5
    mov rsi, num
up2: 
    xor rdx, rdx
    mul rbx
    xor rdx, rdx
    mov dl, [rsi]
    sub dl, '0'
    add rax, rdx
    inc rsi
    dec rcx
    jnz up2

    mov [result], ax

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
    add dl, '0'
    mov [rsi], dl
    dec rsi
    dec rcx
    jnz count

    mov rax, 1
    mov rdi, 1
    mov rsi, ans
    mov rdx, 4
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, newline_len
    syscall

    ret