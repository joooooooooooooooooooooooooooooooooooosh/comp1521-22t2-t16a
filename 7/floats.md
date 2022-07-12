# 0 00000000 00000000000000000000000

sign = 0 (+ve)
exponent = 0 (adjusted -127)
fraction = 1.000
float = 1 * 2^-127 ~= 0


# 1 00000000 00000000000000000000000 

sign = 1 (-ve)
exponent = 0 (adjusted -127)
fraction = 1.000
float = -1 * 2^-127 ~= -0

# 0 01111111 10000000000000000000000

sign = 0 (+ve)
exponent = 255 (adjusted 128)
fraction = 0b1.100000000 = 1.5
float = 1.5 * 2^128 = 5.104e+38

# 0 01111110 00000000000000000000000
sign = 0 (+ve)
exponent = 254 (adjusted 127)
fraction = 1.000
float = 1 * 2^127 = 1.7e+38


# 2.5
sign = 0 (+ve)
exponent = 1 (adjusted 128) = 1000 0000
fraction = 1.0100 = 0100000000000
float = 1.01 * 2^1 = 2.5
0 10000000 01000000000000000000000
