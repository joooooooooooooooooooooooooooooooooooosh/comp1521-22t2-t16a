.text
main:
        # v0 = 4
        # a0 = my_prompt

        li      $v0, 4
        la      $a0, my_prompt
        syscall

        # x is in $t0
        li      $v0, 5
        syscall
        move    $t0, $v0

        # y is in $t1
        mul     $t1, $t0, $t0

        li      $v0, 1
        move    $a0, $t1
        syscall

        li      $v0, 11
        li      $a0, '\n'
        # li      $a0, 10
        syscall

        jr      $ra

.data
my_prompt:
        .asciiz "Enter a number: "
