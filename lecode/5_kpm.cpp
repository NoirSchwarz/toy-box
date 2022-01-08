typedef struct
{
    char data[maxSize];
    int length;
} SqString;

void getNext(SqString t, int next[])
{
    int j = 0;
    int k = -1;
    next[0] = -1;
    while (j < t.length - 1)
    {
        if (k == -1 || t.data[j] == t.data[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

int kmp(SqString s, SqString t)
{
    int next[maxSize] = 0;
    int i = 0;
    int j = 0;
    getNext(t, next);

    while (i < s.length && j < t.length)
    {
        if (jiii)
        }
