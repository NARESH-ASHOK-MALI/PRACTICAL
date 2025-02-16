%macro print 2
    mov rax, 1            ; syscall: write
    mov rdi, 1            ; file descriptor: stdout
    mov rsi, %1           ; message address
    mov rdx, %2           ; message length
    syscall
%endmacro

section .data
    prompt_name db 'Enter your name: ', 0
    prompt_name_len equ $-prompt_name

    welmsg db 10, 'Welcome to count +ve and -ve numbers in an array', 10
    welmsg_len equ $-welmsg

    pmsg db 10, 'Count of +ve numbers: '
    pmsg_len equ $-pmsg

    nmsg db 10, 'Count of -ve numbers: '
    nmsg_len equ $-nmsg

    prompt_elements db 'Enter number of elements (1-255): ', 0
    prompt_elements_len equ $-prompt_elements

    prompt_number db 'Enter number (signed, in decimal): ', 0
    prompt_number_len equ $-prompt_number

    newline db 10, 0

section .bss
    name_buffer resb 32    ; Reserve 32 bytes for user name
    dispbuff resb 2        ; Reserve 2 bytes for display buffer
    pcnt resb 1            ; Positive count storage
    ncnt resb 1            ; Negative count storage
    element_count resb 1   ; To store number of elements entered by user
    user_array resw 256    ; Reserve space for up to 256 elements

section .text
    global _start

_start:
    ; Prompt user for name
    print prompt_name, prompt_name_len

    ; Read user's name
    mov rax, 0
    mov rdi, 0
    mov rsi, name_buffer
    mov rdx, 32
    syscall

    ; Remove newline from the input
    mov rdi, name_buffer
strip_newline:
    cmp byte [rdi], 0Ah        ; Check for newline character
    je remove_newline
    inc rdi
    loop strip_newline

remove_newline:
    mov byte [rdi], 0          ; Replace newline with null terminator

    ; Print welcome message
    print welmsg, welmsg_len

    ; Prompt for number of elements
    print prompt_elements, prompt_elements_len
    mov rax, 0
    mov rdi, 0
    mov rsi, element_count
    mov rdx, 1
    syscall

    ; Convert ASCII to binary (assuming single-digit input)
    sub byte [element_count], 48

    ; Initialize counters
    xor byte [pcnt], 0
    xor byte [ncnt], 0

    ; Loop to read and store array elements
    mov cl, [element_count]   ; Load number of elements into CL
    mov rsi, user_array       ; Point RSI to user_array

read_elements:
    print prompt_number, prompt_number_len
    mov rax, 0
    mov rdi, 0
    mov rsi, name_buffer      ; Use name buffer temporarily for input
    mov rdx, 10               ; Read up to 10 characters (decimal input)
    syscall

    ; Convert ASCII decimal input to binary (basic implementation)
    mov rdi, name_buffer      ; Pointer to input buffer
    xor eax, eax              ; Clear EAX for result
    xor ebx, ebx              ; Clear EBX for sign

parse_digit:
    mov bl, byte [rdi]
    cmp bl, 0Ah               ; Check for newline
    je done_parsing
    cmp bl, 45                ; Check for '-' (negative sign)
    jne valid_digit
    mov ebx, 1                ; Set sign flag
    inc rdi
    jmp parse_digit

valid_digit:
    sub bl, 48                ; Convert ASCII to binary
    imul eax, eax, 10         ; Multiply result by 10
    add eax, ebx              ; Add current digit
    inc rdi
    jmp parse_digit

done_parsing:
    test ebx, ebx             ; Check if the number is negative
    jz store_number
    neg eax                   ; Make it negative

store_number:
    mov [rsi], ax             ; Store the input in user_array
    add rsi, 2                ; Move to the next element
    dec cl                    ; Decrement element counter
    jnz read_elements         ; Continue reading elements

    ; Print positive count
    print pmsg, pmsg_len
    mov bl, [pcnt]
    call disp8num

    ; Print negative count
    print nmsg, nmsg_len
    mov bl, [ncnt]
    call disp8num

    ; Print new line
    print newline, 1

exit:
    ; Exit the program
    mov rax, 60
    mov rdi, 0
    syscall

disp8num:
    mov rcx, 2
    mov rdi, dispbuff

dup1:
    rol bl, 4
    mov al, bl
    and al, 0Fh
    cmp al, 09
    jbe dskip
    add al, 07h

dskip:
    add al, 30h
    mov [rdi], al
    inc rdi
    loop dup1

    print dispbuff, 2
    ret
