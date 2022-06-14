main:
        # i is in t0
        li      $t0, 0
main_while_1:
        bge     $t0, 5, main_while_end_1

        # scanf
        li      $v0, 5
        syscall
        move    $t1, $v0

        # calculate address of numbers[i]
        la      $t2, numbers
        mul     $t3, $t0, 4
        add     $t4, $t2, $t3

        sw      $t1, ($t4) # store value of t1 at the address stored in $t4
        # int a;
        # int *b = &a;
        # *b = 3; // store 3 at the address stored in b

        # i++
        addi    $t0, $t0, 1
        b       main_while_1

main_while_end_1:

        li      $t0, 0
main_while_2:
        bge     $t0, 5, main_while_end_2

        # printf
        mul     $t1, $t0, 4
        lw      $a0, numbers($t1) # &numbers + value of t1

        li      $v0, 1
        syscall

        # \n
        li      $v0, 11
        li      $a0, '\n'
        syscall

        # i++
        addi    $t0, $t0, 1
        b main_while_2

main_while_end_2:

        # return 0
        li      $v0, 0
        jr      $ra

        .data
numbers:
        .word 0,0,0,0,0,0,0,0,0,0
        # .space 4 * 10
