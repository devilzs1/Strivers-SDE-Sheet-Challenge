string kthPermutation(int n, int k)
{
    // Write your code here.
    vector<long> fact(10, 1);
    for (int i = 2; i < 10; i++)
        fact[i] = fact[i - 1] * i;
    int size = n, val = fact[n];
    --k;
    string permut = "", temp = "";
    for (int i = 1; i <= n; i++)
        temp += ('0' + i);
    while (size)
    {
        val /= size;
        int ind = k / val;
        k %= val;
        permut += temp[ind];
        temp.erase(ind, 1);
        size--;
    }
    return permut;
}
