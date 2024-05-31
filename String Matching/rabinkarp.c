#include <stdio.h>
#include <string.h>
#include <limits.h>

void RabinKarpMatcher(char txt[], char pat[], int d, int q)
{
    int n = strlen(txt);
    int m = strlen(pat);
    int t = 0;
    int p = 0;
    int h = 1;
    int i, j;
    for (i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    for (i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= n - m; i++)
    {

        if (p == t)
        {

            for (j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }

            if (j == m)
                printf("Pattern found at index %d \n", i);
        }

        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            // if (t < 0)
            //     t = (t + q);
        }
    }
}

void NaiveStringMatcher(char txt[], char pat[])
{
    int n = strlen(txt);
    int m = strlen(pat);
    int i,j;
    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (txt[i + j] != pat[j])
            {
                
                break;
            }
        }
        if(j==m)
        {
            printf("Pattern found at index %d \n", i);
        }
    }
}

    int main()
    {
        char txt[] = "Helelele Hello Hello Bolo";
        char pat[] = "lele";

        int q = INT_MAX;

        int d = 53;

        RabinKarpMatcher(txt, pat, d, q);
        NaiveStringMatcher(txt, pat);
        return 0;
    }
