/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    int res=~(~x & ~y) & ~(x & y);
    return res;
}


/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    int x1 = (x >> 31)&1;
    int y1 = (y >> 31)&1;
    if ((!x&&!y)){
        return 1;
    }
    else{
        if (x&&y){
        if (x1&y1){
            return 1;
        }
        else{
            if (!x1&!y1){
                return 1;
            }
        }
    }
    }
    return 0;

    
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int r = 0;
    int t;

    t = (v > 65535) << 4; 
    r = r|t;
    v = v >> t;
    t = (v > 255) << 3;
    r = r|t;
    v = v >> t;
    t = (v > 15) << 2;
    r = r|t;
    v = v >> t;
    t = (v > 3) << 1;
    r = r|t;
    v = v >> t;
    t = (v > 1); 
    r = r|t;

    return r;
}



/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int n8 = n << 3;
    int m8 = m << 3;
    int x1=x>>n8&0xFF;
    int x2=x>>m8&0xFF;
    int res1=x1<<m8;
    int res2=x2<<n8;
    x=x&~(0xFF<<n8);
    x=x&~(0xFF<<m8);
    x = x|res1;
    x = x|res2;
    return x;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    unsigned res=0;
    for (unsigned n =32;n;n--){
        res=res<<1 | (v&1);
        v>>=1;
    }
    return res;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int r1=x>>n;
    int r2=~(((1<<31)>>n)<<1);
    return r1&r2;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int count=0;
    int flag;
    flag=!(~(x>>16));
    count=count+(flag<<4);
    x=x<<(flag<<4);
    flag=!(~(x>>24));
    count=count+(flag<<3);
    x=x<<(flag<<3);
    flag=!(~(x>>28));
    count=count+(flag<<2);
    x=x<<(flag<<2);
    flag=!(~(x>>30));
    count=count+(flag<<1);
    x=x<<(flag<<1);
    flag=!(~(x>>31));
    count=count+flag;
    x=x<<flag;
    count=count+((x>>31)&1);
    return count;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned sign,abs_x,e,frac,pos;
    int shift;
    if(x==0){
        return 0;
    }
    sign=(x>>31);
    if (sign){
        abs_x=-x;
    }
    else{
        abs_x=x;
    }
    pos=0;
    unsigned temp=abs_x;
    while(temp>1){
        temp=temp>>1;
        pos++;
    }
    e=pos+127;
    if(pos<=23){
        frac=(abs_x<<(23-pos))&0x7FFFFF;
    }
    else{
        shift=pos-23;
        frac=(abs_x>>shift)&0x7FFFFF;
        unsigned mask=(1<<shift)-1;
        unsigned half=1<<(shift-1);
        unsigned dropped=abs_x&mask;
        if(dropped>half){
            frac++;
            }
        else{
            if(dropped==half){
                if(frac&1){
                    frac++;
                }
            }
        }
            if(frac==0x800000){
                e++;
                frac=0;
            }
        

    }
    return (sign<<31)|(e<<23)|frac;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned s=uf>>31;
    unsigned e=(uf>>23)&0xFF;
    unsigned f=uf&0x7FFFFF;
    if(e==0xFF){
        return uf;
    }
    if(e==0){
        f=f<<1;
        if(f&0x800000){
            e=1;
            f=f&0x7FFFFF;
        }
    }
    else{
        e++;
        if(e==0xFF){
            f=0;
        }
    }
    return (s<<31)|(e<<23)|f;
}
/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned sign = uf2 >> 31;
    unsigned exp = (uf2 >> 20) & 0x7FF;
    unsigned frac_high = uf2 & 0xFFFFF;
    unsigned frac_low = uf1;
    if(!exp){
        if(!frac_high){
            if(!frac_low){
                return 0;
            }
        }
        return 0;
    }
    if(exp>=0x7FF){
        return 0x80000000;
    }
    int E = exp - 1023;
    if(E < 0){
        return 0;
    }
    if(E > 31){
        return 0x80000000;
    }
    if(E>30){
        if(frac_high){
            return 0x80000000;
        }
        if(frac_low){
            return 0x80000000;
        }
        if(!sign){
            return 0x80000000;
        }
    }
    unsigned abs_val;
    if(E > 20){
        abs_val = (frac_high | 0x100000) << (E - 20);
    }
    else{
        abs_val = (frac_high | 0x100000) >> (20 - E);
    }
    if(sign){
        return -abs_val;
    }
    else{
        if(abs_val > 0x7FFFFFFF){
            return 0x80000000;
        }
    }
    return abs_val;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    if(x>=128){
        return 0x7F800000;
    }
    if(x<=-150){
        return 0;
    }
    if(x>=-126){
        return (x+127)<<23;
    }
    else{
        return 1<<(x+149);
    }
}
