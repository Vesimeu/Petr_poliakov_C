.ORIG x3000
    ; Проверка условия x > 0
    LD R1, x
    LD R2, #0
    NOT R2, R2
    ADD R2, R2, #1
    ADD R1, R1, R2
    BRn ELSE
    ; Тело if
    ; ...
    BR ENDIF
ELSE
    ; Тело else
    ; ...
ENDIF
    ; Проверка условия y > 0
WHILE
    LD R1, y
    LD R2, #0
    NOT R2, R2
    ADD R2, R2, #1
    ADD R1, R1, R2
    BRn ENDWHILE
    ; Тело while
    ; ...
    BR WHILE
ENDWHILE
.END
