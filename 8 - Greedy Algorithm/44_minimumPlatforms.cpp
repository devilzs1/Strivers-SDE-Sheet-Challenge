int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    int minPlat = 0, currPlat = 0;
    int lastdt = *max_element(dt, dt + n);
    vector<int> platform(lastdt + 2);
    for (int i = 0; i < n; i++)
    {
        platform[at[i]]++;
        platform[dt[i] + 1]--;
    }
    for (int i = 0; i <= lastdt + 1; i++)
    {
        currPlat += platform[i];
        minPlat = max(minPlat, currPlat);
    }

    return minPlat;
}