typedef unsigned int spot;
typedef unsigned long twospot;

typedef spot* tail;
typedef twospot* hybrid;
// may only work on 64-bit architecture

tail tail_new(spot n){
    tail t = malloc(sizeof(spot) * n);
    memset(t, 0, sizeof(spot) * n);
    return t;
}

spot ror (spot x) {
  return (x >> 1) | (x << 15);
}

spot spot_or(spot s)
{
    return s | ror(s);
}

spot spot_and(spot s)
{
    return s & ror(s);
}

spot spot_xor(spot s)
{
    return s ^ ror(s);
}

spot spot_select(spot base, spot mask)
{
    spot res = 0;
    spot bcpy = base;
    spot mcpy = mask;
    unsigned short masks = 0;
    for (int i = 0; i < 16; i++)
    {
        unsigned short t = mcpy & 1;
        if (t)
        {
            res |= (bcpy & 1) << (i - masks);
        }
        else
        {
            masks++;
        }

        bcpy >>= 1;
        mcpy >>= 1;
    }
    return res;
}

twospot mingle(spot s1, spot s2)
{
    twospot res = 0;

    spot cpy1 = s1;
    spot cpy2 = s2;

    for (int i = 0; i < 16; i++)
    {
        res |= (cpy1 & 1) << (i * 2);
        res |= (cpy2 & 1) << (i * 2 + 1);

        cpy1 >>= 1;
        cpy2 >>= 1;
    }

    return res;
}