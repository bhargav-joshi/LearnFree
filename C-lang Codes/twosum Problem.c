/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char * s, char * p, int* returnSize)
{
    int ls = strlen(s);
    int lp = strlen(p);
    int *result;
    int count = 0;
    if (ls < lp)
    {
        result = malloc(1);
        (* returnSize) = 0;
        return result;
    }
    result = malloc(sizeof(int)*(ls-lp+1));
    int pc[26];
    int sc[26];
    memset(pc,0,sizeof(int)*26);
    memset(sc,0,sizeof(int)*26);
    
    int i,k;
    for (i=0; i<(lp-1); i++)
    {
        pc[p[i]-'a']++;
        sc[s[i]-'a']++;
    }
    pc[p[i]-'a']++;
    for (i=0,k=lp-1; i<(ls-lp+1); i++,k++)
    {
        sc[s[k]-'a']++;
        int j;
        for (j=0; j<26; j++)
            if (sc[j] != pc[j])
                break;
        
        if (j==26)
        {
            result[count++] = i;
        }
        sc[s[i]-'a']--;
    }
    (* returnSize) = count;
    return(result);
}
