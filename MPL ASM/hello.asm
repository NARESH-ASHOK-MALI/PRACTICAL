section .data
    name db 'User is Naresh Ashok Mali SCOD16', 0xA    ; User name followed by newline
    name_len equ $ - name    ; Length of the name string
    message db 'Hello, World!', 0xA  ; Message with newline
    msg_len equ $ - message  ; Length of the message

section .text
    global _start

_start:
    ; Print user name
    mov eax, 4          ; System call number for write (sys_write)
    mov ebx, 1          ; File descriptor 1 (stdout)
    mov ecx, name       ; Pointer to the name string
    mov edx, name_len   ; Length of the name string
    int 0x80            ; Call the kernel

    ; Print "Hello, World!"
    mov eax, 4          ; System call number for write (sys_write)
    mov ebx, 1          ; File descriptor 1 (stdout)
    mov ecx, message    ; Pointer to the message string
    mov edx, msg_len    ; Length of the message string
    int 0x80            ; Call the kernel

    ; Exit the program
    mov eax, 1          ; System call number for exit (sys_exit)
    xor ebx, ebx        ; Return code 0
    int 0x80            ; Call the kernel
