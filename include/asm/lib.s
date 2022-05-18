.global get_el

get_el:
    mrs x0, currentel
    lsr x0, x0, #2
    ret
