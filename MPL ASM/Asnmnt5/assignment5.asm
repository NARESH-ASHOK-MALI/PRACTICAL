section .data
    name db 'User is Naresh Ashok Mali SCOD16', 0xA    ; User name followed by newline
    name_len equ $ - name    ; Length of the name string
	msg1 db "Count of Positive numbers: ", 0
	len1 equ $-msg1
	msg2 db "Count of Negative numbers: ", 0
	len2 equ $-msg2
	prompt db "Enter 7 numbers (separated by spaces): ", 0
	len_prompt equ $-prompt
	array db 0, 0, 0, 0, 0, 0, 0  ; Array to store user input

section .bss
	count resb 2
	pcount resb 2
	ncount resb 2
	totalcount resb 2
	input resb 50  ; Buffer to store user input

section .text
	global _start

; Macro to print a message
%macro print 2
	mov rax, 1      	; syscall: write
	mov rdi, 1      	; file descriptor: stdout
	mov rsi, %1     	; message to print
	mov rdx, %2     	; message length
	syscall
%endmacro

_start:
    ; Print user name
    mov eax, 4          ; System call number for write (sys_write)
    mov ebx, 1          ; File descriptor 1 (stdout)
    mov ecx, name       ; Pointer to the name string
    mov edx, name_len   ; Length of the name string
    int 0x80            ; Call the kernel
	; Print the prompt message
	print prompt, len_prompt

	; Read input from the user
	mov rax, 0      	; syscall: read
	mov rdi, 0      	; file descriptor: stdin
	mov rsi, input  	; buffer to store input
	mov rdx, 50     	; number of bytes to read
	syscall

	; Parse the input and store in the array
	mov rsi, input  	; Point to the input buffer
	mov rdi, array  	; Point to the array
	mov byte [count], 7 ; Number of elements to read

parse_input:
	xor rax, rax    	; Clear RAX
	xor rbx, rbx    	; Clear RBX

next_char:
	lodsb           	; Load next byte from input buffer
	cmp al, ' '     	; Check if it's a space
	je store_number 	; If space, store the number
	cmp al, 0x0A    	; Check if it's a newline (end of input)
	je store_number 	; If newline, store the number
	sub al, '0'     	; Convert ASCII to integer
	imul rbx, 10    	; Multiply current number by 10
	add rbx, rax    	; Add the new digit
	jmp next_char   	; Continue to next character

store_number:
	mov [rdi], bl   	; Store the number in the array
	inc rdi         	; Move to the next position in the array
	dec byte [count]	; Decrement the count
	jnz parse_input 	; If count is not zero, continue parsing

	; Initialize counters
	mov byte [count], 7
	mov byte [pcount], 0
	mov byte [ncount], 0

	; Point to the array
	mov rsi, array

Up:
	mov al, [rsi]   	; Load the current number
	test al, al     	; Check if the number is negative
	js neg          	; If negative, jump to neg
	inc byte [pcount]   ; Increment positive count
	jmp Down        	; Jump to Down

neg:
	inc byte [ncount]   ; Increment negative count

Down:
	inc rsi         	; Move to the next number in the array
	dec byte [count]	; Decrement the count
	jnz Up          	; If count is not zero, continue

	; Print the count of positive numbers
	print msg1, len1
	mov bh, [pcount]
	call disp

	; Print the count of negative numbers
	print msg2, len2
	mov bh, [ncount]
	call disp

	; Exit the program
	mov rax, 60     	; syscall: exit
	mov rdi, 0      	; exit code 0
	syscall

disp:
	mov byte [count], 2 ; Number of digits to display

loop:
	rol bh, 4       	; Rotate left by 4 bits
	mov al, bh      	; Move the rotated value to AL
	and al, 0x0F    	; Mask the lower 4 bits
	cmp al, 9       	; Compare with 9
	jbe l1          	; If below or equal, jump to l1
	add al, 7       	; Adjust for ASCII (A-F)

l1:
	add al, '0'     	; Convert to ASCII
	mov [totalcount], al ; Store the ASCII character
	print totalcount, 1 ; Print the character
	dec byte [count]	; Decrement the count
	jnz loop        	; If count is not zero, continue
	Ret
