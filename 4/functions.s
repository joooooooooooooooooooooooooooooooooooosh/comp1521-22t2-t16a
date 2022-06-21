    .text
main: # ra is kernel
main_prologue:
        begin
        push    $ra

main_body:
        li      $a0, 11
        li      $a1, 13
        li      $a2, 17
        li      $a3, 19
        
        jal     sum4
        # ra = next instruction
        # j sum4
        move    $a0, $v0  #ra here
        li      $v0, 1
        syscall

main_epilogue:

        pop     $ra
        end
        jr      $ra

sum4:
sum4_prologue:
        begin
        push    $ra
        push    $s0
        push    $s1
        push    $s2

sum4_body:
        move    $s1, $a2
        move    $s2, $a3
        
        jal     sum2
        move    $s0, $v0
        
        move    $a0, $s1
        move    $a1, $s2
        jal     sum2
        move    $t1, $v0
        
        add     $v0, $s0, $t1
        
sum4_epilogue:
        pop     $s2
        pop     $s1
        pop     $s0
        pop     $ra
        end
        jr      $ra
        
sum2:
        add     $v0, $a0, $a1
        jr      $ra
        
