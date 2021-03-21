

int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new)
{

    if (source == NULL && n_new == 0)
        return NULL;
    else if (source == NULL && n_new != 0)
    {
        int *a = new int[n_new];
        return a;
    }


    else if (source != NULL && n_new == 0)
    {
        delete [] source;
        return NULL;
    }

    else
    {
        int N;
        if (n_old < n_new)
            N = n_old;
        else
            N = n_new;

        int* a = new int[n_new];
        for (int i=0; i < N; i++)
        {
            *(a+i) = *(source+i);
        }
        delete [] source;
        return a;
    }
}
