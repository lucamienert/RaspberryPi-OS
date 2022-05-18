.global out_word
.global in_word

out_word:
    str w1, [x0]
    ret

in_word:
    ldr w0, [x0]
    ret
