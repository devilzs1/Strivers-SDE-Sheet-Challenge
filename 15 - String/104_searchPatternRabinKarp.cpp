
vector<int> stringMatch(string text, string pattern)
{
    // Write your code here.
    const int mod = 1e9 + 7;
    const int p = 53;
    vector<int> match;
    int patLen = pattern.length(), textLen = text.length();
    vector<long long> textHash(textLen + 1, 0);
    vector<long long> power(max(patLen, textLen), 0);

    power[0] = 1;
    for (int i = 1; i < max(patLen, textLen); i++)
        power[i] = (power[i - 1] * p) % mod;

    for (int i = 0; i < textLen; i++)
    {
        textHash[i + 1] = (textHash[i] + (text[i] - 'a' + 1) * power[i]) % mod;
    }
    long long patHash = 0;
    for (int i = 0; i < patLen; i++)
    {
        patHash = (patHash + (pattern[i] - 'a' + 1) * power[i]) % mod;
    }

    for (int i = 0; i + patLen - 1 < textLen; i++)
    {
        long long curr = (textHash[i + patLen] - textHash[i] + mod) % mod;
        if (curr == (patHash * power[i]) % mod)
        {
            match.push_back(i + 1);
        }
    }
    return match;
}
