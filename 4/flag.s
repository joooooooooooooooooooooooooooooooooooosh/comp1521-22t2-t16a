.data
flag:
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

        .text
main:
        # row in t0
        li      $t0, 0
main_for_start_1:
        bge     $t0, 6, main_for_end_1
        # col in t1
        li      $t1, 0
main_for_start_2:
        bge     $t1, 12, main_for_end_2

        # &flag[t0][t1]
        # &flag[t0] = &flag + t0 * sizeof(row)
        # &flag[t0] = &flag + t0 * 12 * sizeof(char)
        # &flag[t0][t1] = (&flag + t0 * 12) + t1 * sizeof(char)

        la      $t2, flag
        mul     $t3, $t0, 12
        add     $t3, $t2, $t3
        mul     $t4, $t1, 1
        add     $t4, $t3, $t4

        li      $v0, 11
        lb      $a0, ($t4)
        syscall

        addi    $t1, $t1, 1
        b main_for_start_2
main_for_end_2:
        li      $v0, 11
        li      $a0, '\n'
        syscall

        addi    $t0, $t0, 1
        b       main_for_start_1
main_for_end_1:

        jr      $ra
