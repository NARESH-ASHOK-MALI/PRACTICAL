section .data
    name_msg        db "USER IS NARESH ASHOK MALI SCOD 16", 10
    name_len        equ $ - name_msg

    welcome_msg     db "Welcome to Overlapped Block Transfer!", 10
    welcome_len     equ $ - welcome_msg

    before_msg      db "Block contents BEFORE transfer:", 10
    before_len      equ $ - before_msg

    src_msg         db "Source Block: "
    src_len         equ $ - src_msg

    dest_msg        db "Destination Block: "
    dest_len        equ $ - dest_msg

    after_msg       db 10, "Block contents AFTER transfer:", 10
    after_len       equ $ - after_msg

    thanks_msg      db 10, "Thank you!", 10
    thanks_len      equ $ - thanks_msg

    newline         db 10

    src_block       db "ABCDEFGH"
    dest_block      db "12345678"

section .text
    global _start

_start:
    ; Step 2: Display welcome and name
    mov rax, 1
    mov rdi, 1
    mov rsi, welcome_msg
    mov rdx, welcome_len
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, name_msg
    mov rdx, name_len
    syscall

    ; Step 3: BEFORE transfer
    mov rax, 1
    mov rdi, 1
    mov rsi, before_msg
    mov rdx, before_len
    syscall

    ; Step 4 & 5: Show source block
    mov rax, 1
    mov rdi, 1
    mov rsi, src_msg
    mov rdx, src_len
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, src_block
    mov rdx, 8
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall

    ; Step 6 & 7: Show dest block
    mov rax, 1
    mov rdi, 1
    mov rsi, dest_msg
    mov rdx, dest_len
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, dest_block
    mov rdx, 8
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall

    ; Step 8-11: Perform overlapped transfer from src_block to dest_block
    ; Copy last 4 bytes from src_block to dest_block (in reverse)

    std                     ; Step 10: Set direction flag (auto-decrement)
    mov rcx, 4              ; Step 9: 4 bytes to transfer

    lea rsi, [rel src_block + 7]  ; Last byte of source
    lea rdi, [rel dest_block + 7] ; Last byte of destination

    rep movsb               ; Step 11: Repeat byte move RCX times

    cld                     ; Always clear DF after use

    ; Step 12: AFTER transfer
    mov rax, 1
    mov rdi, 1
    mov rsi, after_msg
    mov rdx, after_len
    syscall

    ; Step 13 & 14: Print source
    mov rax, 1
    mov rdi, 1
    mov rsi, src_msg
    mov rdx, src_len
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, src_block
    mov rdx, 8
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall

    ; Step 15 & 16: Print dest
    mov rax, 1
    mov rdi, 1
    mov rsi, dest_msg
    mov rdx, dest_len
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, dest_block
    mov rdx, 8
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall

    ; Step 17: Thank you
    mov rax, 1
    mov rdi, 1
    mov rsi, thanks_msg
    mov rdx, thanks_len
    syscall

    ; Step 18: Exit
    mov rax, 60
    xor rdi, rdi
    syscall
