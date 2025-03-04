section .data
    m1 db "NAME: Naresh Ashok Mali SCOD16", 10    ; Name with newline
    l1 equ $ - m1
    array db 15h, 5h, 63h, 52h, 94h

    msg1 db 10, "ALP to find the largest number in an array", 10
    msg1_len equ $ - msg1
   
    msg2 db 10, "The Array contains the elements : ", 10
    msg2_len equ $ - msg2
   
    msg3 db 10,10,'The Largest number in the array is '
    msg3_len equ $ - msg3

section .bss
    counter resb 1
    result resb 4
   
%macro write 2
    mov rax, 1             ; Syscall: write
    mov rdi, 1             ; File descriptor: STDOUT
    mov rsi, %1            ; Message pointer
    mov rdx, %2            ; Message length
    syscall
%endmacro

section .text
    global _start
   
_start:
        write m1, l1          ; Write the name to STDOUT
        write msg1, msg1_len  ; Write the introductory message
        write msg2, msg2_len  ; Write the array message
       
        mov byte [counter], 5 ; Initialize counter for array size
        mov rsi, array        ; Base address of the array

next:  
        mov al, [rsi]         ; Load array element
        push rsi              ; Save RSI
        call disp             ; Display element
        pop rsi               ; Restore RSI
        inc rsi               ; Move to next array element
        dec byte [counter]    ; Decrement counter
        jnz next              ; Repeat until all elements are displayed
       
        write msg3, msg3_len  ; Write the message for the largest number

        mov byte [counter], 5 ; Reset counter for finding the largest
        mov rsi, array        ; Reset base address of the array
        mov al, 0             ; Initialize the largest number as 0
       
repeat:
        cmp al, [rsi]         ; Compare current largest with array element
        jg skip               ; Skip if current largest is greater
        mov al, [rsi]         ; Update the largest number
skip:  
        inc rsi               ; Move to the next array element
        dec byte [counter]    ; Decrement counter
        jnz repeat            ; Repeat until all elements are checked

        call disp             ; Display the largest number

        mov rax, 60           ; Exit syscall
        xor rdi, rdi          ; Return code 0
        syscall

disp:
        mov bl, al            ; Value to display
        mov rdi, result       ; Buffer to hold ASCII characters
        mov cx, 2             ; Number of nibbles to process
       
up1:
        rol bl, 4             ; Rotate to extract higher nibble
        mov al, bl            ; Copy value to AL
        and al, 0x0F          ; Mask to isolate nibble
        cmp al, 9             ; Check if it's greater than 9
        jg hex_convert        ; If so, convert to hex letter
        add al, '0'           ; Convert to ASCII digit
        jmp store_digit
hex_convert:
        add al, 'A' - 10      ; Convert to ASCII hex letter
store_digit:
        mov [rdi], al         ; Store ASCII character in buffer
        inc rdi               ; Increment buffer pointer
        dec cx                ; Decrement nibble count
        jnz up1               ; Repeat for the next nibble

        write result, 2       ; Write the 2-character result
        mov al, ' '           ; Add a space after each element
        mov [result], al
        write result, 1       ; Write the space

        ret
