

int main()
{

    int n=5,r=2;

    int res = 1;

    for(int i=0;i<r;i++)
    {

        res*=(n-i);
        res/=(i+1);

    }

}