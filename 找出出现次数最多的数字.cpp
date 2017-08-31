void search(int a[], int len)
{
    int sp[1000] = {0};
    int i = 0;
    int max = 0;
    
    for(i=0; i<len; i++)
    {
        int index = a[i] - 1;
        
        sp[index]++;
    }
    
    for(i=0; i<1000; i++)
    {
        if( max < sp[i] )
        {
            max = sp[i];
        }
    }
    
    for(i=0; i<1000; i++)
    {
        if( max == sp[i] )
        {
            printf("%d\n", i+1);
        }
    }
}
