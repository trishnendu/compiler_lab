MOV a, R0
DIV c, R0
MOV f, R1
MULT 10, R1
MOV R0, R2
ADD 1, R2
MOV R2, R0
SUB c, R0
MOV R0, R1
ADD res, R1
jnz tag5
MOV res, R0
SUB 1, R0
jmp tag6
tag5:
MOV res, R2
ADD 1, R2
tag6:
tag11:
COMP condjz tag10
MOV h, R3
MULT res, R3
MOV R3, R4
ADD c, R4
= res
COMP condjmp tag11
tag10:
end
