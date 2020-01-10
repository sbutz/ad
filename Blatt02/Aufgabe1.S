# n liegt in 1
INP 1

# 2n + 1
LDK 2
MUL 1
STA 2
LDK 1
ADD 2
STA 2

# n + 1
LDK 1
ADD 1

# (2n + 1) * (n + 1) * n
MUL 2
MUL 1
STA 2

# erg / 6
LDK 6
STA 3
LDA 2
DIV 3
STA 2

OUT 2

HTL 99
