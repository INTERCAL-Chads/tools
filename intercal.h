typedef unsigned int spot;
typedef unsigned long twospot;
// may only work on 64-bit architecture

spot spot_or(spot s)
{
    spot res = 0;
    spot cpy = s >> 1;
    spot cpy2 = s;
    for(int i = 0; i < 16; i++)
    {
        res |= (1 & (cpy2 | cpy)) << i;
        cpy >>= 1;
        cpy2 >>= 1;
    }
    return res | (((s & 1) | ((s & (1 << 15)) >> 15)) << 15);
}

spot spot_and(spot s)
{
    spot res = 0;
    spot cpy = s >> 1;
    spot cpy2 = s;
    for(int i = 0; i < 16; i++)
    {
        res |= (1 & (cpy2 & cpy)) << i;
        cpy >>= 1;
        cpy2 >>= 1;
    }
    return res | (((s & 1) & ((s & (1 << 15)) >> 15)) << 15);
}

spot spot_xor(spot s)
{
    spot res = 0;
    spot cpy = s >> 1;
    spot cpy2 = s;
    for(int i = 0; i < 16; i++)
    {
        res |= (1 & (cpy2 ^ cpy)) << i;
        cpy >>= 1;
        cpy2 >>= 1;
    }
    return res | (((s & 1) ^ ((s & (1 << 15)) >> 15)) << 15);
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